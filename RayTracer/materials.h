#pragma once
#include "utility.h"

enum MaterialType
{
	DIFFUSE,
	REFLECTIVE,
	REFRACTIVE,
	GLASSLIKE = REFLECTIVE | REFRACTIVE
};

struct Material
{
	MaterialType type;
	Vec3f ambient;
	Vec3f diffuse;
	Vec3f specular;
	Vec3f emission;
	float shininess;
	float refractionIndex;
};

const Material glass =
{
	GLASSLIKE,
	Vec3f(0.0f, 0.0f, 0.0f) * 255,
	Vec3f(0.588235f, 0.670588f, 0.729412f) * 255,
	Vec3f(0.9f, 0.9f, 0.9f) * 255,
	Vec3f(0.0f, 0.0f, 0.0f) * 255,
	96.0f,
	1.5f
};

const Material orange
{
	DIFFUSE,
	Vec3f(0.0f, 0.0f, 0.0f) * 255,
	Vec3f(0.992157f, 0.513726f, 0.0f) * 255,
	Vec3f(0.0225f, 0.0225f, 0.0225f) * 255,
	Vec3f(0.0f, 0.0f, 0.0f) * 255,
	12.8f,
	0.0f
};

const Material white
{
	DIFFUSE,
	Vec3f(0.0f, 0.0f, 0.0f) * 255,
	Vec3f(0.992157f, 0.992157f, 0.992157f) * 255,
	Vec3f(0.0225f, 0.0225f, 0.0225f) * 255,
	Vec3f(0.0f, 0.0f, 0.0f) * 255,
	12.8f,
	0.0f
};

const Material red
{
	DIFFUSE,
	Vec3f(0.0, 0.0, 0.0) * 255,
	Vec3f(1.0, 0.0, 0.0) * 255,
	Vec3f(0.0225, 0.0225, 0.0225) * 255,
	Vec3f(0.0, 0.0, 0.0) * 255,
	12.8f,
	0.0f
};

const Material violet
{
	DIFFUSE,
	Vec3f(0.0, 0.0, 0.0),
	Vec3f(0.635294, 0.0, 1.0) * 255,
	Vec3f(0.0225, 0.0225, 0.0225) * 255,
	Vec3f(0.0, 0.0, 0.0),
	12.8f,
	0.0f
};