//
//  BuilderPattern.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <stdio.h>

/**
建造者模式
建造者模式（Builder Pattern）使用多个简单的对象一步一步构建成一个复杂的对象。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。

一个 Builder 类会一步一步构造最终的对象。该 Builder 类是独立于其他对象的。
 */

#include <string>
using namespace std;

// 表示食物和包装的接口
class Packing {
public:
    virtual string pack() = 0;
};

class Item {
public:
    virtual string name() = 0;
    virtual Packing *packing() = 0;
    virtual float price() = 0;
};

//创建实现 Packing 接口的实体类。

class Wrapper : public Packing {
public:
    string pack() {
        return "Wrapper";
    }
};

class Bottle : public Packing {
public:
    string pack() {
        return "Bottle";
    }
};

//创建实现 Item 接口的抽象类，该类提供了默认的功能。

class Burger : public Item {
public:
    Packing *packing() {
        return new Wrapper();
    };
    virtual float price() {
        return 0;
    }
};

class ColdDrink : public Item {
public:
    Packing *packing() {
        return new Bottle();
    };
    virtual float price() {
        return 0;
    }
};

class VegBurger : public Burger {
public:
    string name() {
        return "VegBurger";
    };
    float price() {
        return 25;
    }
};

class ChickenBurger : public Burger {
public:
    string name() {
        return "ChickenBurger";
    };
    float price() {
        return 35;
    }
};

class Coke : public ColdDrink {
public:
    string name() {
        return "Coke";
    };
    float price() {
        return 30;
    }
};

class Pepsi : public ColdDrink {
public:
    string name() {
        return "Pepsi";
    };
    float price() {
        return 35;
    }
};

#include <vector>

//创建一个 Meal 类，带有上面定义的 Item 对象。

class Meal {
    vector<Item*> items;
public:
    void addItem(Item* item) {
        items.push_back(item);
    }
    float getCost() {
        float cost = 0.0f;
        for (Item *item : items)
            cost += item->price();
        return cost;
    }
    void showItems() {
        for (Item *item : items)
        {
            printf("name : %s \n",item->name().c_str());
            printf("pack : %s \n",item->packing()->pack().c_str());
            printf("price: %f \n",item->price());
        }
    }
};

//创建一个 MealBuilder 类，实际的 builder 类负责创建 Meal 对象。

class MealBuilder {
public:
    Meal* prepareVegMeal() {
        Meal *meal = new Meal();
        meal->addItem(new VegBurger());
        meal->addItem(new Coke());
        return meal;
    }
    Meal* prepareNonVegMeal() {
        Meal *meal = new Meal();
        meal->addItem(new ChickenBurger());
        meal->addItem(new Pepsi());
        return meal;
    }
};


void test_DesignPattern() {
    MealBuilder *mealBuilder = new MealBuilder();
    Meal *vegMeal = mealBuilder->prepareVegMeal();
    
    printf("Veg Meal: \n");
    vegMeal->showItems();
    printf("Veg Meal cost : %f\n",vegMeal->getCost());

    printf("\n");
    
    Meal *nonVegMeal = mealBuilder->prepareNonVegMeal();
    printf("Non Veg Meal: \n");
    nonVegMeal->showItems();
    printf("Non Veg Meal cost : %f\n",nonVegMeal->getCost());
}
