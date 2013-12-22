/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#define _WLGeoError_H_
#import "AbstractAcquisitionError.h"

typedef enum {
	PERMISSION_DENIED, 
	POSITION_UNAVAILABLE, 
	TIMEOUT
} WLGeoErrorCodes;


/**
 * An error that occurred during Geo acquisition
 */
@interface WLGeoError : AbstractAcquisitionError {
	@private
	WLGeoErrorCodes errorCode;
}



/**
      * @param errorCode The error code
      * @param message The error's message
      */
- (id)initWithErrorCode:(WLGeoErrorCodes)errorCode message:(NSString*)message;
/**
	 * @return the error code
	 */
- (WLGeoErrorCodes) getErrorCode  ;
- (NSString*) description  ;

@end

