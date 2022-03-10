//
//  _03_09.cpp
//  cpp_test
//
//  Created by delims on 2022/3/9.
//

#include "_03_09.hpp"
#include <list>
#include <deque>

extern void _03_09(const char *) {
    
    std::list<int> a;
    
    std::deque<int> dak;
    dak.push_back(1);
    
    printf("%d \n",dak.size());

}
