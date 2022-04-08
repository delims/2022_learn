//
//  main.cpp
//  DesignPattern
//
//  Created by delims on 2022/4/7.
//

#include <iostream>

extern void test_FactoryPattern();
extern void test_AbstractFactoryPattern();
extern void test_Singleton();
extern void test_BuilderPattern();
extern void test_PrototypePattern();
extern void test_BridgePattern();
extern void test_StatusPattern();
extern void test_StrategyPattern();
extern void test_TemplatePattern();

int main(int argc, const char * argv[]) {
        
    test_BuilderPattern();
    
    return 0;
}
