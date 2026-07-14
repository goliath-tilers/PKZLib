#pragma once

#include "../Package/PKPackage.h"

class RZResourceMgr
{
public:
    enum Res
    {
        kComplete,
        KSkip,
        kIncomplete,
        kError
    };

    Res LoadChunk(CMChunk& chunk, BUStream& stream, PKPackage* pPackage)
    {

        switch (chunk.GetIDToEnum())
        {
        case Gen_HierarchyLibrary:
        case Gen_HAnimLibrary:
        case Gen_GeometryLibrary:
        case Gen_TextureLibrary:
        case Gen_FontLibrary:
        case Gen_ParticleLibrary:
        case Gen_BinaryDataLibrary:
        case Gen_CutSceneLibrary:
        case Gen_AudioSoundLibrary:
        case Gen_AudioCueLibrary:
        case Gen_AudioSampleLibrary:
        case Gen_AudioCategoryLibrary:
        case Gen_AudioRPCLibrary:
        case Gen_MaterialAnimLibrary:
        case Gen_MotionTrailLibrary:
        case Gen_BSplineLibrary_REMOVED:
        case Gen_ParamBlockLibrary:
        case Gen_AudioReverbLibrary:
        case Gen_AnimCueLibrary:
        case Gen_AnimTreeLibrary:
        case Gen_TextStyleLibrary:
        case Gen_CurveLibrary:
        case Gen_ResourcesListLibrary:
        case Gen_ParamTreeLibrary:
        case Gen_ParamGraphLibrary:
        case Gen_AudioInterleavedStreamsLibrary:
        case Gen_Hud3dLibrary:
        case Gen_WwiseAudioLibrary:
        case Gen_HeightMapLibrary:
        case Gen_DecalLibrary:
        case Gen_WwiseAudioCutsceneLibrary:
        case Gen_WwiseMediaLibrary:
        case Gen_SequenceLibrary:
            return LoadRezLibrary(chunk, stream, pPackage);

        case Gen_LogicLibrary:
        {
            return RZResourceMgr::LoadLogicLibrary(chunk, stream, pPackage);
        }

        case Gen_AudioLibrary:
        {
            Res result = kComplete;
            while (chunk.ReadSub(stream))
            {
                result = LoadRezLibrary(subChunk, stream, pPackage);
            }
            return result;
        }

        default:
            printf("Unhandled chunk type %s in RZResourceMgr::LoadChunk", ToString(chunk.GetIDToEnum()).c_str());
            return kIncomplete;
        }
    }
};