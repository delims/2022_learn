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

void _03_30() {

    map<int,Apple_30> test_map;
    
    Apple_30 &a = test_map[0];
    Apple_30 &b = test_map[0];
    Apple_30 &c = test_map[1];

//    Apple_30 b;

    printf("end  \n");
}
