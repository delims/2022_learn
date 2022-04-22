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
//#include <weak_ptr>
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

class RedApple : public Apple {
public:
    
    RedApple(){
        printf("red apple constructor\n");
    }
    ~RedApple(){
        printf("red apple destructor\n");
    }
    
    void* operator new(unsigned long size) {
        printf("call new \n");
        return  malloc(100);
    }
    operator int() {
        return 456;
    }
};


//static void test_func(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9) {
//    int x1 = a7;
//    int x2 = a8;
//    int x3 = a9;
//}
//static void test_func(int a1,int a2,int a3,int a4,int a5,int a6) {
//
//}

Apple testCopy(Apple  a) {
    return a;
}




void _04_17() {

//    test_func(1, 2, 3, 4, 5, 6);
//    test_func(1, 2, 3, 4, 5, 6,7,8,9);
    
//    Apple a;
//    testCopy(a);

//    weak_ptr<Apple> a = std::make_<Apple>();
    
    

//    RedApple *a = new RedApple();
//
//    delete a;
    
//    void *p = operator new (100);
//
//    Apple *a =  new (p) Apple();
//
//    RedApple *red = new RedApple;
//
//    print_int((int)*red);

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
    
//    bool a = true;
//
//    if (!!!!a) {
//        printf("true");
//    }
//
    
}
