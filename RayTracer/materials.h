#pragma once
#include "utility.h"

struct Material
{
	Vec3f ambient;
	Vec3f diffuse;
	Vec3f specular;
	Vec3f emission;
	float shininess;
	float refractionIndex;
};

const Material glass =
{
	Vec3f(0.0f, 0.0f, 0.0f),
	Vec3f(0.588235f, 0.670588f, 0.729412f),
	Vec3f(0.9f, 0.9f, 0.9f),
	Vec3f(0.0f, 0.0f, 0.0f),
	96.0f,
	1.5f
};