/*
 *  Licensed Materials - Property of IBM
 *  5725-I43 (C) Copyright IBM Corp. 2011, 2013. All Rights Reserved.
 *  US Government Users Restricted Rights - Use, duplication or
 *  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  WLChallengeHandler.h
//  WorklightStaticLibProject
//
//  Created by Ishai Borovoy on 9/13/12.
//

#import "BaseChallengeHandler.h"
#import "WLFailResponse.h"

@interface WLChallengeHandler : BaseChallengeHandler
-(void) submitChallengeAnswer: (NSDictionary *)answer;
    -(void) handleSuccess: (NSDictionary *)success;
    -(void) handleFailure: (NSDictionary *)failure;
    -(void) handleChallenge: (NSDictionary *)challenge;
@end
