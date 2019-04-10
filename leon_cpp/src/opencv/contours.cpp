#include "opencv2/opencv.hpp"
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("../test_img/0.jpg");
    cv::cvtColor(img, img, CV_RGB2GRAY);
    cv::Mat img_blur;

    cv::blur(img,img_blur,cv::Size(3,3));
    cv::Mat dst = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierachy;

    cv::findContours(img_blur, contours, hierachy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
    int index = 0;
    for(; index >=0; index=hierachy[index][0])
    {
        cv::Scalar color(255,0,0);
        cv::drawContours(dst, contours, index, color, cv::FILLED,8, hierachy);
        //index++;
    }
    cv::imshow("raw", img);
    cv::imshow("blur",img_blur);
    cv::imshow("contours", dst);
    cv::waitKey(-1);
}


