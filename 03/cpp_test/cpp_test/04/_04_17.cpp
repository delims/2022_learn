//
//  _04_17.cpp
//  cpp_test
//
//  Created by delims on 2022/4/17.
//

#include <stdio.h>
#include "../class.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;
static void testFunc(int apple) {
    
}

//void F(int a) {
//    cout << "int version " <<a <<endl;
//}

void F(int& a) {
    cout << "int& version " <<a <<endl;
}

void F(int&& a) {
    // do something
    cout << "int&& version " <<a <<endl;
}

template<class A>
void G(A &&a) {
    F(std::forward<A>(a));
}

static int sum(int a,int b) {
    return a+b;
}

template <typename R>
class MyFunction {};

template <typename R,typename Arg1, typename Arg2>
class MyFunction<R(Arg1,Arg2)>
{
    using Pfunc = R(*)(Arg1,Arg2);
public:
    MyFunction(Pfunc pfunc):pfunc_(pfunc) {
        printf("MyFunction construcotr \n");
    }
    R operator()(Arg1 arg1,Arg2 arg2) {
        return pfunc_(arg1,arg2);
    }
    
private:
    Pfunc pfunc_;
};




void _04_17() {
    
//    Apple a;
    
//    a.color = 130;
//    a.weight = 245;
    
//    Apple b(a);
//    Apple b(a);

//    std::list<Apple> b;
//
//    b.push_back(a);

//    printf("%d\n",b.color);
    
//    int a = 100;

//    vector<Apple> app;
//    app.push_back(a);
//    app.push_back(std::move(a));
    // std::move  转成右值引用。
//    Apple b = std::move(a);

//    testFunc(std::forward<Apple>(a));
    
//    int i = 2;
//    G(i); //int& version
//    G(5); //int& version

    
//    testFunc(a);
    
//    MyFunction<int(int,int)> func2 = sum;
//    std::cout << func2(10,20) << endl;
    
    bool a = true;
    
    if (!!!!a) {
        printf("true");
    }
    
    
}
