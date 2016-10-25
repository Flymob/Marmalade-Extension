/*
Generic implementation of the FlyMob extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "FlyMob_internal.h"
s3eResult FlyMobInit()
{
    //Add any generic initialisation code here
    return FlyMobInit_platform();
}

void FlyMobTerminate()
{
    //Add any generic termination code here
    FlyMobTerminate_platform();
}

void s3eFlyMobInterstitialInitialize(const int zoneID)
{
	s3eFlyMobInterstitialInitialize_platform(zoneID);
}

void s3eFlyMobInterstitialLoad()
{
	s3eFlyMobInterstitialLoad_platform();
}

void s3eFlyMobInterstitialShow()
{
	s3eFlyMobInterstitialShow_platform();
}

bool s3eFlyMobInterstitialIsReady()
{
	return s3eFlyMobInterstitialIsReady_platform();
}

void s3eFlyMobRewardedVideoInitialize(const int zoneID)
{
	s3eFlyMobRewardedVideoInitialize_platform(zoneID);
}

void s3eFlyMobRewardedVideoLoad()
{
	s3eFlyMobRewardedVideoLoad_platform();
}

void s3eFlyMobRewardedVideoShow()
{
	s3eFlyMobRewardedVideoShow_platform();
}

bool s3eFlyMobRewardedVideoIsReady()
{
	return s3eFlyMobRewardedVideoIsReady_platform();
}

void s3eFlyMobSDKSetDebugMode(bool isDebug)
{
	s3eFlyMobSDKSetDebugMode_platform(isDebug);
}

bool s3eFlyMobSDKIsDebugMode()
{
	return s3eFlyMobSDKIsDebugMode_platform();
}

void s3eFlyMobSDKSetCoppa(bool isCoppa)
{
	s3eFlyMobSDKSetCoppa_platform(isCoppa);
}

bool s3eFlyMobSDKIsCoppa()
{
	return s3eFlyMobSDKIsCoppa_platform();
}

void s3eFlyMobSDKSetDnt(bool isDnt)
{
	s3eFlyMobSDKSetDnt_platform(isDnt);
}

bool s3eFlyMobSDKIsDnt()
{
	return s3eFlyMobSDKIsDnt_platform();
}

void s3eFlyMobSDKSetTesting(bool isTesting)
{
	s3eFlyMobSDKSetTesting_platform(isTesting);
}

bool s3eFlyMobSDKIsTesting()
{
	return s3eFlyMobSDKIsTesting_platform();
}
