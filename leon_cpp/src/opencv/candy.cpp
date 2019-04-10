#include "opencv2/opencv.hpp"

int main()
{
    cv::Mat img = cv::imread("../test_img/1.jpg");
    cv::resize(img, img, cv::Size(img.cols/5,img.rows/5));
    cv::Mat img_gray;
    cv::Mat edge, dst;

    dst.create(img.size(), img.type());
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cv::blur(img_gray,edge, cv::Size(3,3));
    cv::Canny(edge, edge, 3, 9, 3);
    dst = cv::Scalar::all(0);
    img.copyTo(dst,edge);

    cv::imshow("raw",img);
    //cv::imshow("blur", edge);
    cv::imshow("canny", edge);
    cv::imshow("dst", dst);
    cv::waitKey(-1);
}


