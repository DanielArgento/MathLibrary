#ifndef  VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>

//This is for normalizing Vectors. Dividing by zero is a well known problem, but dividing by nearly zero is also a problem
#ifndef VERY_SMALL
#define VERY_SMALL 1.0e-9	
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI

#ifndef DEGREES_TO_RADIANS
#define DEGREES_TO_RADIANS (M_PI / 180.0f)
#endif // !DEGREES_TO_RADIANS


namespace GAME_Lib
{

	struct Vec3
	{
		float x, y, z;

		//Utility to populate a Vector
		inline void Load(float _x, float _y, float _z)
		{
			x = _x; y = _y; z = _z;
		}

		//Constructors

		inline Vec3(float s = float(0.0))
		{
			Load(s, s, s);
		}

		inline Vec3(float _x, float _y, float _z)
		{
			Load(_x, _y, _z);
		}

		//Copy Constructor
		//In this context const means a promise not to modify anything v points to
		inline Vec3(const Vec3 &v)
		{
			Load(v.x, v.y, v.z);
		}


		//*******************************************
		//***********Operator Overloads**************
		//*******************************************

		//Assignment Operator
		inline Vec3& operator = (const Vec3 &v)
		{
			Load(v.x, v.y, v.z);
			return *this;
		}

		//To use vector like an array you need 2 overloads
		//This is for reading the Vec3 as if it were an array
		inline const float operator [] (int index) const
		{
			return *(&x + index);
		}

		//This is for writing to an array
		inline float& operator [] (int index)
		{
			return *(&x + index);
		}

		//Add two Vec3's
		inline const Vec3 operator +(const Vec3 &other) const
		{
			return Vec3(x + other.x, y + other.y, z + other.z);
		}

		//Add another Vec3 to itself
		inline Vec3& operator+=(const Vec3 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		//Take the negative of a vec3
		inline const Vec3 operator-() const
		{
			return Vec3(-x, -y, -z);
		}

		//Substract two Vec3's
		inline const Vec3 operator-(const Vec3& other) const
		{
			return Vec3(x - other.x, y - other.y, z - other.z);
		}

		//Subtract a Vec3 from itself
		inline const Vec3& operator -=(const Vec3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		//Multiply a Vec3 by a scalar
		inline const Vec3 operator * (const float s) const
		{
			return Vec3(s * x, s * y, s * z);
		}

		//Multiply a Vec3 by a scalar and assign it to itself
		inline Vec3& operator *= (const float s)
		{
			x *= s;
			y *= s;
			z *= s;

			return *this;
		}

		//Multiply a scalar by a Vec3 if it's the scalar first
		inline friend Vec3 operator * (const float s, const Vec3 &v)
		{
			return v * s;
		}

		//Divide by scalar watch for divide by zero issues
		inline const Vec3 operator/(const float s) const
		{
#ifdef _DEBUG //if in debug mode, lets worry about dividing by zero
			if (fabs(s) < VERY_SMALL)
			{
				std::string errorMsg("Divide by nearly zero!!");
				throw errorMsg;
			}
#endif // _DEBUG 
			float r = 1.0f / s;
			return *this * r;

		}

		//Divide by scalar and assign it to itself
		inline Vec3& operator /= (const float s)
		{
#ifdef DEBUG //If in debug mode lets worry about dividing by zero
			if (fabs(s) < VERY_SMALL)
			{
				std::string errorMsg("Divide by nearly zero!");
				throw errorMsg;
			}
#endif // DEBUG 

			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void Print()
		{
			printf("%f %f %f \n", x, y, z);
		}

	};

	//Vec4 definitions
	//I am intentionally creating a Vec4 from a Vec3 so I can pass a Vec4 into a subroutine that wants a Vec3
	//In many cases this will be mathematically ok, just be careful

	struct Vec4 : public Vec3
	{
		//float x;
		//float y; //from Vec3
		//float z;
		float w;

		//Constructors
		inline Vec4(float s = float(0.0))
		{
			x = s;
			y = s;
			z = s;
			w = s;
		}

		inline Vec4(float _x, float _y, float _z, float _w)
		{
			x = _x;
			y = _y;
			z = _z;
			w = _w;
		}

		inline Vec4(const Vec4 &v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = v.w;
		}

		inline Vec4(const Vec3 &v)
		{
			x = v.x;
			y = v.y;
			z = v.z;
			w = 1.0f;
		}

		//*************************************
		//********Operator Overloads***********
		//*************************************

		//Assignment Operator
		inline Vec4& operator = (const Vec4 &other)
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;
		}

		//Write array
		inline float& operator [] (int index)
		{
			return *(&x + index);
		}

		//Read array
		inline const float operator [] (int index) const
		{
			return *(&x + index);
		}

		//Add two Vec4's
		inline const Vec4 operator + (const Vec4 &other) const
		{
			return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		//Add another Vec4 to itself
		inline Vec4& operator += (const Vec4 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		//Take the negative of a Vec4
		inline const Vec4 operator - () const
		{
			return Vec4(-x, -y, -z, -w);
		}

		//Subtract two Vec4's
		inline const Vec4 operator - (const Vec4 &other) const
		{
			return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
		}

		//Subtract a Vec4 from itself
		inline Vec4& operator -= (const Vec4 &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		//Multiply a Vec4 by a scalar
		inline const Vec4 operator * (const float s) const
		{
			return Vec4(s * x, s * y, s * z, s * w);
		}

		//Multiply a Vec4 by a scalar and assign it to itself
		inline Vec4& operator *= (const float s)
		{
			x *= s;
			y *= s;
			z *= s;
			w *= s;

			return *this;
		}

		//Multiply a Vec4 by a scalar if the scalar comes first
		inline friend Vec4 operator * (const float s, const Vec4 &v)
		{
			return v * s;
		}

		//Divide by scalar Watch for divide by zero
		inline const Vec4 operator / (const float s) const
		{


#ifdef DEBUG
			if (fabs(s) < VERY_SMALL)
			{
				std::string errorMsg("Divide by nearly zero!");
				throw errorMsg;
			}
#endif DEBUG	

			float r = 1.0f / s;
			return *this * r;
		}

		//Divide by scalar and assign it to itself
		inline Vec4& operator /= (const float s)
		{
#ifdef DEBUG
			if (fabs(s) < VERY_SMALL)
			{
				std::string errorMsg("Divide by nearly zero!");
				throw errorMsg;
			}
#endif DEBUG	

			float r = 1.0f / s;
			*this *= r;
			return *this;
		}

		inline void Print()
		{
			printf("%f %f %f %f \n", x, y, z, w);
		}

		//Type conversion operators 

		inline operator const float* () const {
			return static_cast<const float*>(&x);
		}
		inline operator float* () {
			return static_cast<float*>(&x);
		}

	};

}


#endif // ! VECTOR_H