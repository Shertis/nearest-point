#include "PolyLine.h"

std::vector<PolyLine::PointOnPolyLine> PolyLine::FindNearPoint(const MathUtils::Vec3& iTargetPoint)
{
	std::vector<PolyLine::PointOnPolyLine> result;
	bool hasPointOnLine = false;
	float distance = FLT_MAX;

	for (int i = 0; i < m_pointData.size() - 1; i++)
	{
		const auto& point1 = m_pointData[i];
		const auto& point2 = m_pointData[i + 1];

		auto vec1 = point2 - point1;
		auto tVec1 = iTargetPoint - point1;
		float d1 = MathUtils::Vec3Dot(vec1, tVec1);

		auto vec2 = point1 - point2;
		auto tVec2 = iTargetPoint - point2;
		float d2 = MathUtils::Vec3Dot(vec2, tVec2);

		if (d1 > 0 && d2 > 0)
		{
			if (!hasPointOnLine)
			{
				result.clear();
				hasPointOnLine = true;
			}

			auto pointOnLine = point1 + vec1 * (d1 / MathUtils::Vec3Dot(vec1, vec1));
			result.emplace_back(PolyLine::PointOnPolyLine({ i, pointOnLine }));
		}
		else if (!hasPointOnLine)
		{
			auto pointOnLine = d1 < 0 ? point1 : point2;
			float curDistance = (iTargetPoint - pointOnLine).Lenght();

			if (std::abs(distance - curDistance) > std::numeric_limits<float>::epsilon())
			{
				if (distance > curDistance)
				{
					result.clear();
					distance = curDistance;
				}
				else
					continue;
			}
			result.emplace_back(PolyLine::PointOnPolyLine({ i, pointOnLine }));
		}
	}

	return result;
}
