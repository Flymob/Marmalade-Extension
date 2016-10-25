/*
 * android-specific implementation of the FlyMob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "FlyMob_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_s3eFlyMobInterstitialInitialize;
static jmethodID g_s3eFlyMobInterstitialLoad;
static jmethodID g_s3eFlyMobInterstitialShow;
static jmethodID g_s3eFlyMobInterstitialIsReady;
static jmethodID g_s3eFlyMobRewardedVideoInitialize;
static jmethodID g_s3eFlyMobRewardedVideoLoad;
static jmethodID g_s3eFlyMobRewardedVideoShow;
static jmethodID g_s3eFlyMobRewardedVideoIsReady;
static jmethodID g_s3eFlyMobSDKSetDebugMode;
static jmethodID g_s3eFlyMobSDKIsDebugMode;
static jmethodID g_s3eFlyMobSDKSetCoppa;
static jmethodID g_s3eFlyMobSDKIsCoppa;
static jmethodID g_s3eFlyMobSDKSetDnt;
static jmethodID g_s3eFlyMobSDKIsDnt;
static jmethodID g_s3eFlyMobSDKSetTesting;
static jmethodID g_s3eFlyMobSDKIsTesting;

s3eResult FlyMobInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("FlyMob");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_s3eFlyMobInterstitialInitialize = env->GetMethodID(cls, "s3eFlyMobInterstitialInitialize", "(LFIXME;)V");
    if (!g_s3eFlyMobInterstitialInitialize)
        goto fail;

    g_s3eFlyMobInterstitialLoad = env->GetMethodID(cls, "s3eFlyMobInterstitialLoad", "()V");
    if (!g_s3eFlyMobInterstitialLoad)
        goto fail;

    g_s3eFlyMobInterstitialShow = env->GetMethodID(cls, "s3eFlyMobInterstitialShow", "()V");
    if (!g_s3eFlyMobInterstitialShow)
        goto fail;

    g_s3eFlyMobInterstitialIsReady = env->GetMethodID(cls, "s3eFlyMobInterstitialIsReady", "()Z");
    if (!g_s3eFlyMobInterstitialIsReady)
        goto fail;

    g_s3eFlyMobRewardedVideoInitialize = env->GetMethodID(cls, "s3eFlyMobRewardedVideoInitialize", "(LFIXME;)V");
    if (!g_s3eFlyMobRewardedVideoInitialize)
        goto fail;

    g_s3eFlyMobRewardedVideoLoad = env->GetMethodID(cls, "s3eFlyMobRewardedVideoLoad", "()V");
    if (!g_s3eFlyMobRewardedVideoLoad)
        goto fail;

    g_s3eFlyMobRewardedVideoShow = env->GetMethodID(cls, "s3eFlyMobRewardedVideoShow", "()V");
    if (!g_s3eFlyMobRewardedVideoShow)
        goto fail;

    g_s3eFlyMobRewardedVideoIsReady = env->GetMethodID(cls, "s3eFlyMobRewardedVideoIsReady", "()Z");
    if (!g_s3eFlyMobRewardedVideoIsReady)
        goto fail;

    g_s3eFlyMobSDKSetDebugMode = env->GetMethodID(cls, "s3eFlyMobSDKSetDebugMode", "(Z)V");
    if (!g_s3eFlyMobSDKSetDebugMode)
        goto fail;

    g_s3eFlyMobSDKIsDebugMode = env->GetMethodID(cls, "s3eFlyMobSDKIsDebugMode", "()Z");
    if (!g_s3eFlyMobSDKIsDebugMode)
        goto fail;

    g_s3eFlyMobSDKSetCoppa = env->GetMethodID(cls, "s3eFlyMobSDKSetCoppa", "(Z)V");
    if (!g_s3eFlyMobSDKSetCoppa)
        goto fail;

    g_s3eFlyMobSDKIsCoppa = env->GetMethodID(cls, "s3eFlyMobSDKIsCoppa", "()Z");
    if (!g_s3eFlyMobSDKIsCoppa)
        goto fail;

    g_s3eFlyMobSDKSetDnt = env->GetMethodID(cls, "s3eFlyMobSDKSetDnt", "(Z)V");
    if (!g_s3eFlyMobSDKSetDnt)
        goto fail;

    g_s3eFlyMobSDKIsDnt = env->GetMethodID(cls, "s3eFlyMobSDKIsDnt", "()Z");
    if (!g_s3eFlyMobSDKIsDnt)
        goto fail;

    g_s3eFlyMobSDKSetTesting = env->GetMethodID(cls, "s3eFlyMobSDKSetTesting", "(Z)V");
    if (!g_s3eFlyMobSDKSetTesting)
        goto fail;

    g_s3eFlyMobSDKIsTesting = env->GetMethodID(cls, "s3eFlyMobSDKIsTesting", "()Z");
    if (!g_s3eFlyMobSDKIsTesting)
        goto fail;



    IwTrace(FLYMOB ("FlyMob init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(FLYMOB, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void FlyMobTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

void s3eFlyMobInterstitialInitialize_platform(const int zoneID)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobInterstitialInitialize, zoneID);
}

void s3eFlyMobInterstitialLoad_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobInterstitialLoad);
}

void s3eFlyMobInterstitialShow_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobInterstitialShow);
}

bool s3eFlyMobInterstitialIsReady_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eFlyMobInterstitialIsReady);
}

void s3eFlyMobRewardedVideoInitialize_platform(const int zoneID)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobRewardedVideoInitialize, zoneID);
}

void s3eFlyMobRewardedVideoLoad_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobRewardedVideoLoad);
}

void s3eFlyMobRewardedVideoShow_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobRewardedVideoShow);
}

bool s3eFlyMobRewardedVideoIsReady_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eFlyMobRewardedVideoIsReady);
}

void s3eFlyMobSDKSetDebugMode_platform(bool isDebug)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobSDKSetDebugMode, isDebug);
}

bool s3eFlyMobSDKIsDebugMode_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eFlyMobSDKIsDebugMode);
}

void s3eFlyMobSDKSetCoppa_platform(bool isCoppa)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobSDKSetCoppa, isCoppa);
}

bool s3eFlyMobSDKIsCoppa_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eFlyMobSDKIsCoppa);
}

void s3eFlyMobSDKSetDnt_platform(bool isDnt)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobSDKSetDnt, isDnt);
}

bool s3eFlyMobSDKIsDnt_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eFlyMobSDKIsDnt);
}

void s3eFlyMobSDKSetTesting_platform(bool isTesting)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_s3eFlyMobSDKSetTesting, isTesting);
}

bool s3eFlyMobSDKIsTesting_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_s3eFlyMobSDKIsTesting);
}
