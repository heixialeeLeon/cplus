#include <opencv2/opencv.hpp>
#include <iostream>

typedef std::map<int, cv::Mat> ID_COLORMAP;

int main()
{
    ID_COLORMAP mat_maps;
    cv::Mat img = mat_maps[0];
    if(img.empty()){
        std::cout<<"get empty img"<<std::endl;
    }
    cv::Mat img_new = cv::Mat(10,10,CV_8UC3);
    mat_maps[0] = img_new;
    if(mat_maps[0].empty()){
        std::cout<<"get empty img"<<std::endl;
    }else{
        std::cout<<"get new img not empty"<<std::endl;
    }

    int a[] = {1,2,3,4};
    std::cout<<sizeof(a)/sizeof(int)<<std::endl;
}
