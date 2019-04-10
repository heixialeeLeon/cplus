#include "opencv2/opencv.hpp"

int main()
{
    cv::Mat img = cv::imread("../test_img/1.jpg");
    cv::resize(img, img, cv::Size(img.cols/5,img.rows/5));
    cv::Mat img_gray, img_guassian;
    cv::Mat edge, dst, abs_dst;

    dst.create(img.size(), img.type());
    cv::GaussianBlur(img, img_guassian, cv::Size(3,3),0,0, cv::BORDER_DEFAULT);
    cv::cvtColor(img_guassian, img_gray, cv::COLOR_BGR2GRAY);
    cv::Laplacian(img_gray, dst, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(dst, abs_dst);

    cv::imshow("raw",img);
    cv::imshow("img_guassian", img_guassian);
    cv::imshow("dst", abs_dst);
    cv::waitKey(-1);
}
