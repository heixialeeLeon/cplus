#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main()
{
    cv::Mat img = cv::imread("../test_img/3.jpg");
    cv::Mat map_x, map_y, dst;

    dst.create(img.size(), img.type());
    map_x.create(img.size(), CV_32FC1);
    map_y.create(img.size(), CV_32FC1);

//    for(int j=0; j<img.rows;j++)
//    {
//        for(int i=0; i< img.cols;i++)
//        {
//            map_x.at<float>(j,i) = static_cast<float>(img.cols - i);
//            map_y.at<float>(j,i) = static_cast<float>(j);
//        }
//    }

    float row_min = img.rows * 0.25;
    float row_max = img.rows * 0.75;
    float cols_min = img.cols * 0.25;
    float cols_max = img.cols * 0.75;
    for(int j=0; j<img.rows;j++)
    {
        for(int i=0; i< img.cols;i++)
        {
            if(i>cols_min && i<cols_max && j>row_min && j<row_max){
                map_x.at<float>(j,i) = static_cast<float>(2*(i-cols_min));
                map_y.at<float>(j,i) = static_cast<float>(2*(j-row_min));
            }

        }
    }
    cv::remap(img,dst,map_x,map_y, CV_INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(0,0,0));

    cv::imshow("raw",img);
    cv::imshow("dst", dst);
    cv::waitKey(-1);
}
