//
//  _04_22.cpp
//  cpp_test
//
//  Created by delims on 2022/4/22.
//

#include <stdio.h>
#include "../class.h"
#include <functional>

using namespace std;

class Pear
{
    
};

class Container {
private:
    void *buf;
    template <class T>
    struct Hepler {
        static void del(void *ptr) {
            delete (T*) ptr;
        }
    };
    void (*del)(void *ptr);
public:
    template <class T>
    Container(T &data) {
        buf = (void*)new T(data);
        del = Hepler<T>::del;
        cout << "copy" << endl;
    }
    template<class T>
    Container(T &&data) {
        buf = (void*)new T(data);
        del = Hepler<T>::del;
        cout << "move" << endl;
    }
    ~Container() {
        del(buf);
        cout << "free" << endl;

    }
};

template<class out, class... in>
class LambdaContainer {
private:
    void *buf;
    template <class T>
    struct Helper {
        static out call(void* ptr,in ... arg) {
            return ((T*)ptr)->operator()(std::forward<in...>(arg...));
        }
        static void del(void *ptr) {
            delete (T*)ptr;
        }
    };
    
    out (*call)(void *ptr, in ...arg);
    void (*del)(void *ptr);
    
public:
    
    template<class T>
    LambdaContainer(T &data) {
        buf = (void*)new T(data);
        call = Helper<T>::call;
        del = Helper<T>::del;
        cout << "copy" << endl;
    }
    
    template<class T>
    LambdaContainer(T &&data) {
        buf = (void*)new T(data);
        call = Helper<T>::call;
        del = Helper<T>::del;
        cout << "move" << endl;
    }
    
    out operator()(in ...arg) {
        return call(buf,std::forward<in...>(arg...));
    }
    
    ~LambdaContainer() {
        del(buf);
        cout << "free" << endl;
    }
    
};

void _04_22() {
    
    
//    double pi = 3.14;
//
//    Container x(1);
//    Container y(pi);
//
//    LambdaContainer<double, double> func = [=](double n) {
//        return n * pi;
//    };
//
//    cout << func(2) << endl;
    
    Apple a;
    
    a();
    a(1,2);
    
//    char x = 1;
//    char y = 2;
//
//    long a = 1;
//    auto func1 = [=](long b) {
//        return b + x + a + y;
//    };
//
//    std::function<long(long)> func2 = [=](long z) {
//        return z + a ;
//    };
//
//    printf("%lu\n",sizeof(func1));
//    printf("%lu\n",sizeof(func2));

    
    
 
    
}
