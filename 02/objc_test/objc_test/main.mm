//
//  main.m
//  objc_test
//
//  Created by delims on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

union isa_t {
    isa_t(){}
    isa_t(uintptr_t value):bits(value){}
    uintptr_t bits;
    Class cls;
    struct {
        uintptr_t nonpointer        : 1;                                         \
        uintptr_t has_assoc         : 1;                                         \
        uintptr_t has_cxx_dtor      : 1;                                         \
        uintptr_t shiftcls          : 44; /*MACH_VM_MAX_ADDRESS 0x7fffffe00000*/ \
        uintptr_t magic             : 6;                                         \
        uintptr_t weakly_referenced : 1;                                         \
        uintptr_t deallocating      : 1;                                         \
        uintptr_t has_sidetable_rc  : 1;                                         \
        uintptr_t extra_rc          : 8;
    };
};

struct obj_object {
    isa_t isa;
};

struct obj_class : public obj_object {
    Class superclass;
    long cache1;
    long cache2;
    uintptr_t bits;
};

@interface Apple : NSObject

@end
@implementation Apple

@end


void findIsa(uintptr_t o){
    obj_object *p = (obj_object*)o;
    if (p->isa.nonpointer) {
        printf("obj %p ->",p);
        findIsa(p->isa.shiftcls << 3);
        static int count = 0;
        count += 1 ;
        if (count > 10) {
            
            
        };
    } else {
        printf("cls %p ->",p);
        findIsa(p->isa.bits);
        static int count = 0;
        count += 1 ;
        if (count > 10) {
        
        };
    }
}



int main(int argc, const char * argv[]) {
//    @autoreleasepool {
//        // insert code here...
//        NSLog(@"Hello, World!");
//    }
    
    
    
    Apple *a = [[Apple alloc]init];
    Apple *a1 = a;
    
    obj_object *b;
    memcpy(&b, &a, sizeof(a));
    
    findIsa((uintptr_t)a);

//    printf("%x \n" ,b->isa.extra_rc);
//    printf("%x \n" ,b->isa.nonpointer);
//    printf("%lx \n",b->isa.shiftcls << 3);
//    printf("%lx \n", Apple.class);
//
//    obj_class *c =(obj_class*)(b->isa.shiftcls << 3);
//
//    NSLog(@"%@",NSStringFromClass((__bridge Class)c));
//
//    printf("= %lx \n" ,c->isa.nonpointer);
//    printf("= %lx \n" ,c->isa.extra_rc);
//    printf("= %lx \n" ,c->isa.bits);
//
//    printf("= %lx \n" ,c->superclass);
//    printf("= %lx \n", NSObject.class);
//
//    obj_class *nsobject =(__bridge obj_class*)(NSObject.class);
//
//
//    printf("|= %lx \n", nsobject->isa.bits);

    return 0;
}
