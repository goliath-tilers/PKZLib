#pragma once

#include <cstring>

#include "../Package/CMChunk.h"
#include "ResourceTypes.h"

class CMChunkResourceHeader : public CMChunk
{
public:
    uint32_t uiCRC;
    uint32_t uiResourceType;
    uint32_t uiLanguageMask;
    uint32_t uiQualityLevel;
    uint64_t uiDataOffset;
    uint32_t uiPostLoadDataCRC;
    char     zName[64];

    CMResourceType GetResourceType() const
    {
        return static_cast<CMResourceType>(uiResourceType);
    }

    std::string GetResourceTypeName() const
    {
        return ToString(GetResourceType());
    }

    uint32_t GetRawResourceType() const
    {
        return uiResourceType;
    }

    uint32_t GetLanguageMask() const
    {
        return uiLanguageMask;
    }

    uint32_t GetQualityLevel() const
    {
        return uiQualityLevel;
    }

    uint32_t GetPostLoadDataCRC() const
    {
        return uiPostLoadDataCRC;
    }

    uint32_t GetCRC() const
    {
        return uiCRC;
    }

    uint32_t GetDataOffset32() const
    {
        return static_cast<uint32_t>(uiDataOffset);
    }

    uint64_t GetDataOffset() const
    {
        return uiDataOffset;
    }

    std::string GetName() const
    {
        return std::string(zName, strnlen(zName, sizeof(zName)));
    }
};