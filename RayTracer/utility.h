#pragma once

template<typename T>
struct Vec2
{
	T x, y;
	
	Vec2() : x(T()), y(T()) {}
	Vec2(T X, T Y) : x(X), y(Y) {}

	template<typename I>
	Vec2<I> operator-() { return Vec2<I>(-v.x, -v.y); }
	template<typename I>
	Vec2<I> operator-(const Vec2<I> &v) { return Vec2<I>(x - v.x, y - v.y); }
	template<typename I>
	Vec2<I> operator+(const Vec2<I> &v) { return Vec2<I>(x + v.x, y + v.y); }
	template<typename I>
	Vec2<I> operator*(float s) { return Vec2<I>(x * s, y * s); }
	template<typename I>
	Vec2<I> operator*(int s) { return Vec2<I>(x * s, y * s); }

	template<typename I>
	I operator*(const Vec2<I> &v) { return x * v.x + y * v.y; }
};

template<typename T>
struct Vec3
{
	T x, y, z;

	Vec3() : x(T()), y(T()), z(T()) {}
	Vec3(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

	template<typename I>
	Vec3<I> operator-() { return Vec3<I>(-v.x, -v.y, -v.z); }
	template<typename I>
	Vec3<I> operator+(const Vec3<I> &v) { return Vec3<I>(x + v.x, y + v.y, z + v.z); }
	template<typename I>
	Vec3<I> operator-(const Vec3<I> &v) { return Vec3<I>(x - v.x, y - v.y, z - v.z); }
	template<typename I>
	Vec3<I> operator*(float s) { return Vec3<I>(x * s, y * s, z * s); }
	template<typename I>
	Vec3<I> operator*(int s) { return Vec3<I>(x * s, y * s, z * s); }
	template<typename I>
	Vec3<I> cross(const Vec3<I> &v)
	{ return Vec3<I>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

	template<typename I>
	I operator*(const Vec3<I> &v) { return x * v.x + y * v.y + z * v.z; }
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;