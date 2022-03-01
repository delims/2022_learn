//
//  ViewController.m
//  gcd_test
//
//  Created by delims on 2022/3/1.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    

    // Do any additional setup after loading the view.
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    NSLog(@"1");
    
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSLog(@"2");
    });
    
    dispatch_sync(dispatch_get_global_queue(0, 0), ^{
        usleep(1);
        
        NSLog(@"3");
//        sleep(1);
    });
    NSLog(@"4");
}


@end
