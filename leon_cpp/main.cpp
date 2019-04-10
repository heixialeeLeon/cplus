#include <iostream>
#include <functional>
#include "imageProcess.hpp"

int main() {
    std::string imageFile = "/data_1/temp/leon/red/0605_14.jpg";
    cv::Mat image = cv::imread(imageFile);
    cv::Mat result = wipeRedProcess(image);
    cv::imshow("raw",image);
    cv::imshow("test",result);
    cv::waitKey();
}