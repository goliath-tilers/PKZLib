#pragma once

#include "BUMath.h"

class BUBox
{
public:
    BUVector3 mOrigin;
    BUVector3 mHalfDims;

    BUVector3 GetMin() const
    {
        return BUVector3(mOrigin.x - mHalfDims.x,
            mOrigin.y - mHalfDims.y,
            mOrigin.z - mHalfDims.z);
    }

    BUVector3 GetMax() const
    {
        return BUVector3(mOrigin.x + mHalfDims.x,
            mOrigin.y + mHalfDims.y,
            mOrigin.z + mHalfDims.z);
    }
};