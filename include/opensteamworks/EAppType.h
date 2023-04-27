#pragma once

typedef enum EAppType
{
    k_EAppTypeDepotonly = -2147483648,
    k_EAppTypeInvalid = 0,
    k_EAppTypeGame = 1,
    k_EAppTypeApplication = 2,
    k_EAppTypeTool = 4,
    k_EAppTypeDemo = 8,
    k_EAppTypeMedia = 16,
    k_EAppTypeDlc = 32,
    k_EAppTypeGuide = 64,
    k_EAppTypeDriver = 128,
    k_EAppTypeConfig = 256,
    k_EAppTypeHardware = 512,
    k_EAppTypeFranchise = 1024,
    k_EAppTypeVideo = 2048,
    k_EAppTypePlugin = 4096,
    k_EAppTypeMusic = 8192,
    k_EAppTypeSeries = 16384,
    k_EAppTypeComic = 32768,
    k_EAppTypeBeta = 65536,
    k_EAppTypeShortcut = 1073741824,
} EAppType;
