//
//  MyHybridBridge.h
//  HybridScreensDemoProjectHybridScreensAppIphone
//
//  Created by Anton Aleksandrov on 17/12/13.
//
//

#import <Cordova/CDV.h>

@interface MyHybridBridge : CDVPlugin

-(void)reportEvent:(NSDictionary*)eventData;

@end
