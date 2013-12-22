/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

//
//  WLCookieExtractor.h
//  Worklight SDK
//
//  Created by Benny Weingarten on 11/24/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * A class used to share cookies between the web code and native code. The class has no API methods. 
 * An object of this class must be passed as a parameter to wlInitWithDelegate:cookieExtractor:
 */
@interface WLCookieExtractor : NSObject {

}

-(id)initWithWebView:(UIWebView *)webview;
-(NSDictionary *)getCookies;


@end
