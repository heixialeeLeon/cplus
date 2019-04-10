#include "opencv2/opencv.hpp"

void floodFill_process(cv::Mat& img)
{
    cv::Mat out=img.clone();
    cv::Rect ccomp;
    cv::floodFill(out, cv::Point(0,out.rows-1), cv::Scalar(255,0,0), &ccomp);
    cv::imshow("raw",img);
    cv::imshow("floodFill", out);
    cv::waitKey(-1);
}

int main() {
    cv::Mat img = cv::imread("../test_img/0.jpg");
    floodFill_process(img);
}