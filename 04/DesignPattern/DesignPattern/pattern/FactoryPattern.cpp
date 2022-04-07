//
//  FactoryPattern.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <cstdio>

/**
 
意图：定义一个创建对象的接口，让其子类自己决定实例化哪一个工厂类，工厂模式使其创建过程延迟到子类进行。

主要解决：主要解决接口选择的问题。

何时使用：我们明确地计划不同条件下创建不同实例时。

如何解决：让其子类实现工厂接口，返回的也是一个抽象的产品。

关键代码：创建过程在其子类执行。

优点： 1、一个调用者想创建一个对象，只要知道其名称就可以了。 2、扩展性高，如果想增加一个产品，只要扩展一个工厂类就可以。 3、屏蔽产品的具体实现，调用者只关心产品的接口。

缺点：每次增加一个产品时，都需要增加一个具体类和对象实现工厂，使得系统中类的个数成倍增加，在一定程度上增加了系统的复杂度，同时也增加了系统具体类的依赖。这并不是什么好事。
 
*/


//enum shape_t {
//    shape_rectangle,
//    shape_square,
//    shape_circle,
//    shape_other,
//};
//
//class Shape {
//public:
//    virtual void draw() {
//        printf("draw Shape\n");
//    };
//};
//
//class Rectangle : public Shape {
//    void draw() {
//        printf("draw Rectangle\n");
//    }
//};
//
//class Square : public Shape {
//    void draw() {
//        printf("draw Square\n");
//    }
//};
//
//class Circle : public Shape {
//    void draw() {
//        printf("draw Circle\n");
//    }
//};
//
//class ShapeFactory {
//public:
//    static Shape* getShape(shape_t type) {
//        switch (type) {
//            case shape_circle:      return new Circle();
//            case shape_square:      return new Square();
//            case shape_rectangle:   return new Rectangle();
//            default:
//                break;
//        }
//        return new Shape();
//    }
//};
//
//void test_FactoryPattern()
//{
//    Shape *square = ShapeFactory::getShape(shape_square);
//    square->draw();
//    
//    Shape *circle = ShapeFactory::getShape(shape_circle);
//    circle->draw();
//
//    Shape *rectangle = ShapeFactory::getShape(shape_rectangle);
//    rectangle->draw();
//    
//    Shape *shape = ShapeFactory::getShape(shape_other);
//    shape->draw();
//}
