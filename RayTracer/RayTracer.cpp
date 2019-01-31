#include <iostream>
#include <vector>
#include "utility.h"
#include <fstream>
#include <sstream>

#define WIDTH 1280
#define HEIGHT 720

int main()
{
	Vec3f v1(2, 2, 1);
	Vec3f v2(3, 1, 4);

	Vec3f v = v1.cross(v2);

	int i = 0;

	std::cout << v.x  << ", " << v.y << ", " << v.z;
	std::cin >> i;

    return 0;
}

struct Sphere
{
	Vec3f pos;
	unsigned int radius;

	Sphere(Vec3f pos, unsigned int radius) : pos(pos), radius(radius) {}
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

Sphere sphere1(Vec3f(20, 20, 20), 15);


