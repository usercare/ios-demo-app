#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UCCustomizable.h"

@class UCTextStyle;
@class UCImageStyle;
@class UCButtonStyle;

@interface UCFAQDialogStyle : NSObject <UCStyle>

@property (nonatomic, strong, nonnull) UCImageStyle *background;
@property (nonatomic, strong, nonnull) UCTextStyle *textStyle;
@property (nonatomic, strong, nullable) UCTextStyle *textFieldStyle;
@property (nonatomic, strong, nonnull) UCButtonStyle *buttonStyle;

@end
