#import <Foundation/Foundation.h>
#import "UCCustomizable.h"

@class UIColor;
@class UCTextStyle;

@interface UCButtonStyle : NSObject <UCStyle>

@property (nonatomic, strong) NSString *image;
@property (nonatomic, strong) UCTextStyle *textStyle;
@property (nonatomic, strong) NSString *textLocation;
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) UIColor *backgroundColor;

@end
