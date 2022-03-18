//
//  _03_14.cpp
//  cpp_test
//
//  Created by delims on 2022/3/14.
//

#include "_03_14.hpp"
#include <iostream>
#include <vector>
using namespace std;

void moveAtoB_(int &a,int &b) {
    if (b == 0 ) b = a & 0x3ff;
    else b+= (a & 0x3ff) << 10;
    a >>= 10;
}

vector<int> solve(int n, int m, vector<int>& a) {
//    int currentIndex = 0;
//    int value = a.at(currentIndex);
//
//    int j = n;
//    while (j--) {
//        int nextIndex = (currentIndex + m) % n;
//        int next = a.at(nextIndex);
//        a[nextIndex] = value;
//        value = next;
//        currentIndex = nextIndex;
//    }
    int i = -1;
    while (++i < n) moveAtoB_(a[i], a[(i+m)%n]);
    
    
    
    
    return a;
}

union isa {
public:
    isa() {
        printf("constructor \n");
    }
    ~isa() {
        printf("destructor \n");
    }
};

void _03_14() {
//    vector<int> a;
//    a.push_back(1);
//    a.push_back(2);
//    a.push_back(3);
//    a.push_back(4);
//    a.push_back(5);
//    a.push_back(6);
//
//    for (int x: solve(a.size(), 2, a)) {
//        printf("%d ",x);
//    }
    
    isa a;
    
    
    printf("\n");
}
