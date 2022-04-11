//
//  ViewController.m
//  Mp3Encoder
//
//  Created by delims on 2022/4/11.
//

#import "ViewController.h"
#include "Mp3Encoder.hpp"


@interface ViewController ()

@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = UIColor.whiteColor;
    
    Mp3Encoder *mp3 = new Mp3Encoder();
    mp3->encode();
    delete mp3;
    
}


@end
