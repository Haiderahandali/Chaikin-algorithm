#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <math.h>

struct Vector2d
{
public:
    Vector2d();
    Vector2d(float x, float y);
    ~Vector2d() {};
    float xPos;
    float yPos;

    //--------------------- function here -----------------//

    void setX(float const& X);
    void setY(float const& Y);
    float dot(Vector2d other) const;
    float length() const;
    float getX() const { return xPos; }
    float getY() const { return yPos; }
    void normalize();

    //-------------overloading --------------//
    Vector2d& operator=(Vector2d&);
    Vector2d& operator=(Vector2d const&);

    friend std::ostream& operator<<(std::ostream& os, Vector2d const& vec);
};

#endif
Vector2d& operator/=(Vector2d& vec2d, float const& other);
Vector2d& operator+=(Vector2d& vec, Vector2d const&);
Vector2d& operator+=(Vector2d& vec, float const&);
Vector2d operator-(Vector2d const& vec, Vector2d const&);
Vector2d operator-(Vector2d const& vec, float const&);
Vector2d operator/(Vector2d const&, float const&);
Vector2d& operator-=(Vector2d& vec, float const&);
Vector2d& operator-=(Vector2d& vec, Vector2d const&);
Vector2d const operator+(Vector2d const&, Vector2d const&);

/* Vector2d

















        */