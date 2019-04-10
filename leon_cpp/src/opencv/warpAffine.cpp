#include "opencv2/opencv.hpp"
#include <iostream>

int main()
{
    cv::Mat img = cv::imread("../test_img/3.jpg");
    cv::Mat dst, rotateDst;
    cv::Point2f srcTriangle[3], dstTriangle[3];
    cv::Mat rotMat(2,3,CV_32FC1);
    cv::Mat warpMat(2,3,CV_32FC1);

    dst = cv::Mat::zeros(img.size(),img.type());

    srcTriangle[0] = cv::Point2f(0,0);
    srcTriangle[1] = cv::Point2f(static_cast<float>(img.cols-1),0);
    srcTriangle[2] = cv::Point2f(0, static_cast<float>(0,img.rows-1));

    dstTriangle[0] = cv::Point2f(static_cast<float>(img.cols*0.0), static_cast<float>(img.rows*0.33));
    dstTriangle[1] = cv::Point2f(static_cast<float>(img.cols*0.65), static_cast<float>(img.rows*0.35));
    dstTriangle[2] = cv::Point2f(static_cast<float>(img.cols*0.5), static_cast<float>(img.rows*1));

    warpMat = cv::getAffineTransform(srcTriangle,dstTriangle);
    cv::warpAffine(img, dst,warpMat,dst.size());

    cv::Point center = cv::Point(img.cols/2, img.rows/2);
    double angle = -60.0;
    double scale = 0.8;
    rotMat = cv::getRotationMatrix2D(center,angle,scale);
    cv::warpAffine(img, rotateDst,rotMat, img.size());

    cv::imshow("raw", img);
    cv::imshow("warpAffine",dst);
    cv::imshow("rotate", rotateDst);
    cv::waitKey(-1);
}

