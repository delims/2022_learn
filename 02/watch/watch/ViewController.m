//
//  ViewController.m
//  watch
//
//  Created by delims on 2022/2/25.
//

#import "ViewController.h"


@interface View : UIView

@end

@implementation View

- (void)drawRect:(CGRect)rect
{
    [super drawRect:rect];
    
    CGContextRef c = UIGraphicsGetCurrentContext();
    CGContextSetStrokeColorWithColor(c, UIColor.redColor.CGColor);
    CGContextSetLineWidth(c, 2);
    
    CGContextAddArc(c, 150, 150, 100, 0, M_PI * 2, 1);
    CGContextStrokePath(c);
}

@end


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    View *view = [View.alloc initWithFrame:self.view.bounds];
    [self.view addSubview:view];
    // Do any additional setup after loading the view.
}


@end
