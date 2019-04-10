#include "opencv2/opencv.hpp"

int main()
{
    cv::Mat img = cv::imread("../test_img/1.jpg");
    cv::resize(img, img, cv::Size(img.cols/5,img.rows/5));

    cv::Point center(img.cols/2, img.rows/2);
    cv::Mat rot_mat = cv::getRotationMatrix2D(center, -180, 1.0);
    cv::Mat rotated_img;
    cv::warpAffine(img, rotated_img, rot_mat, img.size(), cv::INTER_LINEAR);

    cv::imshow("raw",img);
    cv::imshow("roate", rotated_img);
    cv::waitKey(-1);
}

