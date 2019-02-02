#include <iostream>
#include <vector>
#include "geometry.h"
#include <fstream>
#include <sstream>
#include <tuple>

#define PI 3.1415926f
#define WIDTH 1280
#define HEIGHT 720
#define FOV PI/2
#define BG Vec3f(0, 0xCC, 0xFF);

std::vector<Vec3f> framebuffer = std::vector<Vec3f>(WIDTH * HEIGHT);

// Define scene
#pragma region Scene
Vec3f eyeOrigin;
Plane plane(Vec3f(0, -30, 35), Vec3f(0, 1, 0), 40, 40, orange);
Sphere sphere1(Vec3f(20, 20, 20), 15, glass);
Sphere sphere2(Vec3f(0, 20, 15), 10, glass);
Sphere sphere3(Vec3f(10, 10, 30), 17, red);
Light light(Vec3f(25, 35, 40), Vec3f(1.0f, 1.0f, 1.0f), .7f);

Plane* planes[]{ &plane };
Sphere* spheres[]{ &sphere1, &sphere2, &sphere3 };
Light* lights[]{ &light };
#pragma endregion

void render();
Vec3f cast_ray(Vec3f &origin, Vec3f &dir, Light* lights[], unsigned int depth);

int main()
{
	render();

    return 0;
}

void render()
{
	// TODO: Ray casting recursive function and render call function.
}

std::tuple<Object*, Vec3f> closest_hit(Vec3f &origin, Vec3f &dir)
{
	std::vector<Object*> hit = std::vector<Object*>();

	float minDistance = 99999;
	Object* closest = nullptr;
	Vec3f closestIntersect = Vec3f();

	for (Sphere* &sphere : spheres)
	{
		Vec3f intersection = sphere->ray_intersect(origin, dir);
		Vec3f difference = intersection - origin;
		float distance = difference.length();

		if (distance < minDistance && intersection != Vec3f())
		{
			minDistance = distance;
			closest = sphere;
			closestIntersect = intersection;
		}
	}

	for (Plane* &plane : planes)
	{
		Vec3f intersection = plane->ray_intersect(origin, dir);
		Vec3f difference = intersection - origin;
		float distance = difference.length();

		if (distance < minDistance && intersection != Vec3f())
		{
			minDistance = distance;
			closest = plane;
			closestIntersect = intersection;
		}
	}

	return { closest, closestIntersect };
}

Vec3f cast_ray(Vec3f &origin, Vec3f &dir, Light* lights[], unsigned int depth)
{
	if (depth > 4) return BG;

	std::tuple<Object*, Vec3f> closest = closest_hit(origin, dir);

	if (std::get<0>(closest) != nullptr)
	{
		
	}
}