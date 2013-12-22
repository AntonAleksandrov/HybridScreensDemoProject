/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

//
//  NativePage.h
//
//  Created by Benny Weingarten on 9/28/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

@interface NativePage : CDVPlugin {
	@private
    NSMutableDictionary *controllerObjects;
}

@property (nonatomic, retain) NSMutableDictionary *controllerObjects;

+(void)showWebView:(NSDictionary *)data;
@end
