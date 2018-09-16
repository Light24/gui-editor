#include "vector2f.h"


Vector2f::Vector2f(float in_X, float in_Y) : x(in_X), y(in_Y)
{

}

Vector2f::Vector2f(const Vector2f &in_Vec)
{
	*this = in_Vec;
}

const Vector2f &Vector2f::operator=(const Vector2f &in_Vec)
{
	x = in_Vec.x;
	y = in_Vec.y;

	return *this;
}

bool Vector2f::operator==(const Vector2f &in_Vec) const
{
	return ((x == in_Vec.x) && (y == in_Vec.y));
}
