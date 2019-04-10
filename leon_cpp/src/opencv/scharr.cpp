#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main()
{
    cv::Mat img = cv::imread("../test_img/1.jpg");
    cv::resize(img, img, cv::Size(img.cols/5,img.rows/5));
    cv::Mat grad_x, grad_y, grad_abs_x, grad_abs_y;
    cv::Mat dst;

    cv::Scharr(img, grad_x, CV_16S, 1,0,1,0);
    cv::convertScaleAbs(grad_x, grad_abs_x);

    cv::Scharr(img, grad_y, CV_16S, 0,1,1,0);
    cv::convertScaleAbs(grad_y, grad_abs_y);

    cv::addWeighted(grad_abs_x,0.5,grad_abs_y,0.5,0,dst);

    std::cout<<grad_x.type()<<std::endl;
    std::cout<<img.type()<<std::endl;
    std::cout<<grad_abs_x.type()<<std::endl;

    cv::imshow("raw",img);
    cv::imshow("grad_x", grad_abs_x);
    cv::imshow("grad_y", grad_abs_y);
    cv::imshow("dst", dst);
    cv::waitKey(-1);
}