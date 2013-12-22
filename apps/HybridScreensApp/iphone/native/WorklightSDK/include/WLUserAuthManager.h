/*
 * Licensed Materials - Property of IBM
 * 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  WLUserAuthManager.h
//  WorklightStaticLibProject
//

#import <Foundation/Foundation.h>

@interface WLUserAuthManager : NSObject

/**
 * Get the alias used for client user x509 certificate.  Entity is currently not used.
 */
+ (NSString *) getAlias:(NSString *)entity;

/**
 * Get certififacte Label as used when saved in keychain.
 */
+ (NSData *) getCertificateIdentifierFromEntity:(NSString *)provisioningEntity;

/**
 * Get private/public key Label as used when saved in keychain.
 */
+ (NSData *) getKeyIdentifier:(BOOL)isPublic withEntity:(NSString *)provisioningEntity;

/**
 * Checks to see if a user auth certificate exists in the keychain and that it is a valid certificate.
 */
+(BOOL) doesValidCertificateExist:(NSString *)provisioningEntity;

/**
 * Cleans User Cert Credential from KeyChain
 */
+ (BOOL) clearUserCertCredentialsFromKeyChain:(NSString *)provisioningEntity;

@end

