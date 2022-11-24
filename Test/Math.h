#pragma once

namespace MathUtils
{
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

		inline Vec3 operator +(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
		inline Vec3 operator -(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
		inline Vec3 operator *(float f) const { return Vec3(x * f, y * f, z * f); }

		float Lenght() const { return sqrtf(x * x + y * y + z * z); }
		Vec3 Normalize() const { return *this * (1.0f / Lenght()); }
	};

	inline float Vec3Dot(const Vec3& vec1, const Vec3& vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}
}