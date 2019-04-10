#include "opencv2/opencv.hpp"
#include <iostream>

int current_value=3;
const int max_value = 20;

cv::Mat img;
cv::Mat boxFilter_show, blur_show, gaussian_show, median_show, bilateral_show;

void on_TrackerBar_boxFilter(int value, void* data)
{
    //std::cout<<"current value: "<<value<<std::endl;
    if(value >0) {
        cv::Mat out;
        cv::boxFilter(img, boxFilter_show,-1, cv::Size(value,value));
        cv::imshow("boxFilter", boxFilter_show);
    }
}

void on_TrackerBar_blur(int value, void* data)
{
    //std::cout<<"current value: "<<value<<std::endl;
    if(value >0) {
        cv::Mat out;
        cv::blur(img, blur_show, cv::Size(value,value));
        cv::imshow("blur", blur_show);
    }
}

void on_TrackerBar_GaussianBlur(int value, void* data)
{
    //std::cout<<"current value: "<<value<<std::endl;
    if(value % 2 != 0) {
        cv::Mat out;
        cv::GaussianBlur(img, gaussian_show, cv::Size(value,value),0,0);
        cv::imshow("gaussianBlur", gaussian_show);
    }
}

void on_TrackerBar_MedianBlur(int value, void* data)
{
    //std::cout<<"current value: "<<value<<std::endl;
    if(value % 2 != 0) {
        cv::Mat out;
        cv::medianBlur(img, median_show, value);
        cv::imshow("medianBlur", median_show);
    }
}

void on_TrackerBar_BilateralFilter(int value, void* data)
{
    //std::cout<<"current value: "<<value<<std::endl;
    if(value) {
        cv::Mat out;
        cv::bilateralFilter(img, bilateral_show, 25, 25*2, 25/2);
        cv::imshow("bilateralFilter", bilateral_show);
    }
}

int main()
{
    img = cv::imread("../test_img/4.png");
    cv::resize(img, img, cv::Size(img.cols/2,img.rows/2));
    cv::namedWindow("boxFilter");
    cv::namedWindow("blur");
    cv::namedWindow("gaussianBlur");
    cv::namedWindow("medianBlur");
    cv::namedWindow("bilateralFilter");
    cv::createTrackbar("value","boxFilter",&current_value, max_value, on_TrackerBar_boxFilter);
    cv::createTrackbar("value","blur",&current_value, max_value, on_TrackerBar_blur);
    cv::createTrackbar("value","gaussianBlur",&current_value, max_value, on_TrackerBar_GaussianBlur);
    cv::createTrackbar("value","medianBlur",&current_value, max_value, on_TrackerBar_MedianBlur);
    cv::createTrackbar("value","bilateralFilter",&current_value, max_value, on_TrackerBar_BilateralFilter);
    on_TrackerBar_boxFilter(current_value,0);
    on_TrackerBar_blur(current_value,0);
    on_TrackerBar_GaussianBlur(current_value, 0);
    on_TrackerBar_MedianBlur(current_value,0);
    on_TrackerBar_BilateralFilter(current_value, 0);
    cv::waitKey(0);
}
