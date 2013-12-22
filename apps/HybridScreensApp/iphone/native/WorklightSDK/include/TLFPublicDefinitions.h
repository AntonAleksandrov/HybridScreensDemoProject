/*
* Licensed Materials - Property of IBM
* 5725-I43 (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
* US Government Users Restricted Rights - Use, duplication or
* disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
*/

#import <UIKit/UIKit.h>
// Screen changed event
#define kScreenChangedEventDefaultLevel kTLFMonitoringLevel1

@protocol TLFSavePrintScreenOperationDelegate <NSObject>
@optional
- (void)savePrintScreenOnTemporaryDirectoryOperationDidFinishSuccessfullyWithImageName:(NSString*)imageName;

@end

typedef enum {
	
	kTLFMonitoringLevelUnknown = -1,
	
	kTLFMonitoringLevel0 = 0,
	kTLFMonitoringLevel1 = 1,
	kTLFMonitoringLevel2 = 2,
	kTLFMonitoringLevel3 = 3,
	
	kTLFMonitoringLevelNotLog = kTLFMonitoringLevel0,
	
} kTLFMonitoringLevelType;

extern NSString* kTLFButtonClickEvent;
extern NSString* kTLFToggleButtonClickEvent;
extern NSString* kTLFSliderValueChangeEvent;
extern NSString* kTLFStepperValueChangeEvent;
extern NSString* kTLFSelectListValueChangeEvent;
extern NSString* kTLFDatePickerDateChangeEvent;
extern NSString* kTLFTextBoxTextChangeEvent;
extern NSString* kTLFScrollerScrollChangeEvent;
extern NSString* kTLFActionSheetButtonIndexEvent;
extern NSString* kTLFActionSheetShowEvent;
extern NSString* kTLFAlertviewButtonIndexEvent;
extern NSString* kTLFAlertViewShowEvent;
extern NSString* kTLFPrintscreenEvent;
extern NSString* kTLFCustomEventEvent;
extern NSString* kTLFExceptionEvent;
extern NSString* kTLFConnectionEvent; 
extern NSString* kTLFMobileStateEvent;

// The configurable items, needs to match with keys of "TLFResources.bundle/TLFConfigurableItems.plist" file.
#define kConfigurableItemLoggingLevel					@"LoggingLevel"
#define kConfigurableItemCachingLevel					@"CachingLevel"
#define kConfigurableItemCachedFileMaxBytesSize			@"CachedFileMaxBytesSize"
#define kConfigurableItemMaxLoggedElementsSize			@"MaxLoggedElementsSize"
#define kConfigurableItemHasToPersistLocalCache         @"HasToPersistLocalCache"
#define kConfigurableItemPostMessageLevelWifi			@"PostMessageLevelWiFi"
#define kConfigurableItemPostMessageLevelCellular		@"PostMessageLevelCellular"
#define kConfigurableItemPostMessageUrl					@"PostMessageUrl"
#define kConfigurableItemPostMessageTimeIntervals		@"PostMessageTimeIntervals"
#define kConfigurableItemPostMessageMaxBytesSize		@"PostMessageMaxBytesSize"
#define kConfigurableItemPostMessageMaxTimeToSendData	@"PostMessageMaxTimeToSendData"
#define kConfigurableItemPostMessageDelayTimeToSendData	@"PostMessageDelayTimeToSendData"
#define kConfigurableItemPostMessageSecondLevel			@"PostMessageSecondLevel"
#define kConfigurableItemDoPostOnIntervals				@"DoPostOnIntervals"
#define kConfigurableItemDoPostAppIsLaunched			@"DoPostAppIsLaunched"
#define kConfigurableItemDoPostAppGoesToBackground		@"DoPostAppGoesToBackground"
#define kConfigurableItemDoPostAppComesFromBackground	@"DoPostAppComesFromBackground"
#define kConfigurableItemKillSwitchEnabled				@"KillSwitchEnabled"
#define kConfigurableItemKillSwitchUrl					@"KillSwitchUrl"
#define kConfigurableItemKillSwitchTimeout				@"KillSwitchTimeout"
#define kConfigurableItemKillSwitchMaxNumberOfTries		@"KillSwitchMaxNumberOfTries"
#define kConfigurableItemManualPostEnabled              @"ManualPostEnabled"
#define kConfigurableItemMaxNumberOfPostsPerActivation	@"MaxNumberOfPostsPerActivation"
#define kConfigurableItemMaxNumberOfBytesPerActivation	@"MaxNumberOfBytesPerActivation"
#define kConfigurableItemDelayTimeOfTLFInitialization	@"DelayTimeOfTLFInitialization"
#define kConfigurableItemMemoryWarningMaxMemoryBytesSize @"MemoryWarningMaxMemoryBytesSize"
#define kConfigurableItemDoPostOnScreenChange			@"DoPostOnScreenChange"
#define kConfigurableItemScreenTimeNeededToPost			@"ScreenTimeNeededToPost"
#define kConfigurableItemTimeIntervalBetweenSnapshots	@"TimeIntervalBetweenSnapshots"
#define kConfigurableItemPostMessageTimeout             @"PostMessageTimeout"
#define kConfigurableItemMaxStringsLength				@"MaxStringsLength"
#define kConfigurableItemDisableAutoInstrumentation		@"DisableAutoInstrumentation"
#define kConfigurableItemCompressPostMessage            @"CompressPostMessage"
#define kConfigurableItemPercentOfScreenshotsSize       @"PercentOfScreenshotsSize"
#define kConfigurableItemDynamicConfigurationEnabled    @"DynamicConfigurationEnabled"
#define kConfigurableItemDisableTLFFrameworkFlush       @"DisableTLFFrameworkFlush"
#define kConfigurableItemScreenshotFormat               @"ScreenshotFormat"
#define kConfigurableItemJavaScriptToObjectiveCProtocol @"JavaScriptToObjectiveCProtocol"
#define kConfigurableItemJavaScriptToObjectiveCProtocolCode @"JavaScriptToObjectiveCProtocolCode"
#define kConfigurableItemFilterMessageTypes @"FilterMessageTypes"
#define kConfigurableItemMessageTypesToBeFiltered @"MessageTypesToBeFiltered"
#define kConfigurableItemSessionTimeout  @"SessionTimeout"
#define kConfigurableItemAddMessageTypeHeader  @"AddMessageTypeHeader"
#define kConfigurableItemMessageTypeHeader  @"MessageTypeHeader"

@protocol TLFLibDelegate <NSObject>
@optional
/**
 After set a delegate to your TLFApplication implement this callback to generate your custom Session ID
 */
- (NSString*)sessionIdGeneration;

@end

@protocol TLFCustomControlDelegate <NSObject>
@optional
- (BOOL)isTLFCustomControlHidden;
- (NSInteger)tagTLFCustomControl;
- (id)parentTLFCustomControl;
- (CGRect)frameTLFCustomControl;
- (UIColor*)colorTLFCustomControl;
- (UIColor*)backgroundColorTLFCustomControl;

- (NSString*)textTLFCustomControl;
- (BOOL)isTLFCustomControlTextHidden;
- (CGRect)textFrameTLFCustomControl;
- (UIColor*)textTLFCustomControlColor;
- (UIColor*)textTLFCustomControlBackgroundColor;

- (UIImage*)imageTLFCustomControl;
- (BOOL)isTLFCustomControlImageHidden;
- (CGRect)imageFrameTLFCustomControl;
- (UIColor*)imageOpacityTLFCustomControl;
- (UIColor*)imageBackgroundColorTLFCustomControl;

//- (UIImage*)controlBackgroundImageTLFCustomControl;
@end

@protocol TLFCustomControlDelegateX <NSObject>
@optional
- (NSArray*) imageViewsTLFCustomControl;
- (NSArray*) controlsTLFCustomControl;
@end
