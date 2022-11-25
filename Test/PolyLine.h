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

/**
 * Method searches the nearest point on the polyline to given point
 * if there is no point projection, then returns the nearest point of the polyline
 * 
 * @param coordinates of the point to be projected
 * @return the vector of segments of the polyline to which the selected point belongs
 * and the projection of the point on these segments
 */
	std::vector<PointOnPolyLine> FindNearPoint(const MathUtils::Vec3& iTargetPoint);

private:
	std::vector<MathUtils::Vec3> m_pointData;
};

