/*
java implementation of the FlyMob extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */

import com.ideaworks3d.marmalade.LoaderAPI;
import android.content.Context;

import com.flymob.sdk.common.ads.FailResponse;
import com.flymob.sdk.common.ads.interstitial.FlyMobInterstitial;
import com.flymob.sdk.common.ads.interstitial.IFlyMobInterstitialListener;
import com.flymob.sdk.common.ads.video.FlyMobRewardedVideo;
import com.flymob.sdk.common.ads.video.IFlyMobRewardedVideoListener;

import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;

class FlyMob {
    FlyMobInterstitial mFlyMobInterstitial;
    FlyMobRewardedVideo mFlyMobRewardedVideo;

    public native void nativeCallbackInterstitial(int callbackIndex);
    public native void nativeCallbackRewardedVideo(int callbackIndex);

    private enum FlyMobInterstitialCallback
    {
        S3E_FLYMOB_INTERSTITIAL_DID_LOAD,
        S3E_FLYMOB_INTERSTITIAL_DID_FAIL,
        S3E_FLYMOB_INTERSTITIAL_DID_SHOW,
        S3E_FLYMOB_INTERSTITIAL_DID_CLICK,
        S3E_FLYMOB_INTERSTITIAL_DID_CLOSE,
        S3E_FLYMOB_INTERSTITIAL_DID_EXPIRE,
        S3E_FLYMOB_INTERSTITIAL_MAX
    };

    private enum FlyMobRewardedVideoCallback
    {
        S3E_FLYMOB_REWARDED_VIDEO_DID_LOAD,
        S3E_FLYMOB_REWARDED_VIDEO_DID_FAIL,
        S3E_FLYMOB_REWARDED_VIDEO_DID_SHOW,
        S3E_FLYMOB_REWARDED_VIDEO_DID_COMPLETE,
        S3E_FLYMOB_REWARDED_VIDEO_DID_START,
        S3E_FLYMOB_REWARDED_VIDEO_DID_CLOSE,
        S3E_FLYMOB_REWARDED_VIDEO_DID_EXPIRE,
        S3E_FLYMOB_REWARDED_VIDEO_MAX
    };

    public void s3eFlyMobInterstitialInitialize(int zoneID) {
        Context context = (Context) LoaderActivity.m_Activity;
        if (context != null) {
            mFlyMobInterstitial = new FlyMobInterstitial(context, zoneID);
            mFlyMobInterstitial.addListener(new IFlyMobInterstitialListener() {
                @Override
                public void loaded(FlyMobInterstitial interstitial) {
                    nativeCallbackInterstitial(FlyMobInterstitialCallback.S3E_FLYMOB_INTERSTITIAL_DID_LOAD.ordinal());
                }

                @Override
                public void failed(FlyMobInterstitial interstitial, FailResponse response) {
                    nativeCallbackInterstitial(FlyMobInterstitialCallback.S3E_FLYMOB_INTERSTITIAL_DID_FAIL.ordinal());
                }

                @Override
                public void shown(FlyMobInterstitial interstitial) {
                    nativeCallbackInterstitial(FlyMobInterstitialCallback.S3E_FLYMOB_INTERSTITIAL_DID_SHOW.ordinal());
                }

                @Override
                public void clicked(FlyMobInterstitial interstitial) {
                    nativeCallbackInterstitial(FlyMobInterstitialCallback.S3E_FLYMOB_INTERSTITIAL_DID_CLICK.ordinal());
                }

                @Override
                public void closed(FlyMobInterstitial interstitial) {
                    nativeCallbackInterstitial(FlyMobInterstitialCallback.S3E_FLYMOB_INTERSTITIAL_DID_CLOSE.ordinal());
                }

                @Override
                public void expired(FlyMobInterstitial interstitial) {
                    nativeCallbackInterstitial(FlyMobInterstitialCallback.S3E_FLYMOB_INTERSTITIAL_DID_EXPIRE.ordinal());
                }
            });
        }
    }

    public void s3eFlyMobInterstitialLoad() {
        if (mFlyMobInterstitial != null) {
            mFlyMobInterstitial.load();
        }
    }

    public void s3eFlyMobInterstitialShow() {
        if (mFlyMobInterstitial != null) {
            mFlyMobInterstitial.show();
        }
    }

    public boolean s3eFlyMobInterstitialIsReady() {
        if (mFlyMobInterstitial != null) {
            return mFlyMobInterstitial.isLoaded();
        }
        return false;
    }

    public void s3eFlyMobRewardedVideoInitialize(int zoneID) {
        Context context = (Context) LoaderActivity.m_Activity;
        if (context != null) {
            mFlyMobRewardedVideo = new FlyMobRewardedVideo(context, zoneID);

            mFlyMobRewardedVideo.addListener(new IFlyMobRewardedVideoListener() {
                @Override
                public void loaded(FlyMobRewardedVideo video) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_LOAD.ordinal());
                }

                @Override
                public void failed(FlyMobRewardedVideo video, FailResponse response) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_FAIL.ordinal());
                }

                @Override
                public void shown(FlyMobRewardedVideo video) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_SHOW.ordinal());
                }

                @Override
                public void closed(FlyMobRewardedVideo video) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_CLOSE.ordinal());
                }

                @Override
                public void started(FlyMobRewardedVideo video) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_START.ordinal());
                }

                @Override
                public void completed(FlyMobRewardedVideo video) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_COMPLETE.ordinal());
                }

                @Override
                public void expired(FlyMobRewardedVideo video) {
                    nativeCallbackRewardedVideo(FlyMobRewardedVideoCallback.S3E_FLYMOB_REWARDED_VIDEO_DID_EXPIRE.ordinal());
                }
            });
        }
    }

    public void s3eFlyMobRewardedVideoLoad() {
        if (mFlyMobRewardedVideo != null) {
            mFlyMobRewardedVideo.load();
        }
    }

    public void s3eFlyMobRewardedVideoShow() {
        if (mFlyMobRewardedVideo != null) {
            mFlyMobRewardedVideo.show();
        }
    }

    public boolean s3eFlyMobRewardedVideoIsReady() {
        if (mFlyMobRewardedVideo != null) {
            return mFlyMobRewardedVideo.isLoaded();
        }
        return false;
    }

    public void s3eFlyMobSDKSetDebugMode(boolean isDebug) {
        com.flymob.sdk.common.FlyMob.setDebugMode(isDebug);
    }

    public boolean s3eFlyMobSDKIsDebugMode() {
        return com.flymob.sdk.common.FlyMob.isDebugMode();
    }

    public void s3eFlyMobSDKSetCoppa(boolean isCoppa) {
        com.flymob.sdk.common.FlyMob.setCoppa(isCoppa);
    }

    public boolean s3eFlyMobSDKIsCoppa() {
        return com.flymob.sdk.common.FlyMob.isCoppa();
    }

    public void s3eFlyMobSDKSetDnt(boolean isDnt) {
        com.flymob.sdk.common.FlyMob.setDnt(isDnt);
    }

    public boolean s3eFlyMobSDKIsDnt() {
        return com.flymob.sdk.common.FlyMob.isDnt();
    }

    public void s3eFlyMobSDKSetTesting(boolean isTesting) {
        com.flymob.sdk.common.FlyMob.setTesting(isTesting);
    }

    public boolean s3eFlyMobSDKIsTesting() {
        return com.flymob.sdk.common.FlyMob.isTesting();
    }
}
