#pragma once
#include <cmath>
#include <iostream>

template<typename T>
struct Vec2
{
	T x, y;
	
	Vec2() : x(T()), y(T()) {}
	Vec2(T X, T Y) : x(X), y(Y) {}

	friend Vec2<T> operator-(Vec2<T> &v) { return Vec2<T>(-v.x, -v.y); }
	friend Vec2<T> operator+(const Vec2<T> &v1, const Vec2<T> &v2) { return Vec2<T>(v1.x + v2.x, v1.y + v2.y); }
	friend Vec2<T> operator-(const Vec2<T> &v1, const Vec2<T> &v2) { return Vec2<T>(v1.x - v2.x, v1.y - v2.y); }

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

	friend T operator*(const Vec2<T> &v1, const Vec2<T> &v2) { return v1.x * v2.x + v1.y * v2.y; }

	void print() { std::cout << "(" << x << ", " << y << ")\n"; }
};

template<typename T>
struct Vec3
{
	T x, y, z;

	Vec3() : x(T()), y(T()), z(T()) {}
	Vec3(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

	friend Vec3<T> operator-(Vec3<T> &v) { return Vec3<T>(-v.x, -v.y, -v.z); }
	friend Vec3<T> operator+(const Vec3<T> &v1, const Vec3<T> &v2) { return Vec3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
	friend Vec3<T> operator-(const Vec3<T> &v1, const Vec3<T> &v2) { return Vec3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }

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

	friend Vec3<T> cross(const Vec3<T> &v1, const Vec3<T> &v2) { return Vec3<T>(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x); }
	friend T operator*(const Vec3<T> &v1, const Vec3<T> &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

	void print() { std::cout << "(" << x << ", " << y << ", " << z << ")\n"; }
};

typedef Vec2<short> Vec2s;
typedef Vec2<float> Vec2f;
typedef Vec3<short> Vec3s;
typedef Vec3<float> Vec3f;