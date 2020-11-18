#include "objects.hpp"

#include <cmath>

// ---== BASE OBJECT ==---

vector3 object::get_forward()
{
    return vector3(
        std::cos(this->yaw) * std::cos(this->pitch),
        std::sin(this->yaw) * std::cos(this->pitch),
        std::sin(this->pitch)
    );
}

void object::rotate(int rx, int ry, int rz)
{
    this->roll += rx;
    this->pitch += ry;
    this->yaw += rz;
}

raycast_result object::on_hit(int n)
{
    raycast_result result;

    result.w = 1;

    return result;
}

// ---== WALL ==---
raycast_result wall::on_hit(int n)
{
    raycast_result result;

    if((n % 2) == 1)
    {
        result.w = 1;
    }
    else
    {
        result.w = 1;
        //result.w = 0.3;
    }

    return result;
}