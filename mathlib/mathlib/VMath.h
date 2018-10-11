#ifndef VMATH_H
#define VMATH_H	

#include <math.h>
#include <stdio.h>

#include "Vector.h"

//This is a library for Vector 3 routines

namespace GAME_Lib
{

	class VMath
	{
	public:
		//calculate the dot product between Vec3's a & b
		inline static float dot(const Vec3 &a, const Vec3 &b)
		{
			return((a.x*b.x + a.y * b.y + a.z * b.z));
		}

		//Calculate the cross product
		inline static const Vec3 cross(const Vec3 &a, const Vec3 &b)
		{
			return (a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
		}

		//Return a normalized Vec3
		inline static Vec3 normalize(const Vec3 &a)
		{
			float magnitude;
			Vec3 result;
			magnitude = float(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
			//The vector class watches for divide by zero errors
			result.x = a.x / magnitude;
			result.y = a.y / magnitude;
			result.z = a.z / magnitude;

			return result;
		}

		inline static float mag(const Vec3 &a)
		{
			return (sqrt(a.x * a.x + a.y * a.y + a.z + a.z));
		}

		//Axis - angle rotation
		inline static Vec3 rotate(const Vec3 &n, float theta, const Vec3 &v)
		{
			return v * cos(theta) + VMath::dot(v, n) * n * (1 - cos(theta)) + VMath::cross(n, v) * sin(theta);
		}

	};




}


#endif