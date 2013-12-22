/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#import <UIKit/UIKit.h>
#import "TLFPublicDefinitions.h"
#import "TLFApplication.h"
#import "TLFCustomEvent.h"

int main(int argc, char *argv[]) {

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

    NSString *appClass = nil;

    appClass = NSStringFromClass(NSClassFromString(@"TLFApplication"));

    int retVal = UIApplicationMain(argc, argv, appClass, @"MyAppDelegate");
    [pool release];
    return retVal;
}
