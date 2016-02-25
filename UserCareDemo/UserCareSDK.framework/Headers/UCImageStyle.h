#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

@interface UCImageStyle : NSObject <UCStyle>

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, copy) NSString *backgroundImage;
@property (nonatomic, copy) NSString *backgroundImageRepeat;

@end
