#pragma once

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/tracking.hpp>

cv::Mat wipeRed(cv::Mat image, int threshold)
{
    cv::Mat gray;
    cv::cvtColor(image, gray, CV_RGB2GRAY);
    cv::Mat binary;

    cv::threshold(gray, binary, threshold,255, CV_THRESH_BINARY);

    std::vector<cv::Mat> channels;
    cv::split(image, channels);
    cv::Mat red = channels[2];
    cv::Mat blue = channels[0];
    cv::Mat green = channels[1];

    cv::Mat red_binary;
    cv::threshold(red,red_binary,threshold,255, CV_THRESH_BINARY);
    channels[2] = red_binary;

    cv::Mat result;
    cv::merge(channels, result);
    return result;
}

cv::Mat wipeRedProcess(const cv::Mat& image)
{
    cv::Mat wipedImage;
    std::vector<cv::Mat> split_image;
    int w = image.cols;
    int h = image.rows;
    const int red_threshold = 200;

    split(image, split_image);

    cv::Mat wipe(image.rows, image.cols, CV_8UC1, cv::Scalar(0));  //todo remove this line

    cv::Mat& m_b = split_image[0];
    cv::Mat& m_g = split_image[1];
    cv::Mat& m_r = split_image[2];

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            uchar &b = m_b.at<uchar>(i,j);
            uchar &g = m_g.at<uchar>(i,j);
            uchar &r = m_r.at<uchar>(i,j);
            //red and bright
            if(b * b + g * g < r * r && r > red_threshold)
            {
                b = 255;
                g = 255;
                r = 255;
                wipe.at<uchar>(i,j) = 255;  // todo remove this line
            }
        }
    }
    // change the image back to rgb
    cvtColor(split_image[2], wipedImage, CV_GRAY2BGR);
    return wipedImage;
}


