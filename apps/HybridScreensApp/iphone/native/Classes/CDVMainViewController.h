/*
 * Licensed Materials - Property of IBM
 * 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */


//
//  CDVMainViewController.h
//  cccTestCordovaIphone
//


#import "MainViewController.h"

@interface CDVMainViewController : MainViewController <UIWebViewDelegate>{
    IBOutlet UISegmentedControl *segmentedControl;
    IBOutlet UINavigationBar *navigationBar;
}

-(IBAction)segmentedClicked:(UISegmentedControl*)sender;
-(IBAction)navigationBarLeftButtonClicked:(UIBarButtonItem*)sender;

-(void)updateNavBarLeftButton:(NSString*)title;
-(void)updateNavBarTitle:(NSString*)title;

@end
