#import <Foundation/Foundation.h>

@class SKProduct;
@class SKPaymentTransaction;

static NSString * const kUCEventFaqRead = @"faq_read";
static NSString * const kUCEventActionInvoked = @"action_invoked";

@interface UCEventLogger : NSObject

+ (UCEventLogger *)sharedInstance;

/**
 * Starts service.
 * @return pointer to instance of UCEventLogger.
 * @param secret - your API secret. Sign up and check developer console to receive it.
 */

+ (UCEventLogger *)startLoggingWithAPISecret:(NSString *)secret;

/**
 *  Logs custom event to server.
 * @param eventType - user-defined type of event. Should NOT start with "UCEvent", as this is prefix for internal events. Should be NSString
 * no longer than 63 characters, alphanumeric with hyphens allowed.
 */
- (void)sendEvent:(NSString *)eventType;

@end
