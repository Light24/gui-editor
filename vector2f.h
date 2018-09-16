#pragma once

struct Vector2f
{
public:
	Vector2f(float in_X = 0, float in_Y = 0);
	Vector2f(const Vector2f &in_Vec);

	const Vector2f &operator=(const Vector2f &in_Vec);
	bool operator==(const Vector2f &in_Vec) const;

public:
	float x;
	float y;
};
