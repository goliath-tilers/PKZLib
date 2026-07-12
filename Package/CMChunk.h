#pragma once
#include <cstdint>
#include <vector>

#include "CMChunkTypes.h"

class CMChunk
{
public:
    uint32_t id; // mask with 0x00FFFFFF (GetMaskedID)
    uint16_t hasChildren;
    uint16_t version;
    uint64_t length;

    std::vector<uint8_t> data; // Data of the chunk (Only applied if child chunk.)

    std::vector<CMChunk> children;

    CMChunk() = default;

    CMChunk(uint32_t id, uint16_t hasChildren, uint16_t version, uint64_t length)
        : id(id), hasChildren(hasChildren), version(version), length(length)
    {}

    uint32_t GetMaskedID() const
    {
        return id & 0x00FFFFFF;
    }

    std::vector<CMChunk> FindInChildren(uint32_t searchID) const
    {
        std::vector<CMChunk> foundChunks;
        for (const auto& child : children)
        {
            if (child.GetMaskedID() == searchID)
            {
                foundChunks.push_back(child);
            }
        }
        return foundChunks;
    }

    std::vector<CMChunk> FindInChildren(CMChunkTypes searchType) const
    {
        return FindInChildren(static_cast<uint32_t>(searchType));
    }

    std::vector<CMChunk> GetChildren() const
    {
        return children;
    }

    CMChunkTypes GetIDToEnum() const
    {
        return static_cast<CMChunkTypes>(GetMaskedID());
    }

    uint32_t GetID() const
    {
        return id;
    }

    uint32_t GetVersion() const
    {
        return version;
    }

    uint64_t GetLength() const
    {
        return length;
    }

    bool GetHasChildren() const
    {
        return hasChildren != 0;
    }
};