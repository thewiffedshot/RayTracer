#include <iostream>
#include <vector>
#include "geometry.h"
#include <fstream>
#include <sstream>
#include <tuple>
#include <cmath>

#define PI 3.1415926f
#define FOV PI/2
#define BG Vec3f(0, 0xCC, 0xFF)
#define MAX_DEPTH 4
#define EYE Vec3f(0, 0, 0)
#define LOOK Vec3f(0, 0, 1)
#define UP Vec3f(0, 1, 0) // Must be normalized.

int width = 1280,
	height = 720;

int fov = 90;

std::string filename = "render.ppm";

std::vector<Vec3s> framebuffer;

// Define scene
#pragma region Scene
Plane plane(Vec3f(0, -4, 10), Vec3f(0, 1, 0), 40, 40, orange);
Sphere sphere1(Vec3f(-10, 7, 15), 3.5, orange);
Sphere sphere2(Vec3f(7, 1.5, 20), 3, violet);
Sphere sphere3(Vec3f(13.5, 5, 15), 4, red);
Light light1(Vec3f(25, 35, 40), Vec3f(1.0f, 1.0f, 1.0f), 7.f);
Light light2(Vec3f(-30, 40, 60), Vec3f(1.0f, 1.0f, 1.0f), 3.5f);

Plane* planes[]{ &plane };
Sphere* spheres[]{ &sphere1, &sphere2, &sphere3 };
std::vector<Light*> lights { &light1, &light2 };
#pragma endregion

void render();
Vec3f cast_ray(const Vec3f &origin, const Vec3f &dir, std::vector<Light*> lights, unsigned int depth);

int main(int argCount, char* args[]) // lamao
{
	std::vector<std::string> commandStack = std::vector<std::string>();
	std::vector<std::string> parameterStack = std::vector<std::string>();

	if (argCount > 1)
	{
		for (int i = 1; i < argCount; ++i)
		{
			std::string arg = "";

			for (char* j = args[i]; *j != '\0'; ++j)
			{
				arg += *j;
			}

			if (arg[0] == '-')
				commandStack.push_back(arg.substr(1));
			else
				parameterStack.push_back(arg);

		}

		if (commandStack.size() != parameterStack.size())
		{
			int i;

			std::cout << "Wrong parameters.\n";
			std::cin >> i;
			return 0;
		}

		int iterator = 0;

		try
		{
			for (const auto &c : commandStack)
			{
				if (c == "w")
				{
					width = std::stoi(parameterStack[iterator++]);
				}
				else if (c == "h")
				{
					height = std::stoi(parameterStack[iterator++]);
				}
				else if (c == "fov")
				{
					fov = std::stoi(parameterStack[iterator++]) / 180 * PI;
				}
				else if (c == "f")
				{
					filename = parameterStack[iterator++];
				}
			}
		}
		catch (_exception)
		{
			// Do nothing.
		}
	}

	framebuffer = std::vector<Vec3s>(width * height);

	render();
	
    return 0;
}

void render()
{
	Vec3f lookDir = LOOK.normalize();
	Vec3f sideVector = cross(lookDir, UP).normalize();

	float aspectRatio = width >= height ? width / (float)height : height / (float)width;

#pragma omp parallel for
	for (int h = 0; h < height; ++h)
		for (int w = 0; w < width; ++w)
		{
			float Px = ((2 * ((w + 0.5) / (float)width)) - 1) * tan(FOV / 2) * aspectRatio;
			float Py = (1 - (2 * ((h + 0.5) / (float)height))) * tan(FOV / 2);

			Vec3f ray = (Vec3f(Px, Py, 1) - EYE).normalize();

			Vec3f color = cast_ray(EYE, ray, lights, 4);

			framebuffer[h * width + w] = Vec3s(color.x, color.y, color.z);
		}

	std::ofstream stream(filename);

	// Image header
	stream << "P3" << std::endl;							  // Format RGB
	stream << width << " " << height << std::endl;		      // Size
	stream << "255" << std::endl;							  // Color maxvalue

	for (auto &c : framebuffer)
	{
		stream << c.x << " " << c.y << " " << c.z << std::endl;
	}
}

std::tuple<Object*, Vec3f, Vec3f> closest_hit(const Vec3f &origin, const Vec3f &dir)
{
	float minDistance = std::numeric_limits<float>::max();
	Object* closest = nullptr;
	Vec3f closestIntersect = Vec3f();

	for (Sphere* &sphere : spheres)
	{
		Vec3f intersection = sphere->ray_intersect(origin, dir);
		Vec3f difference = intersection - origin;
		float distance = difference.length();

		if (distance < minDistance && intersection.x != 0 && intersection.y != 0 && intersection.z != 0)
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

		if (distance < minDistance && intersection.x != 0 && intersection.y != 0 && intersection.z != 0)
		{
			minDistance = distance;
			closest = plane;
			closestIntersect = intersection;
		}
	}

	return { closest, closestIntersect, closest == nullptr ? Vec3f() : closest->getNormal(closestIntersect) };
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

Vec3f cast_ray(const Vec3f &origin, const Vec3f &dir, std::vector<Light*> lights, unsigned int depth)
{
	std::tuple<Object*, Vec3f, Vec3f> closest = closest_hit(origin, dir);
	Object* objectHit = std::get<0>(closest);

	if (depth > MAX_DEPTH || objectHit == nullptr) return BG;

	Vec3f color = Vec3f();

	switch (objectHit->mat.type)
	{
	case DIFFUSE:
		for (auto &light : lights)
		{
		   color = color + (objectHit->mat.diffuse / PI) * 
			                light->intensity * 
			                std::fmaxf(.0f, ((light->pos - std::get<1>(closest)).normalize() * 
							std::get<2>(closest)));
		}
		return color;
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