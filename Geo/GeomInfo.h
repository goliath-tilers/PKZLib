#pragma once
#include "../BaseUtils/BUSphere.h"

class CMChunkGeomInfo
{
public:
    BUSphere bSphere;
    uint32_t uiFlags;
    uint32_t uiNbLODs;
    uint32_t uiNbMaterials;
    uint32_t uiNbMorphTargets;
    float fLODDistance[4];
    uint32_t uiNbSBMeshData;
    uint32_t uiNbPrimsTotal;
    uint32_t uiNbText3DPrimsTotal;
    uint32_t uiNbMaterialIdxListSize;
    uint32_t uiNbBonePalettesTotal;
    uint32_t uiVPDataPacketCount;
    uint32_t uiMaxBoneCount;
    uint8_t  uiPadding[3];
};

class CMChunkGeomInfo_V9
{
    BUSphere bSphere;
    uint32_t uiFlags;
    uint32_t uiNbLODs;
    uint32_t uiNbMaterials;
    uint32_t uiNbMorphTargets;
    float fLODDistance[4];
    uint32_t uiNbSBMeshData;
    uint32_t uiNbPrimsTotal;
    uint32_t uiNbText3DPrimsTotal;
    uint32_t uiNbMaterialIdxListSize;
    uint32_t uiNbBonePalettesTotal;
    uint32_t uiVPDataPacketCount;
};