#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

extern NSString * const kUCJSONKeyLabelBackgroundColor;

@interface UCTextStyle : NSObject <UCStyle>

@property (nonatomic, strong) NSString *fontFamily;
@property (nonatomic, strong) NSString *fontStyle;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) NSNumber *fontSize;

@end
