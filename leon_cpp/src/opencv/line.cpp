#include "opencv2/opencv.hpp"
#include <iostream>

int main()
{
    cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC3);
    std::vector<cv::Point> points;

    points.push_back(cv::Point(48, 58));
    points.push_back(cv::Point(105, 98));
    points.push_back(cv::Point(155, 160));
    points.push_back(cv::Point(212, 220));
    points.push_back(cv::Point(248, 260));
    points.push_back(cv::Point(320, 300));
    points.push_back(cv::Point(350, 360));
    points.push_back(cv::Point(412, 400));

    for(int i=0; i<points.size();i++)
    {
        cv::circle(image, points[i],5, cv::Scalar(0,0,255),2,8,0);
    }

    cv::Vec4f line_para;
    cv::fitLine(points, line_para, cv::DIST_L2, 0, 1e-2,1e-2);
    std::cout<<"line_para = " << line_para <<std::endl;

    cv::Point point0;
    point0.x = line_para[2];
    point0.y = line_para[3];
    double k = line_para[1]/line_para[0];

    cv::Point point1,point2;
    point1.x = 50;
    point1.y = k*(50-point0.x)+point0.y;
    point2.x = 300;
    point2.y = k*(300-point0.x)+point0.y;

    cv::line(image, point1, point2, cv::Scalar(0,255,0),2,8,0);

    cv::imshow("image", image);
    cv::waitKey(0);
    return 0;
}
