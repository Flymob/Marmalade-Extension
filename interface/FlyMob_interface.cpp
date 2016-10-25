/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "FlyMob.h"


// Define S3E_EXT_SKIP_LOADER_CALL_LOCK on the user-side to skip LoaderCallStart/LoaderCallDone()-entry.
// e.g. in s3eNUI this is used for generic user-side IwUI-based implementation.
#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
#if (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)) || defined I3D_ARCH_NACLX86_64
// For platforms missing stack-switching (WP8, NaCl, etc.) make loader-entry via LoaderCallStart/LoaderCallDone() on the user-side.
#define LOADER_CALL_LOCK
#endif
#endif


#include "FlyMob_interface.h"

static FlyMobFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xfdb3c38e, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: FlyMob");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xfdb3c38e, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool FlyMobAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void s3eFlyMobInterstitialInitialize(const int zoneID)
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[0] func: s3eFlyMobInterstitialInitialize"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialInitialize);
#endif

    g_Ext.m_s3eFlyMobInterstitialInitialize(zoneID);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialInitialize);
#endif

    return;
}

void s3eFlyMobInterstitialLoad()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[1] func: s3eFlyMobInterstitialLoad"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialLoad);
#endif

    g_Ext.m_s3eFlyMobInterstitialLoad();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialLoad);
#endif

    return;
}

void s3eFlyMobInterstitialShow()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[2] func: s3eFlyMobInterstitialShow"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialShow);
#endif

    g_Ext.m_s3eFlyMobInterstitialShow();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialShow);
#endif

    return;
}

bool s3eFlyMobInterstitialIsReady()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[3] func: s3eFlyMobInterstitialIsReady"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialIsReady);
#endif

    bool ret = g_Ext.m_s3eFlyMobInterstitialIsReady();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobInterstitialIsReady);
#endif

    return ret;
}

void s3eFlyMobRewardedVideoInitialize(const int zoneID)
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[4] func: s3eFlyMobRewardedVideoInitialize"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoInitialize);
#endif

    g_Ext.m_s3eFlyMobRewardedVideoInitialize(zoneID);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoInitialize);
#endif

    return;
}

void s3eFlyMobRewardedVideoLoad()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[5] func: s3eFlyMobRewardedVideoLoad"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoLoad);
#endif

    g_Ext.m_s3eFlyMobRewardedVideoLoad();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoLoad);
#endif

    return;
}

void s3eFlyMobRewardedVideoShow()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[6] func: s3eFlyMobRewardedVideoShow"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoShow);
#endif

    g_Ext.m_s3eFlyMobRewardedVideoShow();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoShow);
#endif

    return;
}

bool s3eFlyMobRewardedVideoIsReady()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[7] func: s3eFlyMobRewardedVideoIsReady"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoIsReady);
#endif

    bool ret = g_Ext.m_s3eFlyMobRewardedVideoIsReady();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobRewardedVideoIsReady);
#endif

    return ret;
}

void s3eFlyMobSDKSetDebugMode(bool isDebug)
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[8] func: s3eFlyMobSDKSetDebugMode"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetDebugMode);
#endif

    g_Ext.m_s3eFlyMobSDKSetDebugMode(isDebug);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetDebugMode);
#endif

    return;
}

bool s3eFlyMobSDKIsDebugMode()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[9] func: s3eFlyMobSDKIsDebugMode"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsDebugMode);
#endif

    bool ret = g_Ext.m_s3eFlyMobSDKIsDebugMode();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsDebugMode);
#endif

    return ret;
}

void s3eFlyMobSDKSetCoppa(bool isCoppa)
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[10] func: s3eFlyMobSDKSetCoppa"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetCoppa);
#endif

    g_Ext.m_s3eFlyMobSDKSetCoppa(isCoppa);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetCoppa);
#endif

    return;
}

bool s3eFlyMobSDKIsCoppa()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[11] func: s3eFlyMobSDKIsCoppa"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsCoppa);
#endif

    bool ret = g_Ext.m_s3eFlyMobSDKIsCoppa();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsCoppa);
#endif

    return ret;
}

void s3eFlyMobSDKSetDnt(bool isDnt)
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[12] func: s3eFlyMobSDKSetDnt"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetDnt);
#endif

    g_Ext.m_s3eFlyMobSDKSetDnt(isDnt);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetDnt);
#endif

    return;
}

bool s3eFlyMobSDKIsDnt()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[13] func: s3eFlyMobSDKIsDnt"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsDnt);
#endif

    bool ret = g_Ext.m_s3eFlyMobSDKIsDnt();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsDnt);
#endif

    return ret;
}

void s3eFlyMobSDKSetTesting(bool isTesting)
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[14] func: s3eFlyMobSDKSetTesting"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetTesting);
#endif

    g_Ext.m_s3eFlyMobSDKSetTesting(isTesting);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKSetTesting);
#endif

    return;
}

bool s3eFlyMobSDKIsTesting()
{
    IwTrace(FLYMOB_VERBOSE, ("calling FlyMob[15] func: s3eFlyMobSDKIsTesting"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsTesting);
#endif

    bool ret = g_Ext.m_s3eFlyMobSDKIsTesting();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eFlyMobSDKIsTesting);
#endif

    return ret;
}
