//
//  test_c.cpp
//  myTest
//
//  Created by delims on 2019/6/6.
//

#include "test_c.hpp"
#include <csignal>
#include <unistd.h>
#include <vector>

#pragma mark 基类

class Shape
{
public:
    virtual int getArea() = 0;

    void setHeight(int h) {
        this->height = h;
    }
    void setWidth(int w);
    
public:
    int height;
    int width;
protected:
    int side;
};

void Shape::setWidth(int w) {
    this->width = w;
}

#pragma mark 子类

class Rectangle : public Shape
{
protected:
    int getArea() {
        return (width * height);
    }
    
public:
//    Rectangle();
//    Rectangle(int h);
    ~Rectangle();
    Rectangle operator+(const Rectangle& b)
    {
        Rectangle rect;
        rect.height = this->height + b.height;
        rect.width = this->width + b.width;
        
        return rect;
    }
public:
    int getHeight();
    friend int getWidth(Rectangle rect);
    friend class Box;
};

#pragma mark 类外实现的方法

int Rectangle::getHeight()
{
    return this->height;
}

int getWidth(Rectangle rect)
{
    return rect.side;
}

//Rectangle::Rectangle()
//{
//    printf("rectangle is being created\n");
//}

//Rectangle::Rectangle(int h)
//{
//    this->height = h;
//}

//Rectangle::Rectangle(int h): height(h)
//{
//    printf("object is being created and initial height\n");
//
//}

Rectangle::~Rectangle()
{
//    printf("Object is being deleted\n");
}


class Box
{

public:
    double length;
    double breadth;
    double height;
    
    void funcBox(){
        Rectangle rect ;
        rect.side = 10;
    }
    

};

#pragma mark 命名空间
namespace first_namespace {
    void func(){
        printf("Inside first namespace \n");
    }
    
    namespace third {
        void func(){
            printf("Inside third namespace \n");


        }
    }
}

namespace second_namespace {
    void func(){
        printf("Inside second namespace \n");
    }
    
    class apple{
    public:
        static void func2();
        void func3(){
            printf("func3\n");
        }
    };
    
}

void second_namespace::apple::func2(){
    printf("Inside second namespace's apple");
}

#pragma mark 信号处理

void signalHandler(int signalNum)
{
    printf("Interrupt signal received\n");
}

#pragma mark 模板类

template <typename K, typename M> class Peach {
private:
    K a;
    M b;
public:
    Peach(K a, M b)
    {
        this->a = a;
        this->b = b;
    }
    
    K getA()
    {
        return a;
    }
    M getB()
    {
        return b;
    }
    
};


void delims(int i)
{
    printf("invoke by function pointer \n");
}
#pragma mark 执行的方法

void run(void)
{
    
    Box box1;
    
    box1.length = 30.0;
    box1.breadth = 20.0;
    box1.height = 100.0;
    
//    printf("%f",box1.length);
//
//    printf("%p",&box1);
    
    int *p ;
    
    long value = (long)&p;
    
    printf("%lx\n",value);
    printf("%p==%p\n",p,(p+1));
    
    
    Rectangle rect;
    
//    rect.height = 10;
    
    
//    rect.setWidth(10);
//    rect.setHeight(9);
//
//    printf("%i",rect.getArea());
//    printf("\n");
//
    printf("%i\n\n\n",rect.height);
    
    
    double *ptr = NULL;
    ptr = new double;
    
    printf("--%p\n",&ptr);
    
    
    first_namespace::func();
    second_namespace::func();
    
    second_namespace::apple::func2();
    
    second_namespace::apple apple_;
    apple_.func3();
    
    first_namespace::third::func();
    
    
    
    Rectangle rect2;
    
    rect.setWidth(10);
    rect.setHeight(10);
    
    rect2.setHeight(19);
    rect2.setWidth(18);
    
    Rectangle rect3 = rect + rect2;
    
    printf("--%i\n",rect3.height);
    
    
//    signal(SIGINT,signalHandler);
//
//    while (1) {
//        printf("go to sleep\n");
//        sleep(1);
//    }
    
    
#pragma mark 泛型
    
    Peach<int , double> peach(10,10.0);
    
    printf("%f\n\n",peach.getB());
    
    
    using namespace std;
    
    vector<int> vectorObj;
    
    for (int i = 0; i < 10; ++i) {
        vectorObj.push_back(i);
    }
    
    
    printf("元素个数= %lu\n",vectorObj.size());
    
    
    for (unsigned i = 0; i < vectorObj.size(); i ++) {
        printf("%i,",vectorObj[i]);
    }
    
    printf("\n");
    
    char c = 'a';
    char c2 = 'b';
    char  const * type = &c ;
    
//    *type = 'b';
    
    type = &c2;
    
    void (*func)(int);
    
    func = delims;
    
    func(1);
    

    void (**func2)(int);
    
    
    func2 = &func;
    
    
}



