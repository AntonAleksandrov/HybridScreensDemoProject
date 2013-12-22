//
//  MyHybridBridge.m
//  HybridScreensDemoProjectHybridScreensAppIphone
//
//  Created by Anton Aleksandrov on 17/12/13.
//
//

#import "MyHybridBridge.h"
#import "CDVMainViewController.h"

@interface MyHybridBridge()

@property (nonatomic, retain) NSString *listenerCallbackId;

@end

@implementation MyHybridBridge

-(void)ACTION_BIND_LISTENER:(CDVInvokedUrlCommand*) command{
    NSLog(@"ACTION_BIND_LISTENER");
    
    self.listenerCallbackId = command.callbackId;
    
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    [pluginResult setKeepCallbackAsBool:true];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void)ACTION_SET_NAVBAR_TITLE:(CDVInvokedUrlCommand*) command{
    NSLog(@"ACTION_SET_NAVBAR_TITLE");
    CDVPluginResult *pluginResult;

    if (command.arguments.count == 1){
        NSString *title = [command.arguments objectAtIndex:0];
        if ([title isKindOfClass:[NSNull class]]) title = nil;
        CDVMainViewController *viewController = (CDVMainViewController*)self.viewController;
        [viewController updateNavBarTitle:title];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Invalid number of parameters"];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void)ACTION_UPDATE_NAVBAR_LEFT_BUTTON:(CDVInvokedUrlCommand*)command{
    NSLog(@"ACTION_UPDATE_NAVBAR_LEFT_BUTTON");
    CDVPluginResult *pluginResult;
    
    if (command.arguments.count == 1){
        NSString *title = [command.arguments objectAtIndex:0];
        if ([title isKindOfClass:[NSNull class]]) title = nil;
        CDVMainViewController *viewController = (CDVMainViewController*)self.viewController;
        [viewController updateNavBarLeftButton:title];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Invalid number of parameters"];
    }
    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

-(void)reportEvent:(NSDictionary*)eventData{
    NSLog(@"reportEvent");
    CDVPluginResult *pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:eventData];
    [pluginResult setKeepCallbackAsBool:true];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:self.listenerCallbackId];
}

@end
