#include "Vector.hpp"

Vector2d::Vector2d(float x, float y)
    : xPos { x }
    , yPos { y }
{
}

Vector2d::Vector2d()
{
    xPos = 0;
    yPos = 0;
}

Vector2d& Vector2d::operator=(Vector2d const& vec)
{
    this->xPos = vec.xPos;
    this->yPos = vec.yPos;
    return *this;
}

void Vector2d::setX(float const& X)
{
    xPos = X;
}

void Vector2d::setY(const float& Y)
{
    yPos = Y;
}

//---------------------------------- Public methods -------------------//
//---------------------------------------------------------------------//

void Vector2d::normalize()
{
    auto l = this->length();
    if (l > 0)
    {
        this->xPos /= l;
        this->yPos /= l;
    }
}

float Vector2d::dot(Vector2d other) const
{

    return (this->xPos * other.xPos) + (this->yPos * other.yPos);
}
float Vector2d::length() const
{
    return sqrt(this->xPos * this->xPos + this->yPos * this->yPos);
}

//--------------------------- Overloading Operator for Vector2D -------------------//
//----------------------------- BEGIN ---------------------//
Vector2d const operator+(Vector2d const& vec2d, Vector2d const& other)
{
    return { vec2d.xPos + other.xPos, vec2d.yPos + other.yPos };
}

Vector2d operator-(Vector2d const& vec2d, Vector2d const& other)
{
    return { vec2d.xPos - other.xPos, vec2d.yPos - other.yPos };
}

Vector2d operator-(Vector2d const& vec, float const& other)
{
    return { vec.xPos - other, vec.yPos - other };
}

Vector2d operator+(Vector2d const& vec2d, float const other)
{
    return { vec2d.xPos + other, vec2d.yPos + other };
}
std::ostream& operator<<(std::ostream& os, Vector2d const& vec)
{
    os << vec.xPos << ' ' << vec.yPos;
    return os;
}

Vector2d operator*(Vector2d const& vec2d, float other)
{
    return { vec2d.xPos * other, vec2d.yPos * other };
}

Vector2d operator/(Vector2d const& vec2d, float const& other)
{
    return { vec2d.xPos / other, vec2d.yPos / other };
}
Vector2d& operator/=(Vector2d& vec2d, float const& other)
{
    vec2d.xPos /= other, vec2d.yPos /= other;
    return vec2d;
}

Vector2d& operator+=(Vector2d& vec, Vector2d const& other)
{
    vec.xPos += other.xPos, vec.yPos += other.yPos;
    return vec;
}

Vector2d& operator+=(Vector2d& vec, float const& other)
{
    vec.xPos += other, vec.yPos += other;
    return vec;
}
Vector2d& operator-=(Vector2d& vec, float const& other)
{
    vec.xPos -= other, vec.yPos -= other;
    return vec;
}
Vector2d& operator-=(Vector2d& vec, Vector2d const& other)
{
    vec.xPos -= other.xPos, vec.yPos -= other.yPos;
    return vec;
}
//--------------------------- Overloading Operator for Vector2D -------------------//
//----------------------------- ENDED ---------------------//