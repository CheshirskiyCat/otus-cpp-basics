#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(){} 
    Ball(const Point& center, const Velocity& velocity, const Color& color);
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    void setColor(const Color& color);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
private:
    Velocity velocity;
    Point center;
    Color color;
    const int radius = 10;
};
