//
//  UCLiveChatClient.h
//  ConciergeDemoApp
//
//  Created by andrey.bolshakov on 2/26/15.
//  Copyright (c) 2015 Manage. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UCCustomMessage;
@protocol UCLiveChatController <NSObject>

- (void)receiveMessages:(NSArray *)messages;
- (void)receiveHistory:(NSArray *)messages;

@end

@interface UCLiveChatClient : NSObject

- (void)sendMessage:(UCCustomMessage *)message;

@property (nonatomic, weak) id <UCLiveChatController> controller;

@end
