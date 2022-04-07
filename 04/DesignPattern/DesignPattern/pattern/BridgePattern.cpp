//
//  BridgePattern.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <stdio.h>

/**
桥接（Bridge）是用于把抽象化与实现化解耦，使得二者可以独立变化。这种类型的设计模式属于结构型模式，它通过提供抽象化和实现化之间的桥接结构，来实现二者的解耦。

主要解决：在有多种可能会变化的情况下，用继承会造成类爆炸问题，扩展起来不灵活。

何时使用：实现系统可能有多个角度分类，每一种角度都可能变化。

关键代码：抽象类依赖实现类。

优点： 1、抽象和实现的分离。 2、优秀的扩展能力。 3、实现细节对客户透明。

缺点：桥接模式的引入会增加系统的理解与设计难度，由于聚合关联关系建立在抽象层，要求开发者针对抽象进行设计与编程。
 
 */

//创建桥接实现接口。
class DrawApi {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

//创建实现了 DrawAPI 接口的实体桥接实现类。
class RedCircle : public DrawApi {
    void drawCircle(int radius, int x, int y){
        printf("draw circle red \n");
    }
};

class GreenCircle : public DrawApi {
    void drawCircle(int radius, int x, int y){
        printf("draw circle green \n");
    }
};

//使用 DrawAPI 接口创建抽象类 Shape。
class Shape {
protected:
    DrawApi *drawApi;
public:
    Shape(DrawApi* api) {
        this->drawApi = api;
    }
    virtual void draw() = 0;
};

//创建实现了 Shape 抽象类的实体类。
class Circle: public Shape {
private:
    int x;
    int y;
    int radius;
public:
    Circle(int x, int y, int radius, DrawApi *api) : Shape(api) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw() {
        drawApi->drawCircle(radius, x, y);
    }
};

//使用 Shape 和 DrawAPI 类画出不同颜色的圆。

void test_BridgePattern() {
    Shape *redCircle = new Circle(100,100,20,new RedCircle());
    Shape *greenCircle = new Circle(100,100,20,new GreenCircle());
    
    redCircle->draw();
    greenCircle->draw();
}
