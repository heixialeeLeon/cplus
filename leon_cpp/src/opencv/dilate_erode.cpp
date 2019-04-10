#include "opencv2/opencv.hpp"

void dilate_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::dilate(img,out,element);
    cv::imshow("raw",img);
    cv::imshow("dilate", out);
    cv::waitKey(-1);
}

void erode_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::erode(img,out,element);
    cv::imshow("raw",img);
    cv::imshow("erode", out);
    cv::waitKey(-1);
}

void morphology_open_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::morphologyEx(img,out,cv::MORPH_OPEN,element);
    cv::imshow("raw",img);
    cv::imshow("open", out);
    cv::waitKey(-1);
}

void morphology_close_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::morphologyEx(img,out,cv::MORPH_CLOSE,element);
    cv::imshow("raw",img);
    cv::imshow("close", out);
    cv::waitKey(-1);
}

void morphology_gradient_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::morphologyEx(img,out,cv::MORPH_GRADIENT,element);
    cv::imshow("raw",img);
    cv::imshow("gradient", out);
    cv::waitKey(-1);
}

void morphology_tophat_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::morphologyEx(img,out,cv::MORPH_TOPHAT,element);
    cv::imshow("raw",img);
    cv::imshow("tophat", out);
    cv::waitKey(-1);
}

void morphology_blackhat_process(const cv::Mat& img)
{
    cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3,3));
    cv::Mat out;
    cv::morphologyEx(img,out,cv::MORPH_BLACKHAT,element);
    cv::imshow("raw",img);
    cv::imshow("blackhat", out);
    cv::waitKey(-1);
}

int main()
{
    cv::Mat img = cv::imread("../test_img/0.jpg");
    dilate_process(img);
    erode_process(img);
    morphology_open_process(img);
    morphology_close_process(img);
    morphology_gradient_process(img);
    morphology_tophat_process(img);
    morphology_blackhat_process(img);
}