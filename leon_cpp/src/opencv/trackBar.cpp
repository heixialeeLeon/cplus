#include "opencv2/opencv.hpp"
#include <iostream>

int current_value=3;
const int max_value = 20;

cv::Mat show_img;

void on_TrackerBar(int value, void* data)
{
    std::cout<<"current value: "<<value<<std::endl;
    if(value >0) {
        cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(value, value));
        cv::Mat out;
        //cv::dilate(show_img, out, element);
        cv::erode(show_img,out,element);
        cv::imshow("Test", out);
    }
}

int main()
{
    cv::Mat img = cv::imread("../test_img/0.jpg");
    show_img = img.clone();
    cv::namedWindow("Test");
    cv::createTrackbar("value","Test",&current_value, max_value, on_TrackerBar);
    on_TrackerBar(current_value,0);
    cv::waitKey(0);
    return 0;
}
