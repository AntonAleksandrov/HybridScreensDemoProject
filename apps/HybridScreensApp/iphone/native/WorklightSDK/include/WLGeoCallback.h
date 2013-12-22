/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoCallback_H_
#import <Foundation/Foundation.h>
#import "AcquisitionCallback.h"
@class WLGeoPosition;

/**
 * A callback for when a Geo position is acquired.
 */
@protocol WLGeoCallback <AcquisitionCallback> 

/**
      * The method will be executed when a Geo position is acquired.
      * @param pos The Geo position acquired.
      */
- (void) execute : (WLGeoPosition*) pos ;

@end

