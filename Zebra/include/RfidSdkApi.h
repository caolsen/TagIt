/******************************************************************************
 *
 *       Copyright Zebra Technologies, Inc. 2014 - 2015
 *
 *       The copyright notice above does not evidence any
 *       actual or intended publication of such source code.
 *       The code contains Zebra Technologies
 *       Confidential Proprietary Information.
 *
 *
 *  Description:  RfidSdkApi.h
 *
 *  Notes:
 *
 ******************************************************************************/

#import "RfidSdkDefs.h"
#import "RfidSdkApiDelegate.h"
#import "RfidReportConfig.h"
#import "RfidAccessConfig.h"
#import "RfidAntennaConfiguration.h"
#import "RfidDynamicPowerConfig.h"
#import "RfidSingulationConfig.h"
#import "RfidTagReportConfig.h"
#import "RfidReaderVersionInfo.h"
#import "RfidReaderCapabilitiesInfo.h"
#import "RfidStartTriggerConfig.h"
#import "RfidStopTriggerConfig.h"
#import "RfidRegulatoryConfig.h"
#import "RfidPreFilter.h"

#ifndef __RFID_SDK_API__
#define __RFID_SDK_API__

@protocol srfidISdkApi <NSObject>

- (NSString*) srfidGetSdkVersion;

- (SRFID_RESULT) srfidSetDelegate:(id<srfidISdkApiDelegate>)delegate;
- (SRFID_RESULT) srfidSubsribeForEvents:(int)sdkEventsMask;
- (SRFID_RESULT) srfidUnsubsribeForEvents:(int)sdkEventsMask;

- (SRFID_RESULT) srfidSetOperationalMode:(int)operationalMode;

- (SRFID_RESULT) srfidGetAvailableReadersList:(NSMutableArray**)availableReadersList;
- (SRFID_RESULT) srfidGetActiveReadersList:(NSMutableArray**)activeReadersList;

- (SRFID_RESULT) srfidEstablishCommunicationSession:(int)readerID;
- (SRFID_RESULT) srfidTerminateCommunicationSession:(int)readerID;

- (SRFID_RESULT) srfidEnableAvailableReadersDetection:(BOOL)enable;
- (SRFID_RESULT) srfidEnableAutomaticSessionReestablishment:(BOOL)enable;

- (SRFID_RESULT) srfidStartRapidRead:(int)readerID aReportConfig:(srfidReportConfig*)reportConfig aAccessConfig:(srfidAccessConfig*)accessConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidStopRapidRead:(int)readerID aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidStartInventory:(int)readerID aMemoryBank:(SRFID_MEMORYBANK)memoryBankId aReportConfig:(srfidReportConfig*)reportConfig aAccessConfig:(srfidAccessConfig*)accessConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidStopInventory:(int)readerID aStatusMessage:(NSString**)statusMessage;


- (SRFID_RESULT) srfidGetSupportedLinkProfiles:(int)readerID aLinkProfilesList:(NSMutableArray**)linkProfilesList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetAntennaConfiguration:(int)readerID aAntennaConfiguration:(srfidAntennaConfiguration**)antennaConfiguration aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetAntennaConfiguration:(int)readerID aAntennaConfiguration:(srfidAntennaConfiguration*)antennaConfiguration aStatusMessage:(NSString**)statusMessage;

/* dynamic power optimization */
- (SRFID_RESULT) srfidGetDpoConfiguration:(int)readerID aDpoConfiguration:(srfidDynamicPowerConfig**)dpoConfiguration aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetDpoConfiguration:(int)readerID aDpoConfiguration:(srfidDynamicPowerConfig*)dpoConfiguration aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetSingulationConfiguration:(int)readerID aSingulationConfig:(srfidSingulationConfig**)singulationConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetSingulationConfiguration:(int)readerID aSingulationConfig:(srfidSingulationConfig*)singulationConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetTagReportConfiguration:(int)readerID aTagReportConfig:(srfidTagReportConfig**)reportConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetTagReportConfiguration:(int)readerID aTagReportConfig:(srfidTagReportConfig*)reportConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetReaderVersionInfo:(int)readerID aReaderVersionInfo:(srfidReaderVersionInfo**)readerVersionInfo aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetReaderCapabilitiesInfo:(int)readerID aReaderCapabilitiesInfo:(srfidReaderCapabilitiesInfo**)readerCapabilitiesInfo aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetStartTriggerConfiguration:(int)readerID aStartTriggeConfig:(srfidStartTriggerConfig**)triggerConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetStartTriggerConfiguration:(int)readerID aStartTriggeConfig:(srfidStartTriggerConfig*)triggerConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetStopTriggerConfiguration:(int)readerID aStopTriggeConfig:(srfidStopTriggerConfig**)triggerConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetStopTriggerConfiguration:(int)readerID aStopTriggeConfig:(srfidStopTriggerConfig*)triggerConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetSupportedRegions:(int)readerID aSupportedRegions:(NSMutableArray**)supportedRegionsList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidGetRegionInfo:(int)readerID aRegionCode:(NSString*)regionCode aSupportedChannels:(NSMutableArray**)supportedChannelsList aHoppingConfigurable:(BOOL*)hoppingConfigurable aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetRegulatoryConfig:(int)readerID aRegulatoryConfig:(srfidRegulatoryConfig**)regulatoryConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetRegulatoryConfig:(int)readerID aRegulatoryConfig:(srfidRegulatoryConfig*)regulatoryConfig aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidGetBeeperConfig:(int)readerID aBeeperConfig:(SRFID_BEEPERCONFIG*)beeperConfig aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetBeeperConfig:(int)readerID aBeeperConfig:(SRFID_BEEPERCONFIG)beeperConfig aStatusMessage:(NSString**)statusMessage;


- (SRFID_RESULT) srfidGetPreFilters:(int)readerID aPreFilters:(NSMutableArray**)filtersList aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidSetPreFilters:(int)readerID aPreFilters:(NSMutableArray*)filtersList aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidStartTagLocationing:(int)readerID aTagEpcId:(NSString*)epcID aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidStopTagLocationing:(int)readerID aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidSaveReaderConfiguration:(int)readerID aSaveCustomDefaults:(BOOL)saveCustomDefaults aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidRestoreReaderConfiguration:(int)readerID aRestoreFactoryDefaults:(BOOL)restoreFactoryDefaults aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidReadTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aLength:(short)length aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidWriteTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aOffset:(short)offset aData:(NSString*)data aPassword:(long)password aDoBlockWrite:(BOOL)blockWrite aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidKillTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aPassword:(long)password aStatusMessage:(NSString**)statusMessage;
- (SRFID_RESULT) srfidLockTag:(int)readerID aTagID:(NSString*)tagID aAccessTagData:(srfidTagData**)accessTagData aMemoryBank:(SRFID_MEMORYBANK)memoryBankID aAccessPermissions:(SRFID_ACCESSPERMISSION)accessPermissions aPassword:(long)password aStatusMessage:(NSString**)statusMessage;

- (SRFID_RESULT) srfidRequestBatteryStatus:(int)readerID;

@end


#endif /* __RFID_SDK_API__ */
