//
//  ViewController.m
//  OPEN_GL
//
//  Created by delims on 2022/4/11.
//

#import "ViewController.h"



@interface ViewController () <NSCopying>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.whiteColor;
    
    ViewController *vc = ViewController.alloc.init;
    
    [vc copy];
    
    // Do any additional setup after loading the view.
}

- (id)copyWithZone:(NSZone *)zone
{
    ViewController *vc = [ViewController allocWithZone:zone];
    
    NSLog(@"copy");
    return vc;
}

@end
