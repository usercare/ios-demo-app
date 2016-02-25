#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UCCustomizable.h"

@class UCTextStyle;

@interface UCLabelStyle : NSObject <UCStyle>

@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, strong) UIColor *backgroundColor;

@end
