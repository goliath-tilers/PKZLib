#pragma once

#include "BUMath.h"
#define kEpsilon 0.0000099999997

class BUMatrix
{
public:
    float m[4][4]; // Actual struct isn't present in SSCR ?

    BUMatrix(float _f00, float _f01, float _f02, float _f03,
        float _f10, float _f11, float _f12, float _f13,
        float _f20, float _f21, float _f22, float _f23,
        float _f30, float _f31, float _f32, float _f33)
    {
        m[0][0] = _f00; m[0][1] = _f01; m[0][2] = _f02; m[0][3] = _f03;
        m[1][0] = _f10; m[1][1] = _f11; m[1][2] = _f12; m[1][3] = _f13;
        m[2][0] = _f20; m[2][1] = _f21; m[2][2] = _f22; m[2][3] = _f23;
        m[3][0] = _f30; m[3][1] = _f31; m[3][2] = _f32; m[3][3] = _f33;
    }

    void Decompose(BUVector3 &_outScale, BUQuaternion &_outRot, BUVector3 &_outTrans) const
    {
        BUVector3 right(m[0][0], m[0][1], m[0][2]);
        BUVector3 up(m[1][0], m[1][1], m[1][2]);
        BUVector3 forward(m[2][0], m[2][1], m[2][2]);

        _outScale.x = right.Length();
        _outScale.y = up.Length();
        _outScale.z = forward.Length();

        if (_outScale.x == 0.0f) _outScale.x = kEpsilon;
        if (_outScale.y == 0.0f) _outScale.y = kEpsilon;
        if (_outScale.z == 0.0f) _outScale.z = kEpsilon;

        right /= _outScale.x;
        up /= _outScale.y;
        forward /= _outScale.z;

        BUVector3 crossFR = forward ^ right;

        if (crossFR.Dot(up) < 0.0f)
        {
            right = -right;
            up = -up;
            forward = -forward;

            _outScale.x = -_outScale.x;
        }

        BUMatrix tmpMat(right, up, forward);
        tmpMat.ToQuat(_outRot);

        _outTrans.x = m[3][0];
        _outTrans.y = m[3][1];
        _outTrans.z = m[3][2];
    }

    void FromRows3()
    {

    }

    void InvertOthoNormal()
    {

    }

    void MultiplyMat3Vec3()
    {

    }
};