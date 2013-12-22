/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  WLPush.h
//  WorklightStaticLibProject
//
//  Created by worklightdev on 24/01/13.
//  Copyright (c) 2013 odedr@worklight.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WLClient.h"
#import "WLOnReadyToSubscribeListener.h"
#import "WLEventSourceListener.h"
#import "WLDelegate.h"
#import "WLPushOptions.h"

@interface WLPush : NSObject

@property (retain) id <WLOnReadyToSubscribeListener> onReadyToSubscribeListener;
@property (retain) NSMutableDictionary *registeredEventSources;
@property  BOOL isTokenUpdatedOnServer;
@property (retain) NSString *serverToken;
@property (retain) NSString *deviceToken;
@property (retain) NSMutableArray *subscribedEventSources;
@property (retain) NSString *tokenFromClient;

+(WLPush *) sharedInstance;

-(void) setOnReadyToSubscribeListener:(id <WLOnReadyToSubscribeListener>)listener;

-(void) registerEventSourceCallback:(NSString *)alias :(NSString *)adapter :(NSString *)eventsource :(id <WLEventSourceListener>)eventSourceListener;

-(BOOL)isAbleToSubscribe :(NSString * )alias :(BOOL)isRegistering;

-(void) updateToken :(NSString *)svrToken;

-(void) updateTokenCallback :(NSString *)deviceToken;

-(void) clearSubscribedEventSources;

-(void) updateSubscribedEventSources :(NSDictionary *) eventSources;

-(void) subscribe :(NSString *)alias :(WLPushOptions *)options : (id <WLDelegate>)responseListener;

-(void) unsubscribe :(NSString *)alias :(id <WLDelegate>)responseListener;

-(BOOL) isSubscribed :(NSString *)alias;

-(BOOL)isPushSupported;

@end
