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
    
    NSString *pcmFilePath = [NSBundle.mainBundle pathForResource:@"冰雨片段8k16bit单声道" ofType:@"pcm"];
    
    bool exist =  [NSFileManager.defaultManager fileExistsAtPath:pcmFilePath];
    
    NSArray *contents =  [NSFileManager.defaultManager contentsOfDirectoryAtPath:NSBundle.mainBundle.bundlePath error:nil ];
    
//    for (NSString *item in contents) {
//        NSLog(item);
//    }
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,  NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *mp3Path = [documentsDirectory stringByAppendingPathComponent:@"vocal.mp3"];
    
    Mp3Encoder *mp3 = new Mp3Encoder();

    mp3->init(pcmFilePath.UTF8String, mp3Path.UTF8String, 4000, 1, 3000);
    mp3->encode();

    NSLog(@"%d",exist);
    
    delete mp3;
    
}


@end
