#pragma once

enum EAppState
{
	k_EAppStateInvalid			= 0,
	k_EAppStateUninstalled		= 1,
	k_EAppStateUpdateRequired	= 2,
	k_EAppStateFullyInstalled	= 4,
	k_EAppStateDataEncrypted	= 8,
	k_EAppStateSharedOnly		= 64,
	k_EAppStateDataLocked		= 16,
	k_EAppStateFilesMissing		= 32,
	k_EAppStateFilesCorrupt		= 128,
	k_EAppStateAppRunning		= 8192,
	k_EAppStateBackupRunning	= 4096,
	k_EAppStateUpdateRunning	= 256,
	k_EAppStateUpdateStopping	= 8388608,
	k_EAppStateUpdatePaused		= 512,
	k_EAppStateUpdateStarted	= 1024,
	k_EAppStateReconfiguring	= 65536,
	k_EAppStateAddingFiles		= 262144,
	k_EAppStateDownloading		= 1048576,
	k_EAppStateStaging			= 2097152,
	k_EAppStateCommitting		= 4194304,
	k_EAppStateUninstalling		= 2048,
	k_EAppStatePreallocating	= 524288,
	k_EAppStateValidating		= 131072,
};