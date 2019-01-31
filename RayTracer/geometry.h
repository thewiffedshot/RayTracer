#pragma once
#include "materials.h"

struct Light
{
	Vec3f pos;
	Vec3f color;
	float intensity;

	Light(Vec3f pos, Vec3f color, float intensity) : pos(pos), color(color), intensity(intensity) {}
};

struct Sphere
{
	Vec3f pos;
	unsigned int radius;
	Material mat;

	Sphere(Vec3f pos, unsigned int radius, Material mat) : pos(pos), radius(radius), mat(mat) {}
};

struct Plane
{
	Vec3f verts[4];

	Plane(Vec3f pos, unsigned int width, unsigned int depth)
	{
		verts[0] = Vec3f(pos.x - width / 2, pos.y, pos.z + depth / 2);
		verts[1] = Vec3f(pos.x + width / 2, pos.y, pos.z + depth / 2);
		verts[2] = Vec3f(pos.x + width / 2, pos.y, pos.z - depth / 2);
		verts[3] = Vec3f(pos.x - width / 2, pos.y, pos.z - depth / 2);
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