/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

//
//  WLFailResponse.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 6/17/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WLResponse.h"

typedef enum {
    WLErrorCodeUnexpectedError,
    WLErrorCodeUnresponsiveHost,
    WLErrorCodeRequestTimeout,
    WLErrorCodeProcedureError,
	WLErrorCodeApplicationVersionDenied,
	WLErrorCodeApplicationVersionNotify
} WLErrorCode;

/*
 * Derived from WLResponse, containing error codes and messages in addition to the status in WLResponse. 
 * Contains the original response data object from the server as well.
 */
@interface WLFailResponse : WLResponse {
	WLErrorCode errorCode;
	NSString *errorMsg;
	
}

// The possible errors are described in the WLErrorCode section.
@property (nonatomic) WLErrorCode errorCode;
// An error message for the developer, which is not necessarily suitable for displaying to the end user.
@property (nonatomic, retain) NSString *errorMsg;

//-(id)initWithRequest:(ASIHTTPRequest *) request;
+(NSString *) getErrorMessageFromCode: (WLErrorCode) code;
+(NSString *) getErrorMessageFromJSON: (NSDictionary *) jsonResponse;
+(WLErrorCode) getWLErrorCodeFromJSON: (NSDictionary *) jsonResponse;



@end
