#pragma once

#include <cstdint>
#include <vector>

#include "CMChunk.h"
#include <string>

class PKPackage
{
public:
    std::vector<CMChunk> rootChunks; // Root chunks of the package

public:
    PKPackage() = default;

    PKPackage()
    {}

    uint32_t GetPackageSize() const
    {
        return sizeof(PKPackage);
    }

    void ReadFromFile(const std::string& filePath)
    {
        // Implement reading a package from a file.
    }
};