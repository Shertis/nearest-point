#pragma once

struct Vec3
{
	union
	{		
		struct 
		{ 
			float x, y, z; 
		};
		float v[3];
	};

	Vec3() : x(0.f), y(0.f), z(0.f) {}
	Vec3(float iX, float iY, float iZ) : x(iX), y(iY), z(iZ) {}

	float VecDot(const Vec3& otherVec)
	{
		return x * x + y * y + z * z;
	}
};