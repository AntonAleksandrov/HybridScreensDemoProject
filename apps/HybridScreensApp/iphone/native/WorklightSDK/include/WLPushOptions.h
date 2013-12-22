/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  WLPushOptions.h
//  WorklightStaticLibProject
//
//  Created by worklightdev on 27/01/13.
//  Copyright (c) 2013 odedr@worklight.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WLPushOptions : NSObject

@property  bool alert;
@property  bool sound;
@property  bool badge;
@property (retain) NSDictionary *parameters;

-(void) addSubscriptionParameter :(NSString *)name :(NSString *)value;

-(NSDictionary *) getSubscriptionParameters;

-(void) addSubscriptionParameters :(NSDictionary *)parameters;

-(NSString *) getSubscriptionParameter :(NSString *)name;

@end
