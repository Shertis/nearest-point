#pragma once

#include <vector>
#include "Math.h"



class PolyLine
{
public:
	struct PointOnPolyLine
	{
		int segment = 0;
		MathUtils::Vec3 Point;
	};

	PolyLine() {}
	PolyLine(const std::vector<MathUtils::Vec3>& iData) : m_pointData(iData) {}

	std::vector<PointOnPolyLine> FindNearPoint(const MathUtils::Vec3& iTargetPoint);

private:
	std::vector<MathUtils::Vec3> m_pointData;
};

