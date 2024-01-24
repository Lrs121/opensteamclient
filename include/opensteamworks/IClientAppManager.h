//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ICLIENTAPPMANAGER_H
#define ICLIENTAPPMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "SteamTypes.h"
#include "AppsCommon.h"

struct AppStateInfo_t {
    char allInfo[4096] = { 0 };
};

typedef int LibraryFolder_t;
typedef uint ELanguage;

abstract_class IClientAppManager
{
public:
    
    
    //virtual  EAppUpdateError InstallApp( , const char *cszAppDir, int32 iBaseFolder,  ) = 0;
    virtual EAppUpdateError InstallApp(AppId_t unAppID, LibraryFolder_t libraryFolder, bool bLegacy) = 0; //argc: 3, index 1
    //virtual EAppUpdateError UninstallApp( AppId_t unAppID, bool bComplete ) = 0;
    virtual EAppUpdateError UninstallApp(AppId_t) = 0; //argc: 1, index 2
    virtual EAppUpdateError LaunchApp(CGameID appID, uint32 uLaunchOption, uint32 arch, char const* pszLaunchArgs) = 0; //argc: 4, index 3
    virtual unknown_ret ShutdownApp(AppId_t unAppID, bool bForce) = 0; //argc: 2, index 4
    virtual EAppState GetAppInstallState(AppId_t unAppID) = 0; //argc: 1, index 5
    virtual unknown_ret GetAppInstallDir(AppId_t unAppID, char*, unsigned int) = 0; //argc: 3, index 6
    virtual unknown_ret GetAppContentInfo(AppId_t unAppID, bool, unsigned int*, unsigned int*, unsigned long long*, unsigned long long*) = 0; //argc: 6, index 7
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret GetAppStagingInfo() = 0; //argc: 3, index 8
    virtual bool IsAppDlcInstalled(AppId_t unAppID, AppId_t unDLCId) = 0; //argc: 2, index 9
    virtual unknown_ret GetDlcDownloadProgress(AppId_t unAppID, unsigned int, unsigned long long*, unsigned long long*) = 0; //argc: 4, index 10
    virtual bool BIsDlcEnabled(AppId_t unAppID, AppId_t unDLCId, bool *outIsEnabled) = 0; //argc: 3, index 11
    virtual unknown_ret SetDlcEnabled(AppId_t unAppID, AppId_t unDLCId, bool enable) = 0; //argc: 3, index 12
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret SetDlcContext() = 0; //argc: 2, index 13
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret GetDlcSizes() = 0; //argc: 4, index 14
    virtual uint32 GetNumInstalledApps() = 0; //argc: 0, index 15
    virtual unknown_ret GetInstalledApps(AppId_t *unAppsIDs, unsigned int maxOut) = 0; //argc: 2, index 0
    virtual bool BIsWaitingForInstalledApps() = 0; //argc: 0, index 1
    virtual unknown_ret GetAppDependencies(AppId_t unAppID, AppId_t* unAppsIDs, unsigned int maxOut) = 0; //argc: 3, index 0
    virtual unknown_ret GetDependentApps(AppId_t, AppId_t* unAppsIDs, unsigned int maxOut) = 0; //argc: 3, index 1
    virtual unknown_ret GetUpdateInfo(AppId_t, AppUpdateInfo_s*) = 0; //argc: 2, index 2
    virtual bool BIsAppUpToDate(AppId_t) = 0; //argc: 1, index 3
    virtual unknown_ret GetAvailableLanguages(AppId_t, bool, char*, unsigned int) = 0; //argc: 4, index 4
    virtual ELanguage GetCurrentLanguage(AppId_t, char*, unsigned int) = 0; //argc: 3, index 5
    virtual ELanguage GetCurrentLanguage(AppId_t) = 0; //argc: 1, index 6
    virtual unknown_ret GetFallbackLanguage(AppId_t, ELanguage*) = 0; //argc: 2, index 7
    virtual unknown_ret SetCurrentLanguage(AppId_t, ELanguage*) = 0; //argc: 2, index 8
    virtual unknown_ret StartValidatingApp(AppId_t) = 0; //argc: 1, index 9
    virtual unknown_ret CancelValidation(AppId_t) = 0; //argc: 1, index 10
    virtual unknown_ret MarkContentCorrupt(DepotId_t, bool) = 0; //argc: 2, index 11
    virtual unknown_ret GetInstalledDepots(AppId_t, DepotId_t*, uint32) = 0; //argc: 3, index 12
    virtual unknown_ret GetFileDetails(DepotId_t, char const*) = 0; //argc: 2, index 13
    virtual unknown_ret VerifySignedFiles(DepotId_t) = 0; //argc: 1, index 14
    virtual unknown_ret GetAvailableBetas(AppId_t, int*, char*, int, int) = 0; //argc: 5, index 15
    virtual unknown_ret CheckBetaPassword(AppId_t, char const*) = 0; //argc: 2, index 16
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret SetActiveBeta(AppId_t, const char*) = 0; //argc: 2, index 17
    virtual unknown_ret GetActiveBeta(AppId_t, char*, int) = 0; //argc: 3, index 18
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret BGetActiveBetaForApps(AppId_t* apps, int numApps, char* betas, int betasLength) = 0; //argc: 2, index 19
    virtual unknown_ret SetDownloadingEnabled(bool) = 0; //argc: 1, index 20
    virtual bool BIsDownloadingEnabled() = 0; //argc: 0, index 21
    virtual unknown_ret GetDownloadStats(DownloadStats_s*) = 0; //argc: 1, index 0
    virtual AppId_t GetDownloadingAppID() = 0; //argc: 0, index 1
    virtual bool GetAutoUpdateTimeRestrictionEnabled() = 0; //argc: 0, index 0
    virtual unknown_ret SetAutoUpdateTimeRestrictionEnabled(bool) = 0; //argc: 1, index 0
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret GetAutoUpdateTimeRestrictionHours() = 0; //argc: 2, index 1
    virtual unknown_ret SetAutoUpdateTimeRestrictionStartHour() = 0; //argc: 1, index 2
    virtual unknown_ret SetAutoUpdateTimeRestrictionEndHour() = 0; //argc: 1, index 3
    virtual EAppAutoUpdateBehavior GetAppAutoUpdateBehavior(AppId_t) = 0; //argc: 1, index 4
    virtual unknown_ret SetAppAutoUpdateBehavior(AppId_t, EAppAutoUpdateBehavior) = 0; //argc: 2, index 5
    virtual unknown_ret SetAppAllowDownloadsWhileRunningBehavior(AppId_t, EAppAllowDownloadsWhileRunningBehavior) = 0; //argc: 2, index 6
    virtual EAppAllowDownloadsWhileRunningBehavior GetAppAllowDownloadsWhileRunningBehavior(AppId_t) = 0; //argc: 1, index 7
    virtual unknown_ret SetAllowDownloadsWhileAnyAppRunning(bool) = 0; //argc: 1, index 8
    virtual bool BAllowDownloadsWhileAnyAppRunning() = 0; //argc: 0, index 9
    virtual unknown_ret ChangeAppDownloadQueuePlacement(AppId_t, EAppDownloadQueuePlacement) = 0; //argc: 2, index 0
    virtual unknown_ret SetAppDownloadQueueIndex(AppId_t, int) = 0; //argc: 2, index 1
    virtual int GetAppDownloadQueueIndex(AppId_t) = 0; //argc: 1, index 2
    virtual RTime32 GetAppAutoUpdateDelayedUntilTime(AppId_t) = 0; //argc: 1, index 3
    virtual int GetNumAppsInDownloadQueue() = 0; //argc: 0, index 4
    virtual bool BHasLocalContentServer() = 0; //argc: 0, index 0
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret BuildBackup() = 0; //argc: 4, index 0
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret BuildInstaller() = 0; //argc: 4, index 1
    virtual unknown_ret CancelBackup() = 0; //argc: 0, index 2
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret RestoreAppFromBackup() = 0; //argc: 2, index 0
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret RecoverAppFromFolder() = 0; //argc: 2, index 1
    virtual bool CanMoveApp(AppId_t, LibraryFolder_t libraryFolder) = 0; //argc: 2, index 2
    virtual EAppUpdateError MoveApp(AppId_t, LibraryFolder_t libraryFolder) = 0; //argc: 2, index 3
    virtual unknown_ret GetMoveAppProgress(AppId_t, unsigned long long*, unsigned long long*, unsigned int*) = 0; //argc: 4, index 4
    virtual unknown_ret CancelMoveApp(AppId_t) = 0; //argc: 1, index 5
    virtual unknown_ret GetAppStateInfo(AppId_t, AppStateInfo_t* unknownStruct) = 0; //argc: 2, index 6
    virtual unknown_ret BGetAppStateInfoForApps(AppId_t* apps, AppStateInfo_t* unknownStructArray) = 0; //argc: 2, index 7
    virtual unknown_ret BCanRemotePlayTogether(AppId_t) = 0; //argc: 1, index 8
    virtual unknown_ret BIsLocalMultiplayerApp(AppId_t) = 0; //argc: 1, index 9
    virtual int GetNumLibraryFolders() = 0; //argc: 0, index 10
    virtual unknown_ret GetLibraryFolderPath(LibraryFolder_t, char*, int) = 0; //argc: 3, index 0
    virtual LibraryFolder_t AddLibraryFolder(char const*) = 0; //argc: 1, index 1
    virtual unknown_ret SetLibraryFolderLabel(LibraryFolder_t, const char* label) = 0; //argc: 2, index 2
    virtual unknown_ret GetLibraryFolderLabel(LibraryFolder_t, char* label, uint32 labellength) = 0; //argc: 3, index 3
    virtual unknown_ret RemoveLibraryFolder(LibraryFolder_t, bool, bool) = 0; //argc: 3, index 4
    virtual bool BGetLibraryFolderInfo(LibraryFolder_t, bool*, unsigned long long*, unsigned long long*) = 0; //argc: 4, index 5
    virtual LibraryFolder_t GetAppLibraryFolder(AppId_t) = 0; //argc: 1, index 6
    virtual unknown_ret RefreshLibraryFolders() = 0; //argc: 0, index 7
    virtual uint32 GetNumAppsInFolder(LibraryFolder_t) = 0; //argc: 1, index 0
    // Note: intended to be used with a CUtlVector
    virtual unknown_ret GetAppsInFolder(LibraryFolder_t, AppId_t* apps, uint32 appsLength) = 0; //argc: 3, index 1
    virtual unknown_ret ForceInstallDirOverride(const char*) = 0; //argc: 1, index 2
    virtual unknown_ret SetDownloadThrottleRateKbps(int, bool) = 0; //argc: 2, index 3
    virtual unknown_ret GetDownloadThrottleRateKbps(bool) = 0; //argc: 1, index 4
    virtual unknown_ret SuspendDownloadThrottling(bool) = 0; //argc: 1, index 5
    virtual unknown_ret SetThrottleDownloadsWhileStreaming(bool) = 0; //argc: 1, index 6
    virtual bool BThrottleDownloadsWhileStreaming() = 0; //argc: 0, index 7
    virtual char const* GetLaunchQueryParam(AppId_t, char const* pchKey) = 0; //argc: 2, index 0
    virtual unknown_ret BeginLaunchQueryParams(AppId_t) = 0; //argc: 1, index 1
    virtual unknown_ret SetLaunchQueryParam(AppId_t, char const* pchKey, char const* pchValue) = 0; //argc: 3, index 2
    virtual unknown_ret CommitLaunchQueryParams(AppId_t, char const*) = 0; //argc: 2, index 3
    virtual unknown_ret GetLaunchCommandLine(AppId_t, char*, int) = 0; //argc: 3, index 4
    // void* was StringView
    virtual unknown_ret AddContentLogLine(void*) = 0; //argc: 1, index 5
    virtual unknown_ret SetUseHTTPSForDownloads(bool) = 0; //argc: 1, index 6
    virtual bool GetUseHTTPSForDownloads() = 0; //argc: 0, index 7
    virtual unknown_ret SetPeerContentServerMode() = 0; //argc: 1, index 0
    virtual unknown_ret SetPeerContentClientMode() = 0; //argc: 1, index 1
    virtual unknown_ret GetPeerContentServerMode() = 0; //argc: 0, index 2
    virtual unknown_ret GetPeerContentClientMode() = 0; //argc: 0, index 0
    virtual unknown_ret GetPeerContentServerStats() = 0; //argc: 1, index 0
    virtual unknown_ret SuspendPeerContentClient() = 0; //argc: 1, index 1
    virtual unknown_ret SuspendPeerContentServer() = 0; //argc: 1, index 2
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret GetPeerContentServerForApp() = 0; //argc: 3, index 3
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret NotifyDriveAdded() = 0; //argc: 1, index 4
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret NotifyDriveRemoved() = 0; //argc: 1, index 5
    // WARNING: Argument count doesn't match argc! Remove this once this has been corrected!
    virtual unknown_ret SetAudioDownloadQuality() = 0; //argc: 1, index 6
};

#endif // ICLIENTAPPMANAGER_H