/*
 * Licensed Materials - Property of IBM
 * 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  WLCallbackFactory.h
//  WorklightStaticLibProject
//
//  Created by Dolev Dotan on 10/30/13.
//  Copyright (c) 2013 odedr@worklight.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol WLTriggerCallback;
@protocol WLGeoCallback;
@protocol WLGeoFailureCallback;
@protocol WLWifiConnectedCallback;
@protocol WLWifiFailureCallback;
@protocol WLDeviceContext;
@class    WLGeoError;
@class    WLWifiError;
@class    WLGeoPosition;
@class    WLWifiAccessPoint;


/**
 A utility class that allows using blocks wherever a callback object is needed in the Worklight Location Services API.
 */
@interface WLCallbackFactory : NSObject

/**
 Create a WLTriggerCallback that wraps the given block
 */
+ (id<WLTriggerCallback>)       createTriggerCallback:       (void (^)(id<WLDeviceContext> deviceContext)) callbackBlock;

/**
 Create a WLGeoCallback that wraps the given block
 */
+ (id<WLGeoCallback>)           createGeoCallback:           (void (^)(WLGeoPosition* pos))                callbackBlock;

/**
 Create a WLWifiConnectedCallback that wraps the given block
 */
+ (id<WLWifiConnectedCallback>) createWifiConnectedCallback: (void (^)(WLWifiAccessPoint* connectedAccessPoint, NSNumber* signalStrength)) callbackBlock;

/**
 Create a WLGeoFailureCallback that wraps the given block
 */
+ (id<WLGeoFailureCallback>)    createGeoFailureCallback:    (void (^)(WLGeoError* error))                 callbackBlock;

/**
 Create a WLWifiFailureCallback that wraps the given block
 */
+ (id<WLWifiFailureCallback>)   createWifiFailureCallback:   (void (^)(WLWifiError* error))                callbackBlock;

@end
