#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main()
{
    cv::Mat img = cv::imread("../test_img/3.jpg");
    cv::resize(img, img, cv::Size(img.cols,img.rows));
    cv::Mat img_gray, img_mid;
    cv::Mat dst;
    std::vector<cv::Vec2f> lines;

    cv::cvtColor(img,img_mid , cv::COLOR_BGR2GRAY);
    cv::Canny(img_mid, img_mid,50, 200,3);
    cv::cvtColor(img_mid, dst, cv::COLOR_GRAY2BGR);
    cv::HoughLines(img_mid, lines, 1, CV_PI/180,150, 0, 0);
    //cv::HoughLinesP(img_mid, lines, 1,  CV_PI/180, 50, 100, 150);

    for(size_t i = 0; i<lines.size(); i++)
    {
        float rho =lines[i][0];
        float theta = lines[i][1];
        cv::Point pt1, pt2;
        double a = std::cos(theta);
        double b = std::sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 500*(-b));
        pt1.y = cvRound(y0 + 500*(a));
        pt2.x = cvRound(x0 - 500*(-b));
        pt2.y = cvRound(y0 - 500*(a));
        cv::line(dst, pt1,pt2, cv::Scalar(255,0,0),1, cv::LINE_AA);
    }

    cv::imshow("raw",img);
    cv::imshow("canny", img_mid);
    cv::imshow("dst", dst);
    cv::waitKey(-1);
}

