/*
 * iphone-specific implementation of the FlyMob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "s3eEdk.h"
#include "FlyMob_internal.h"

#include <UIKit/UIKit.h>
#import "FlyMobSDK.h"

s3eResult FlyMobInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void FlyMobTerminate_platform()
{ 
}

//
// Interstitial
//

@interface MarmaladeFlyMobIOSInterstitialDelegate : NSObject <FlyMobInterstitialDelegate>

@end

@implementation MarmaladeFlyMobIOSInterstitialDelegate

-(void)interstitialDidLoadAd:(FlyMobInterstitial *)interstitial
{
	s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_INTERSTITIAL_DID_LOAD);
}

-(void)interstitialDidFailToLoadAd:(FlyMobInterstitial *)interstitial error:(NSError *)error
{
	s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_INTERSTITIAL_DID_FAIL);
}

-(void)interstitialDidShow:(FlyMobInterstitial *)interstitial
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_INTERSTITIAL_DID_SHOW);
}

-(void)interstitialDidClick:(FlyMobInterstitial *)interstitial
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_INTERSTITIAL_DID_CLICK);
}

-(void)interstitialDidClose:(FlyMobInterstitial *)interstitial
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_INTERSTITIAL_DID_CLOSE);
}

-(void)interstitialDidExpire:(FlyMobInterstitial *)interstitial
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_INTERSTITIAL_DID_EXPIRE);
}

@end

FlyMobInterstitial *interstitial = nil;
MarmaladeFlyMobIOSInterstitialDelegate *interstitialDelegate = nil;

void s3eFlyMobInterstitialInitialize_platform(const int zoneID)
{
	interstitial = [FlyMobInterstitial interstitialWithZoneID:zoneID];

	interstitialDelegate = [MarmaladeFlyMobIOSInterstitialDelegate new];

    interstitial.delegate = interstitialDelegate;
}

void s3eFlyMobInterstitialLoad_platform()
{
	if (interstitial)
	{
		[interstitial loadAd];
	}
}

void s3eFlyMobInterstitialShow_platform()
{
	if (interstitial.isReady)
	{
		[interstitial showFromViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
	}
}

bool s3eFlyMobInterstitialIsReady_platform()
{
    return interstitial.isReady;
}

//
// Rewarded Video
//

@interface MarmaladeFlyMobIOSRewardedVideoDelegate : NSObject <FlyMobRewardedVideoDelegate>

@end

@implementation MarmaladeFlyMobIOSRewardedVideoDelegate

-(void)rewardedVideoDidLoadAd:(FlyMobRewardedVideo *)rewardedVideo
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_LOAD);
}

-(void)rewardedVideoDidFailToLoadAd:(FlyMobRewardedVideo *)rewardedVideo error:(NSError *)error
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_FAIL);
}

-(void)rewardedVideoDidShow:(FlyMobRewardedVideo *)rewardedVideo
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_SHOW);
}

-(void)rewardedVideoDidComplete:(FlyMobRewardedVideo *)rewardedVideo
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_COMPLETE);
}

-(void)rewardedVideoDidStart:(FlyMobRewardedVideo *)rewardedVideo
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_START);
}

-(void)rewardedVideoDidClose:(FlyMobRewardedVideo *)rewardedVideo
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_CLOSE);
}

-(void)rewardedVideoDidExpire:(FlyMobRewardedVideo *)rewardedVideo
{
    s3eEdkCallbacksEnqueue(S3E_EXT_FLYMOB_HASH, S3E_FLYMOB_REWARDED_VIDEO_DID_EXPIRE);
}

@end


FlyMobRewardedVideo *rewardedVideo = nil;
MarmaladeFlyMobIOSRewardedVideoDelegate *rewardedVideoDelegate = nil;

void s3eFlyMobRewardedVideoInitialize_platform(const int zoneID)
{
	rewardedVideo = [FlyMobRewardedVideo rewardedVideoWithZoneID:zoneID];

	rewardedVideoDelegate = [MarmaladeFlyMobIOSRewardedVideoDelegate new];

    rewardedVideo.delegate = rewardedVideoDelegate;
}

void s3eFlyMobRewardedVideoLoad_platform()
{
	if (rewardedVideo)
	{
		[rewardedVideo loadAd];
	}
}

void s3eFlyMobRewardedVideoShow_platform()
{
	if (rewardedVideo.isReady)
	{
		[rewardedVideo showFromViewController:[UIApplication sharedApplication].keyWindow.rootViewController];
	}
}

bool s3eFlyMobRewardedVideoIsReady_platform()
{
    return rewardedVideo.isReady;
}

//
// Configuration
//

void s3eFlyMobSDKSetDebugMode_platform(bool isDebug)
{
	// Do nothing
}

bool s3eFlyMobSDKIsDebugMode_platform()
{
    return false;
}

void s3eFlyMobSDKSetCoppa_platform(bool isCoppa)
{
	[FLYConfiguration sharedInstance].coppa = isCoppa;
}

bool s3eFlyMobSDKIsCoppa_platform()
{
    return [FLYConfiguration sharedInstance].coppa;
}

void s3eFlyMobSDKSetDnt_platform(bool isDnt)
{
	[FLYConfiguration sharedInstance].dnt = isDnt;
}

bool s3eFlyMobSDKIsDnt_platform()
{
    return [FLYConfiguration sharedInstance].dnt;
}

void s3eFlyMobSDKSetTesting_platform(bool isTesting)
{
	[FLYConfiguration sharedInstance].testing = isTesting;
}

bool s3eFlyMobSDKIsTesting_platform()
{
    return [FLYConfiguration sharedInstance].testing;
}
