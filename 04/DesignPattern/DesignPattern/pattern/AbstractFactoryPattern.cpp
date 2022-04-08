//
//  AbstractFactoryPattern.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <stdio.h>

//工厂的工厂，和工厂设计模式差不多，只不过工厂实例也是通过抽象工厂创建的

enum factory_t {
    factory_shape,
    factory_color,
};

enum shape_t {
    shape_square,
    shape_rect,
    shape_circle,
};

enum color_t {
    color_red,
    color_green,
    color_blue,
};


class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape(){}
};

class Rectangle : public Shape {
public:
    void draw() {
        printf("draw Rectangle\n");
    }
};

class Square : public Shape {
public:
    void draw() {
        printf("draw Square\n");
    }
};

class Circle : public Shape {
public:
    void draw() {
        printf("draw Circle\n");
    }
};


class Color {
public:
    virtual void fill() = 0;
};

class Red : public Color {
public:
    void fill() {
        printf("Inside Red::fill() method\n");
    }
};

class Green : public Color {
public:
    void fill() {
        printf("Inside Green::fill() method\n");
    }
};

class Blue : public Color {
public:
    void fill() {
        printf("Inside Blue::fill() method\n");
    }
};

class AbstractFactory {
public:
    virtual Color *getColor(color_t color) {return nullptr;}
    virtual Shape *getShape(shape_t shape) {return nullptr;}
};

class ColorFactory : public AbstractFactory {
    Color *getColor(color_t color) {
        switch (color) {
            case color_red:     return new Red();
            case color_green:   return new Green();
            case color_blue:    return new Blue();
            default: break;
        }
        return nullptr;
    }
};

class ShapeFactory : public AbstractFactory {
    Shape *getShape(shape_t shape) {
        switch (shape) {
            case shape_square:   return new Square();
            case shape_rect:     return new Rectangle();
            case shape_circle:   return new Circle();
            default: break;
        }
        return nullptr;
    }
};


class FactoryProducer {
public:
    static AbstractFactory *getFactory(factory_t factory) {
        switch (factory) {
            case factory_color: return new ColorFactory();
            case factory_shape: return new ShapeFactory();
            default: break;
        }
        return nullptr;
    }
};


void test_AbstractFactoryPattern() {
    AbstractFactory *shapeFactory = FactoryProducer::getFactory(factory_shape);
    
    Shape *square = shapeFactory->getShape(shape_square);
    square->draw();
    
    delete square;

    FactoryProducer::getFactory(factory_color)->getColor(color_red)->fill();
    
    
}
