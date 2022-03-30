//
//  _03_21.cpp
//  cpp_test
//
//  Created by delims on 2022/3/21.
//

#include "_03_21.hpp"
#include <vector>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> res;
    for (int x : input) {
        if (res.empty()) res.push_back(x);
        else {
            res.push_back(x);
            
            int i = (int)res.size() - 1;
            if (res[i-1] > x) {
                while (--i >= 0) {
                    if (res[i] > x) res[i + 1] = res[i];
                    else break;
                }
                res[i+1] = x;
            }
        }
        if (res.size() > k) res.pop_back();
    }
    return res;
}

class ABC {
public:
    int a;
    int b;
    int c;
    void func(){
        printf("abc func \n");
    }
    
};


class ABCD {
public:
//    int a;
    void func(){
        printf("abcd func \n");
    }
};

struct chendashen{
    virtual void func(){
        
    }
    
    long a[1];
    
};


//virpt
//a[]


class X {
public:
    int a;
    int b;
public:
    void func() {
        printf("%d \n",a);
    }
};

class Y {
public:
    int x;
    int y;
public:
    void func2() {
        printf("%d \n",y);
    }
};



void _03_21() {
    
    X x;
    x.b = 100200;
    
    ((Y*)&x)->func2();
    
//    chendashen c;
    
//    printf("%d\n",sizeof(c));
//    printf("%p\n",c.a[-1]);

//    vector<int> input({4,5,1,6,2,7,3,8});
    
//    ABCD o;
//    (*((ABC*)&o)).func();
//    printf("abcd %d \n",(*((ABC*)&o)).a);
//    printf("abcd %d \n",(*((ABC*)&o)).b);

//    for (int x : GetLeastNumbers_Solution(input, 4)) printf("%d ",x);
    
    
//    int a = *(int*)1;
//    GetLeastNumbers_Solution(input, 4);
    
//    ABCD *a = NULL;
//    a->func();
//
//    ((ABCD*)(NULL))->func();
}
