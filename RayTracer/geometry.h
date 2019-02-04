#pragma once
#include "materials.h"
#include <cmath>

struct Light
{
	Vec3f pos;
	Vec3f color;
	float intensity;

	Light(Vec3f pos, Vec3f color, float intensity) : pos(pos), color(color), intensity(intensity) {}
};

struct Object
{
	Vec3f pos;
	Material mat;

	Object(Vec3f pos, Material mat) : pos(pos), mat(mat) {}

	virtual Vec3f ray_intersect(const Vec3f &origin, const Vec3f &dir) const = 0;
};

struct Sphere : public Object
{
	float radius;

	Sphere(Vec3f pos, float radius, Material mat) : Object(pos, mat), radius(radius) {}

	Vec3f ray_intersect(const Vec3f &origin, const Vec3f &dir) const
	{
		Vec3f rayToCenter = origin - pos;
		float rtcLength = rayToCenter.length();

		float dValue = (rayToCenter * dir) * (rayToCenter * dir) - (rtcLength * rtcLength - radius * radius);
		float intersectionParam1 = 0;
		float intersectionParam2 = 0;

		if (dValue >= 0)
		{
			intersectionParam1 = -(rayToCenter * dir) + sqrt(dValue);
			intersectionParam2 = -(rayToCenter * dir) - sqrt(dValue);

			if (intersectionParam1 >= 0 && intersectionParam2 >= 0)
				return origin + std::fmaxf(intersectionParam1, intersectionParam2) * dir;
			else if (intersectionParam1 >= 0)
				return origin + intersectionParam1 * dir;
			else if (intersectionParam2 >= 0)
				return origin + intersectionParam2 * dir;
			else
				return Vec3f();
		}
		else
		{
			return Vec3f();
		}
	}
};

struct Plane : public Object
{
	Vec3f verts[4];
	Vec3f normal;
	unsigned int width, depth;

	Plane(Vec3f pos, Vec3f normal, unsigned int width, unsigned int depth, Material mat)
		: Object(pos, mat), width(width), depth(depth), normal(normal.normalize())
	{
		verts[0] = Vec3f(pos.x - width / 2, pos.y, pos.z + depth / 2);
		verts[1] = Vec3f(pos.x + width / 2, pos.y, pos.z + depth / 2);
		verts[2] = Vec3f(pos.x + width / 2, pos.y, pos.z - depth / 2);
		verts[3] = Vec3f(pos.x - width / 2, pos.y, pos.z - depth / 2);
	}

	Vec3f ray_intersect(const Vec3f &origin, const Vec3f &dir) const
	{
		float dot = dir * normal;

		if (dot != 0)
		{
			float param = (pos - origin) * normal / dot;

			if (param > 0)
				return param * dir + origin;
			else
				return Vec3f();
		}
		else
		{
			return Vec3f();
		}

		return Vec3f();
	}
};

struct Triangle
{
	Vec3f verts[3];

	Triangle(Vec3f v1, Vec3f v2, Vec3f v3)
		: verts{ v1, v2, v3 }
	{}

	Triangle() : verts{ Vec3f(.0f, .0f, .0f), Vec3f(.0f, .0f, .0f), Vec3f(.0f, .0f, .0f) } {}
};

struct Mesh
{
	Triangle triangles[];

	// TODO: obj parser lmlao
	Mesh()
	{

	}
};