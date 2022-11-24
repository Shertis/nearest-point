#pragma once

#include <vector>
#include "Math.h"

class PolyLine
{
public:
	PolyLine() {}
	PolyLine(const std::vector<Vec3>& iData) : m_pointData(iData) {}

	void FindNearPoint(const Vec3& iTargetPoint);

private:
	std::vector<Vec3> m_pointData;
};

