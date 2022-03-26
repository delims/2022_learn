//
//  ViewController+Extend.h
//  category_research
//
//  Created by delims on 2022/3/23.
//

#import "Apple.h"
NS_ASSUME_NONNULL_BEGIN

@interface Apple (Extend)
@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *age;
- (void)func1;
- (void)func2:(int)arg;

@end

NS_ASSUME_NONNULL_END
