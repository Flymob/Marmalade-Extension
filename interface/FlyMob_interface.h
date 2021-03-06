/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*s3eFlyMobInterstitialInitialize_t)(const int zoneID);
typedef       void(*s3eFlyMobInterstitialLoad_t)();
typedef       void(*s3eFlyMobInterstitialShow_t)();
typedef       bool(*s3eFlyMobInterstitialIsReady_t)();
typedef       void(*s3eFlyMobRewardedVideoInitialize_t)(const int zoneID);
typedef       void(*s3eFlyMobRewardedVideoLoad_t)();
typedef       void(*s3eFlyMobRewardedVideoShow_t)();
typedef       bool(*s3eFlyMobRewardedVideoIsReady_t)();
typedef       void(*s3eFlyMobSDKSetDebugMode_t)(bool isDebug);
typedef       bool(*s3eFlyMobSDKIsDebugMode_t)();
typedef       void(*s3eFlyMobSDKSetCoppa_t)(bool isCoppa);
typedef       bool(*s3eFlyMobSDKIsCoppa_t)();
typedef       void(*s3eFlyMobSDKSetDnt_t)(bool isDnt);
typedef       bool(*s3eFlyMobSDKIsDnt_t)();
typedef       void(*s3eFlyMobSDKSetTesting_t)(bool isTesting);
typedef       bool(*s3eFlyMobSDKIsTesting_t)();

/**
 * struct that gets filled in by FlyMobRegister
 */
typedef struct FlyMobFuncs
{
    s3eFlyMobInterstitialInitialize_t m_s3eFlyMobInterstitialInitialize;
    s3eFlyMobInterstitialLoad_t m_s3eFlyMobInterstitialLoad;
    s3eFlyMobInterstitialShow_t m_s3eFlyMobInterstitialShow;
    s3eFlyMobInterstitialIsReady_t m_s3eFlyMobInterstitialIsReady;
    s3eFlyMobRewardedVideoInitialize_t m_s3eFlyMobRewardedVideoInitialize;
    s3eFlyMobRewardedVideoLoad_t m_s3eFlyMobRewardedVideoLoad;
    s3eFlyMobRewardedVideoShow_t m_s3eFlyMobRewardedVideoShow;
    s3eFlyMobRewardedVideoIsReady_t m_s3eFlyMobRewardedVideoIsReady;
    s3eFlyMobSDKSetDebugMode_t m_s3eFlyMobSDKSetDebugMode;
    s3eFlyMobSDKIsDebugMode_t m_s3eFlyMobSDKIsDebugMode;
    s3eFlyMobSDKSetCoppa_t m_s3eFlyMobSDKSetCoppa;
    s3eFlyMobSDKIsCoppa_t m_s3eFlyMobSDKIsCoppa;
    s3eFlyMobSDKSetDnt_t m_s3eFlyMobSDKSetDnt;
    s3eFlyMobSDKIsDnt_t m_s3eFlyMobSDKIsDnt;
    s3eFlyMobSDKSetTesting_t m_s3eFlyMobSDKSetTesting;
    s3eFlyMobSDKIsTesting_t m_s3eFlyMobSDKIsTesting;
} FlyMobFuncs;
