//
//  ViewController.m
//  iPad
//
//  Created by delims on 2022/4/4.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

void func1() {
    
}

void objc_release(id obj) {
    printf("hello world \n");
}

int func() {
    
    int a;
    int i;
    
    a = a + i;
    
    return a;
}




- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.whiteColor;
    
    int a;
    int *p = &a;
    NSLog(@"%p",p);
    
//    DISPATCH_DECL(name) typedef struct name##_s *name##_t
    NSLog(@"%s",__func__);
    dispatch_get_main_queue()
    func();
    // Do any additional setup after loading the view.
}


@end
