#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/nonfree"
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("../test_img/3.jpg");
    int minHessian = 400;
    std::vector<cv::KeyPoint> keypoints;
    cv::SurfFeatureDetector
}

