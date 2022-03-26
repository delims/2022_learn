//
//  ViewController+Extend.m
//  category_research
//
//  Created by delims on 2022/3/23.
//

#import "ViewController+Extend.h"
@implementation Apple (Extend)

- (void)func1
{
    int a = 100;
    int b = a * a;
    int c = b - a;
    b = c;
}

- (void)func2:(int)arg
{
    int a = 100;
    int b = a * a;
    int c = b - a;
    a = c;
}

- (void)setAge:(NSString *)age
{
}

- (void)setName:(NSString *)name
{
}

- (NSString *)name
{
    return @"name_delims";
}

- (NSString *)age
{
    return @"age_delims";
}

@end
