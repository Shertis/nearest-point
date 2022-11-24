#pragma once

#include <string>
#include <sstream>
#include "Math.h"

inline bool GetVec3FromStr(const std::string& iStr, MathUtils::Vec3& oVec)
{
    if (iStr.empty())
        return false;

    std::istringstream iss(iStr.c_str());

    int i = 0;
    while (!iss.eof())
    {
        if (i > 2)
            return false;

        iss >> oVec.v[i];
        i++;
    }

    if (i < 2)
        return false;

    return true;
}