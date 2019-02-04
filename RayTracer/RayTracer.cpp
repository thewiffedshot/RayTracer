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
#define MAX_DEPTH 4

std::vector<Vec3s> framebuffer = std::vector<Vec3s>(WIDTH * HEIGHT);

// Define scene
#pragma region Scene
Vec3f eyeOrigin;
Plane plane(Vec3f(0, -30, 35), Vec3f(0, 1, 0), 40, 40, orange);
Sphere sphere1(Vec3f(20, 20, 20), 15, glass);
Sphere sphere2(Vec3f(0, 20, 15), 10, glass);
Sphere sphere3(Vec3f(10, 10, 30), 17, red);
Light light(Vec3f(25, 35, 40), Vec3f(1.0f, 1.0f, 1.0f), 7.f);

Plane* planes[]{ &plane };
Sphere* spheres[]{ &sphere1, &sphere2, &sphere3 };
Light* lights[]{ &light };
#pragma endregion

void render();
Vec3f cast_ray(Vec3f &origin, Vec3f &dir, Light* light, unsigned int depth);

int main()
{
	render();

    return 0;
}

void render()
{
	// TODO: Render call function and framebuffer filling.
}

std::tuple<Object*, Vec3f, Vec3f> closest_hit(Vec3f &origin, Vec3f &dir)
{
	std::vector<Object*> hit = std::vector<Object*>();

	float minDistance = INFINITY;
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

	return { closest, closestIntersect, closest->getNormal(closestIntersect) };
}

Vec3f reflect(const Vec3f &dir, const Vec3f &normal)
{
	return dir - 2 * normal * (dir * normal);
}

Vec3f refract(const Vec3f &dir, const Vec3f &normal, float refractiveIndex1, float refractiveIndex2 = 1.f)
{
	// TODO: Fresnel refraction and critical angle resolution.
	return Vec3f();
}

Vec3f cast_ray(Vec3f &origin, Vec3f &dir, Light* light, unsigned int depth)
{
	std::tuple<Object*, Vec3f, Vec3f> closest = closest_hit(origin, dir);
	Object* objectHit = std::get<0>(closest);

	if (depth > MAX_DEPTH || objectHit == nullptr) return BG;

	switch (objectHit->mat.type)
	{
	case DIFFUSE:
		break;
	case REFLECTIVE:
		break;
	case REFRACTIVE:
		break;
	case GLASSLIKE:
		break;
	default:
		return BG;
		break;
	}
}