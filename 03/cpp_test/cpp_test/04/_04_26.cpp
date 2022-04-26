//
//  _04_26.cpp
//  cpp_test
//
//  Created by delims on 2022/4/26.
//

#include <stdio.h>
#include "../class.h"
#include <map>

#pragma pack(4)
struct A {
    short a;
    char b;
    int c;
};




void _04_26() {
    
//    vector<Apple> res;
//    Apple a;
//
//    cout << res.size() << " " << res.capacity() << " data=" << res.data() << endl;
//
//    res.push_back(a);
//    cout << res.size() << " " << res.capacity() << " data=" << res.data() << endl;
//
//    res.push_back(a);
//
//    cout << res.size() << " " << res.capacity() << " data=" << res.data() << endl;
//
//    res.push_back(a);
//
//    cout << res.size() << " " << res.capacity() << " data=" << res.data() << endl;

    
//    cout << sizeof(A) << endl;
    
    int i = 100;
    const int j = 200;
    
    printf("%p \n%p \n",&i,&j);
    
}
