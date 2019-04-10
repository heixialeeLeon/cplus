#include "opencv2/opencv.hpp"
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("../test_img/shape.jpg");
    cv::imshow("raw", img);

    cv::Mat gray;
    cv::cvtColor(img, gray, CV_BGR2GRAY);
    cv::Canny(gray, gray, 100, 200,3);
    cv::imshow("gray", gray);

    std::vector<std::vector<cv::Point>> contours;
    //std::vector<cv::Vec4i> hierarchy;
    cv::RNG rng(12345);

    cv::findContours(gray, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
    // draw the contours
    cv::Mat drawing = cv::Mat::zeros(gray.size(), CV_8UC3);
    for(int i=0; i< contours.size(); i++)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
        cv::drawContours(drawing, contours, i, color, 2, 8);
    }

    cv::Mat drawingRect = drawing.clone();
    for(int i = 0; i< contours.size(); i++)
    {
        cv::Scalar color(255,255,0);
        cv::Rect re = cv::boundingRect(contours[i]);
        cv::rectangle(drawingRect, re, color, 2, 8);

    }
    cv::imshow("Result", drawing);
    cv::imshow("ResultRect",drawingRect);
    cv::waitKey(0);
    return 0;
}

//int main()
//{
//    cv::Mat img = cv::imread("../test_img/shape.jpg");
//    cv::imshow("raw", img);
//
//    cv::Mat gray;
//    cv::cvtColor(img, gray, CV_BGR2GRAY);
//    cv::Canny(gray, gray, 100, 200,3);
//    cv::imshow("gray", gray);
//
//    std::vector<std::vector<cv::Point>> contours;
//    std::vector<cv::Vec4i> hierarchy;
//    cv::RNG rng(12345);
//
//    cv::findContours(gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0,0));
//    // draw the contours
//    cv::Mat drawing = cv::Mat::zeros(gray.size(), CV_8UC3);
//    for(int i=0; i< contours.size(); i++)
//    {
//        cv::Scalar color = cv::Scalar(rng.uniform(0,255), rng.uniform(0,255), rng.uniform(0,255));
//        cv::drawContours(drawing, contours, i, color, 2, 8, hierarchy,0, cv::Point());
//    }
//    cv::imshow("Result", drawing);
//    cv::waitKey(0);
//    return 0;
//}
