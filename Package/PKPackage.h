#pragma once

#include <cstdint>

class PKPackage
{
public:
    uint32_t id;        // mask with 0x00FFFFFF
    uint16_t hasChildren;
    uint16_t version;
    uint64_t length;

public:
    PKPackage() = default;

    PKPackage(uint32_t _id, uint16_t _hasChildren, uint16_t _version, uint64_t _length)
        : id(_id), hasChildren(_hasChildren), version(_version), length(_length)
    {}

    uint32_t GetMaskedID() const
    {
        return id & 0x00FFFFFF;
    }
};