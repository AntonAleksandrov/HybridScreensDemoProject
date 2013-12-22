/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Cordova/CDVPlugin.h>
#import "WLAnalytics.h"

@interface AnalyticsConfigurator : CDVPlugin{
}

- (void)send:(CDVInvokedUrlCommand*)command;
- (void)enable:(CDVInvokedUrlCommand*)command;
- (void)disable:(CDVInvokedUrlCommand*)command;
- (void)configureTealeaf:(CDVInvokedUrlCommand*)command;
- (void)resetConfig:(CDVInvokedUrlCommand*)command;

@end
