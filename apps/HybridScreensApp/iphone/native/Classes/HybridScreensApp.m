//
//  MyAppDelegate.m
//  HybridScreensApp
//
//

#import "HybridScreensApp.h"


@implementation MyAppDelegate

- (id) init
{	
    /*
     * If you need to do any extra app-specific initialization, you can do it here.
     **/
    return [super init];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions 
{
    BOOL ret = [super application:application didFinishLaunchingWithOptions:launchOptions];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(didFinishWLNativeInit:) name:@"didFinishWLNativeInit" object:nil];
    
    return ret;
}

/**
 * This is main kick off after the app inits, the views and Settings are setup here. 
 */
-(void) didFinishWLNativeInit:(NSNotification *)notification {

    /*
     * If you need to do any extra app-specific initialization, you can do it here.
     * Note: At this point webview is available.
     **/
}

/**
* These functions handle moving to background and foreground and invoke the appropriate JavaScript functions in the UIWebView.
*/
- (void)applicationDidEnterBackground:(UIApplication *)application
{
	NSString *result = [super.viewController.webView stringByEvaluatingJavaScriptFromString:@"WL.App.BackgroundHandler.onAppEnteringBackground();"]; 
	if([result isEqualToString:@"hideView"]){
		[[self.viewController view] setHidden:YES];
	}
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
	NSString *result = [super.viewController.webView stringByEvaluatingJavaScriptFromString:@"WL.App.BackgroundHandler.onAppEnteringForeground();"];
	if([result isEqualToString:@"hideViewToForeground"]){
		[[self.viewController view] setHidden:NO];
	}
}

- (void)applicationDidBecomeActive:(UIApplication *)application 
{
	[super applicationDidBecomeActive:application];
    /*
     * If you need to do any extra app-specific stuff, you can do it here.
     **/
}

- (void)dealloc
{
	[ super dealloc ];
}

@end