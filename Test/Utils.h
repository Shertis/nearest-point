#pragma once

#include <string>
#include <sstream>
#include "Math.h"

/**
 * trying to convert string to 3
 * returns false if the string does not match the "x y z" format
 *
 * @param iStr input string to convert
 * @param oVec overwrites the Vec3 obtained from the string
 * @return success boolean
 */

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