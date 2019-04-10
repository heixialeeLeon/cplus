#include <iostream>
#include <boost/filesystem.hpp>

int main()
{
    const std::string src = "/data_1/chejian_develop/chejian/model/cls_chemenpentu/se_chemenpentu.caffemodel";
    const std::string dst = "/dev/shm/test.caffemodel";
    boost::filesystem::copy_file(src, dst);
}

