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
 
 * @param secret - your API secret.     Sign up and check developer console to receive it.
 
 */

+ (UCEventLogger *)startLoggingWithAPISecret:(NSString *)secret;

/**
 
 *  Logs In app Purchase event to server.
 
 * @param product - purchased product.
 
 */
- (void)sendPurchaseEventWithProduct:(SKProduct *)product withTransaction:(SKPaymentTransaction *)transaction isPurchased:(BOOL)isPurchased;

/**
 
 *  Logs custom event to server.
 
 * @param eventType - user-defined type of event. Should NOT start with "UCEvent", as this is prefix for internal events. Should be NSString matching pattern /^[a-zA-Z_][a-zA-Z0-9\-_]{0,63}$/
 
 * which means <64 characters long starting with letter or underscore A-Z 0-9 with hyphens.
 
 * @param value - any string, containing data about event
 
 */
- (void)sendEvent:(NSString *)eventType;

@end
