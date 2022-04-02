//
//  _03_30.cpp
//  cpp_test
//
//  Created by delims on 2022/3/30.
//

#include "_03_30.hpp"
#include <map>

using namespace std;

class Apple_30 {
public:
    Apple_30(){
        printf("constructor \n");
    }
};


class rw_lock {
public:
    
    
    
};

void _03_30() {

//    map<int,Apple_30> test_map;
//
//    Apple_30 &a = test_map[0];
//    Apple_30 &b = test_map[0];
//    Apple_30 &c = test_map[1];

//    Apple_30 b;

    printf("end  \n");
}

#include <vector>
#include <string>
#include <cstdio>

using namespace std;

class PhotoFileManager
{
    vector<string> files;
    const char* date_time_string() {
        static char s[32] = {0};
        time_t t = time(0);
        strftime(s, sizeof(s), "%Y%m%d%H%M%S.jpg", localtime(&t));
        return s;
    }
public:
    void add(const char* path) {
        files.push_back(path);
    }
    void remove_old() {
        while (files.size() >= 7) {
            delete_at_index(5);
            delete_at_index(3);
            delete_at_index(1);
        }
    }
    
    void delete_at_index(size_t index) {
        int ret = ::remove(files[index].c_str());
        if (ret == 0) {
            printf("删除成功 %s \n",files[index].c_str());
        } else {
            printf("删除失败 %s \n",files[index].c_str());
        }
        files.erase(files.begin()+index);
    }
    
    void accept(const char *path) {
        string dir = "/var/images/";
        dir = dir + date_time_string();
        ::rename(path, dir.c_str());
        add(dir.c_str());
    }
    
    
};


//const char* date_time_string() {
//    static char s[32] = {0};
//    time_t t = time(0);
//    strftime(s, sizeof(s), "%Y%m%d%H%M%S", localtime(&t));
//    return s;
//}
