/*
 * Licensed Materials - Property of IBM
 * 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  CDVMainViewController.m
//  cccTestCordovaIphone
//
//

#import "CDVMainViewController.h"
#import "MyHybridBridge.h"

BOOL alreadyRun = NO;

@implementation CDVMainViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}
#pragma mark - Custom actions for segmented control
-(IBAction)segmentedClicked:(UISegmentedControl*)sender{
    NSString *selectedIndex = [NSString stringWithFormat:@"%d", [sender selectedSegmentIndex] + 1];
    NSLog(@"segmentedClicked, index :: %@", selectedIndex);
    
    MyHybridBridge *bridge = [self.pluginObjects objectForKey:@"MyHybridBridge"];
    NSDictionary *eventData = [NSDictionary dictionaryWithObjectsAndKeys:
                           @"segmentedClick", @"eventType",
                           selectedIndex, @"pageIndex",
                           nil];
    [bridge reportEvent:eventData];
}

-(void)updateNavBarTitle:(NSString*)title{
    NSLog(@"updateNavBarTitle :: title :: %@", title);
    navigationBar.topItem.title = title;
}

-(IBAction)navigationBarLeftButtonClicked:(UIBarButtonItem*)sender{
    NSLog(@"navigationBarLeftButtonClicked");
    [segmentedControl setSelectedSegmentIndex:0];
    
    MyHybridBridge *bridge = [self.pluginObjects objectForKey:@"MyHybridBridge"];
    NSDictionary *eventData = [NSDictionary dictionaryWithObjectsAndKeys:
                           @"navBarLeftButtonClicked", @"eventType",
                           nil];
    [bridge reportEvent:eventData];
}

-(void)updateNavBarLeftButton:(NSString*)title{
    NSLog(@"updateNavBarLeftButton :: title :: %@", title);
    navigationBar.topItem.leftBarButtonItem.title = title;
    navigationBar.topItem.leftBarButtonItem.enabled = (title != nil);
}

#pragma mark - View lifecycle
-(void)viewWillAppear:(BOOL)animated{
    CGRect viewBounds = self.view.bounds;
    CGRect webViewBound = CGRectMake(viewBounds.origin.x,
                                     viewBounds.origin.y + 100,
                                     viewBounds.size.width,
                                     viewBounds.size.height - 100);

    self.webView.frame = webViewBound;
    self.webView.backgroundColor = [UIColor clearColor];
    [super viewWillAppear:animated];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return [super shouldAutorotateToInterfaceOrientation:interfaceOrientation];
}

#pragma mark - WebView Delegate

/**
 * Called when the UIWebView finishes loading.  This stops the activity view and closes the imageview.
 */
- (void)webViewDidFinishLoad:(UIWebView *)theWebView 
{
	return [ super webViewDidFinishLoad:theWebView ];
}

- (void)webViewDidStartLoad:(UIWebView *)theWebView 
{
	return [ super webViewDidStartLoad:theWebView ];
}

/**
 * Fail Loading With Error
 * Error - If the web page failed to load display an error with the reason.
 */
- (void)webView:(UIWebView *)theWebView didFailLoadWithError:(NSError *)error 
{
	return [ super webView:theWebView didFailLoadWithError:error ];
}

/**
 * Start Loading Request
 * This is where most of the magic happens... We take the request(s) and process the response.
 * From here we can redirect links and other protocols to different internal methods.
 */
- (BOOL)webView:(UIWebView *)theWebView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
{
	return [ super webView:theWebView shouldStartLoadWithRequest:request navigationType:navigationType ];
}


/* Comment out the block below to over-ride */
/*
 #pragma mark - CDVCommandDelegate implementation
 
 - (id) getCommandInstance:(NSString*)className
 {
 return [super getCommandInstance:className];
 }
 
 - (void) registerPlugin:(CDVPlugin*)plugin withClassName:(NSString*)className
 {
 return [super registerPlugin:plugin withClassName:className];
 }
 */

@end
