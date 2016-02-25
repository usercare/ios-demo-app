#import <Foundation/Foundation.h>

@class SKProductsResponse;
@class SKPaymentTransaction;
@class UCEventsPurchaseHelper;

@protocol UCEventsPurchaseHelperDelegate <NSObject>

- (void)purchaseHelper:(UCEventsPurchaseHelper *)purchaseHelper didReceiveResponse:(SKProductsResponse *)response withProductsArray:(NSMutableArray *)productsArray;
- (void)purchaseHelper:(UCEventsPurchaseHelper *)purchaseHelper updatedTransaction:(SKPaymentTransaction *)transaction;

@end

@interface UCEventsPurchaseHelper : NSObject

@property (nonatomic, weak) id <UCEventsPurchaseHelperDelegate> delegate;

- (instancetype)initWithProductsIdsArray:(NSArray *)productIdsArray;
- (void)launchPurchaseFlow:(NSString *)productId;

@end
