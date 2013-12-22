/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

//
//  WLProcedureInvocationResult.h
//  Worklight SDK
//
//  Created by Benjamin Weingarten on 6/29/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * Contains the result of invoking a backend service, including statuses and data items retrieved by the adapter 
 * function from the server.
 */
@interface WLProcedureInvocationResult : NSObject {

		
	@private 
	NSMutableDictionary *response;
	NSDictionary *result;
	NSMutableArray *recordNames;
	NSArray *errors;
	NSArray *warnings;
	NSArray *info;
	NSNumber *success;
}

// Returns an NSDictionary which represents the JSON response returned by the Worklight Server.
@property (nonatomic, readonly) NSDictionary *response;

-(id)initWithInvocationResultDictionary:(NSDictionary *)theResult;

// Returns YES if the invocation was successful, and NO otherwise
-(BOOL)isSuccessful;

// Returns an NSArray of applicative error messages collected by the Server during the procedure invocation.
-(NSArray *)procedureInvocationErrors;

-(NSArray *)warnMessages;
-(NSArray *)infoMessages;
@end
