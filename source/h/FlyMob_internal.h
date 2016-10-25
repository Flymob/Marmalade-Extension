/*
 * Internal header for the FlyMob extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef FLYMOB_INTERNAL_H
#define FLYMOB_INTERNAL_H

#include "s3eTypes.h"
#include "FlyMob.h"
#include "FlyMob_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult FlyMobInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult FlyMobInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void FlyMobTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void FlyMobTerminate_platform();
void s3eFlyMobInterstitialInitialize_platform(const int zoneID);

void s3eFlyMobInterstitialLoad_platform();

void s3eFlyMobInterstitialShow_platform();

bool s3eFlyMobInterstitialIsReady_platform();

void s3eFlyMobRewardedVideoInitialize_platform(const int zoneID);

void s3eFlyMobRewardedVideoLoad_platform();

void s3eFlyMobRewardedVideoShow_platform();

bool s3eFlyMobRewardedVideoIsReady_platform();

void s3eFlyMobSDKSetDebugMode_platform(bool isDebug);

bool s3eFlyMobSDKIsDebugMode_platform();

void s3eFlyMobSDKSetCoppa_platform(bool isCoppa);

bool s3eFlyMobSDKIsCoppa_platform();

void s3eFlyMobSDKSetDnt_platform(bool isDnt);

bool s3eFlyMobSDKIsDnt_platform();

void s3eFlyMobSDKSetTesting_platform(bool isTesting);

bool s3eFlyMobSDKIsTesting_platform();


#endif /* !FLYMOB_INTERNAL_H */