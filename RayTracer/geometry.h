#pragma once
#include "materials.h"

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
	unsigned int radius;

	Sphere(Vec3f pos, unsigned int radius, Material mat) : Object(pos, mat), radius(radius) {}

	Vec3f ray_intersect(const Vec3f &origin, const Vec3f &dir) const
	{
		return Vec3f(); // TODO
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
		return Vec3f(); // TODO
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