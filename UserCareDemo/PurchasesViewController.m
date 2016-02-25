#import "PurchasesViewController.h"

@interface PurchasesViewController ()

@end
#import <UserCareSDK/UserCareSDK.h>
#import <StoreKit/StoreKit.h>

@interface PurchasesViewController  () <UCEventsPurchaseHelperDelegate, UIAlertViewDelegate>

@property (nonatomic, strong) NSArray *productIds;
@property (nonatomic, strong) UCEventsPurchaseHelper *purchaseHelper;
@property (nonatomic, strong) NSMutableArray *productsArray;
@property (weak, nonatomic) IBOutlet UILabel *label;

@end

@implementation PurchasesViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.productIds = [NSArray arrayWithObjects:@"your_purchase_id", nil];
    
    self.purchaseHelper = [[UCEventsPurchaseHelper alloc] initWithProductsIdsArray:self.productIds];
    self.purchaseHelper.delegate = self;
}

- (IBAction)performPurchase:(id)sender
{
    if (self.productsArray.count) {
        [self.purchaseHelper launchPurchaseFlow:[self.productsArray objectAtIndex:0]];
    } else {
         self.label.text = @"Please input proper product IDs.";
    }
}

#pragma mark - SKPaymentTransactionObserver and SKProductsRequestDelegate
- (void)purchaseHelper:(UCEventsPurchaseHelper *)purchaseHelper didReceiveResponse:(SKProductsResponse *)response withProductsArray:(NSMutableArray *)productsArray
{
    self.productsArray = productsArray;
}

- (void)purchaseHelper:(UCEventsPurchaseHelper *)purchaseHelper updatedTransaction:(SKPaymentTransaction *)transaction
{
    if (transaction.transactionState == SKPaymentTransactionStatePurchased) {
       self.label.text = @"Purchase sucessful. You can now see it in your admin panel.";
    }
}

@end
