#pragma once
#include <cmath>
#include <iostream>

template<typename T>
struct Vec2
{
	T x, y;
	
	Vec2() : x(T()), y(T()) {}
	Vec2(T X, T Y) : x(X), y(Y) {}

	template<typename I>
	friend Vec2<I> operator-(Vec2<I> &v) { return Vec2<I>(-v.x, -v.y); }
	template<typename I>
	friend Vec2<I> operator+(const Vec2<I> &v1, const Vec2<I> &v2) { return Vec2<I>(v1.x + v2.x, v1.y + v2.y); }
	template<typename I>
	friend Vec2<I> operator-(const Vec2<I> &v1, const Vec2<I> &v2) { return Vec2<I>(v1.x - v2.x, v1.y - v2.y); }

	friend Vec2<T> operator*(Vec2<T> v, float s) { return Vec2<T>(v.x * s, v.y * s); }
	friend Vec2<T> operator*(float s, Vec2<T> v) { return Vec2<T>(v.x * s, v.y * s); }

	friend Vec2<T> operator*(Vec2<T> v, int s) { return Vec2<T>(v.x * s, v.y * s); }
	friend Vec2<T> operator*(int s, Vec2<T> v) { return Vec2<T>(v.x * s, v.y * s); }

	friend Vec2<T> operator*(Vec2<T> v, double s) { return Vec2<T>(v.x * s, v.y * s); }
	friend Vec2<T> operator*(double s, Vec2<T> v) { return Vec2<T>(v.x * s, v.y * s); }

	friend Vec2<T> operator/(Vec2<T> v, float s) { return Vec2<T>(v.x / s, v.y / s); }
	friend Vec2<T> operator/(float s, Vec2<T> v) { return Vec2<T>(v.x / s, v.y / s); }

	friend Vec2<T> operator/(Vec2<T> v, int s) { return Vec2<T>(v.x / s, v.y / s); }
	friend Vec2<T> operator/(int s, Vec2<T> v) { return Vec2<T>(v.x / s, v.y / s); }

	friend Vec2<T> operator/(Vec2<T> v, double s) { return Vec2<T>(v.x / s, v.y / s); }
	friend Vec2<T> operator/(double s, Vec2<T> v) { return Vec2<T>(v.x / s, v.y / s); }

	bool operator!=(const Vec2<T> &v) { return x == v.x && y == v.y; }

	T length() { return sqrt(x * x + y * y); }
	Vec2<T> normalize() { return Vec2<T>(x / length(), y / length()); }

	template<typename I>
	friend I operator*(const Vec2<I> &v1, const Vec2<I> &v2) { return v1.x * v2.x + v1.y * v2.y; }

	void print() { std::cout << "(" << x << ", " << y << ")\n"; }
};

template<typename T>
struct Vec3
{
	T x, y, z;

	Vec3() : x(T()), y(T()), z(T()) {}
	Vec3(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

	template<typename I>
	friend Vec3<I> operator-(Vec3<I> &v) { return Vec3<I>(-v.x, -v.y, -v.z); }
	template<typename I>
	friend Vec3<I> operator+(const Vec3<I> &v1, const Vec3<I> &v2) { return Vec3<I>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
	template<typename I>
	friend Vec3<I> operator-(const Vec3<I> &v1, const Vec3<I> &v2) { return Vec3<I>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }

	friend Vec3<T> operator*(Vec3<T> v, float s) { return Vec3<T>(v.x * s, v.y * s, v.z * s); }
	friend Vec3<T> operator*(float s, Vec3<T> v) { return Vec3<T>(v.x * s, v.y * s, v.z * s); }

	friend Vec3<T> operator*(Vec3<T> v, int s) { return Vec3<T>(v.x * s, v.y * s, v.z * s); }
	friend Vec3<T> operator*(int s, Vec3<T> v) { return Vec3<T>(v.x * s, v.y * s, v.z * s); }

	friend Vec3<T> operator*(Vec3<T> v, double s) { return Vec3<T>(v.x * s, v.y * s, v.z * s); }
	friend Vec3<T> operator*(double s, Vec3<T> v) { return Vec3<T>(v.x * s, v.y * s, v.z * s); }

	friend Vec3<T> operator/(Vec3<T> v, float s) { return Vec3<T>(v.x / s, v.y / s, v.z / s); }
	friend Vec3<T> operator/(float s, Vec3<T> v) { return Vec3<T>(v.x / s, v.y / s, v.z / s); }

	friend Vec3<T> operator/(Vec3<T> v, int s) { return Vec3<T>(v.x / s, v.y / s, v.z / s); }
	friend Vec3<T> operator/(int s, Vec3<T> v) { return Vec3<T>(v.x / s, v.y / s, v.z / s); }

	friend Vec3<T> operator/(Vec3<T> v, double s) { return Vec3<T>(v.x / s, v.y / s, v.z / s); }
	friend Vec3<T> operator/(double s, Vec3<T> v) { return Vec3<T>(v.x / s, v.y / s, v.z / s); }

	bool operator!=(const Vec3<T> &v) { return x == v.x && y == v.y && z == v.z; }

	T length() { return sqrt(x * x + y * y + z * z); }
	Vec3<T> normalize() { return Vec3<T>(x / length(), y / length(), z / length()); }

	template<typename I>
	Vec3<I> cross(const Vec3<I> &v)
	{ return Vec3<I>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }

	template<typename I>
	friend I operator*(const Vec3<I> &v1, const Vec3<I> &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

	void print() { std::cout << "(" << x << ", " << y << ", " << z << ")\n"; }
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;