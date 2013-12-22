/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

//
//  WLCordovaAppDelegate.h
//  Worklight SDK
//
//  Created by Benny Weingarten on 8/16/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CDVAppDelegate.h"


@class Push;

@interface WLCordovaAppDelegate : CDVAppDelegate < UIApplicationDelegate, UIAlertViewDelegate > {
	Push *push;
	BOOL applicationPageLoaded;
	BOOL isIPAD;
    
}

extern NSString * const SKIN_LOADER_FILE_NAME;
extern NSString * const BUILD_TIME_FILE_NAME;
extern NSString * const APP_PATH_FILE_NAME;
extern NSString * const CHECKSUM_JS_FILE_NAME;
extern NSString * const CHECKSUM_KEY_NAME; // key for reading the checksum from checksum.js
extern NSString * const DEFAULT_SKIN_NAME;
extern NSString * const SAVED_CHECKSUM_KEY_NAME; // key for NSUserDefaults

@property (retain, nonatomic) Push *push;
@property (readonly) BOOL isIPAD;
@property (nonatomic, copy) NSString *appInitErrorString;


// Class public methods
+ (void) setAppChecksum:(NSString *)checksum;
+ (NSString *)readPrePackagedChecksum;
+ (long long) getFreeSpaceOnDevice;
+ (NSString*) wwwFolderName;
+ (NSString*) startPage;
+ (NSString*) pathForResource:(NSString*)resourcepath;

// This method can be used instead of application:didLaunchingWithOptions for application
// initialization IF some other delegate superclass is receiving the application:didLaunchingWithOptions
// message to do some pre-requisite initialization (such as a secure container authorization).
// The superclass will return to iOS, and then at some later point (such as when secure container
// authorization is successful) should invoke this method.
- (BOOL)appStart:(UIApplication *)application withOptions:(NSDictionary *)launchOptions;

@end

