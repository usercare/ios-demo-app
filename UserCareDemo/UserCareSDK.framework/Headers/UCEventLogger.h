#import <Foundation/Foundation.h>

@class SKProduct;
@class SKPaymentTransaction;
@class UCEvent;

static NSString *const kUCEventFaqRead = @"faq_read";
static NSString *const kUCEventActionInvoked = @"action_invoked";

/**
 Main interface of event SDK. Initialize it with startLoggingWithAPISecret: . First get API secret from developer console.
 */
@interface UCEventLogger : NSObject


+ (UCEventLogger *)sharedInstance;

/**
    Starts service.
    @return pointer to instance of UCEventLogger.
    @param secret - your API secret. Sign up and check developer console to receive it.
 */

+ (UCEventLogger *)startLoggingWithAPISecret:(NSString *)secret;

/**
    Logs custom event to server.
    @param eventType - user-defined type of event. Should be NSString no longer than 63 characters, alphanumeric with hyphens allowed.
    @param parameters - dictionary of additional parameters
 */
- (void)sendEvent:(NSString *)eventType withCustomParameters:(NSDictionary *)parameters;

- (void)sendEventWithEvent:(UCEvent *)event;

@end
