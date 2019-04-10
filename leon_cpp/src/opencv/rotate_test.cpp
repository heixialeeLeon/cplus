#include "opencv2/opencv.hpp"

#define PI 3.1415926

float angle_to_radian(float degree, float min, float second)
{
    float flag = (degree < 0)? -1.0 : 1.0;			//判断正负
    if(degree<0)
    {
        degree = degree * (-1.0);
    }
    float angle = degree + min/60 + second/3600;
    float result =flag * (angle * PI)/180;
    return result;
}

bool rotateImg(const cv::Mat& src, float angle, cv::Mat& dst){

    int width = src.cols;
    int height = src.rows;
    int heightNew = width * abs(sin(angle_to_radian(angle,0,0))) +
                    height * abs(cos(angle_to_radian(angle,0,0)));
    int widthNew = height * abs(sin(angle_to_radian(angle,0,0))) +
                   width * abs(cos(angle_to_radian(angle,0,0)));

    cv:: Mat rot = cv::getRotationMatrix2D(cv::Point2f((float)width/2,(float)height/2),
                                           angle,1);
    rot.at<double>(0, 2) += (widthNew - width)/2;
    rot.at<double>(1, 2) += (heightNew - height)/2;
    cv::warpAffine(src,dst,rot,cv::Size(widthNew,heightNew));
    return true;
}

void rotateImg2(const cv::Mat& src, float angle, cv::Mat& dst)
{
    cv::Point center = cv::Point(src.cols/2, src.rows/2);
    double scale = 1;
    cv::Mat rotMat = cv::getRotationMatrix2D(center,angle,scale);
    cv::warpAffine(src, dst,rotMat, src.size());
}

int main()
{
    cv::Mat img = cv::imread("../test_img/3.jpg");
    cv::Mat rotated_img;
    cv::Mat rotated_img2;
    rotateImg(img, 90, rotated_img);
    rotateImg2(img,90, rotated_img2);

    cv::imshow("raw",img);
    cv::imshow("roate", rotated_img);
    cv::imshow("roate2", rotated_img2);
    cv::waitKey(-1);
}