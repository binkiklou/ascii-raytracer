#pragma once

#include "3d.hpp"

// Very bad fix but eh, it works 
class raycast_result
{
    public:
    vector3 hit_pos;
    int limit;
    float w;
    bool hit = false;
};


class object
{
    public:
    vector3 position;

    vector3 rot_x;
    vector3 rot_y;
    vector3 rot_z;

    std::vector<vector3> voxels;
    std::vector<std::pair<float,vector3>> light_points;

    // Get and Sets
    vector3 get_forward();

    // Functions
    void rotate(int,int,int);

    // Virtual functions
    virtual raycast_result on_hit(int);

    private:
    int roll = 0;
    int pitch = 0;
    int yaw = 0;
};

class light : public object
{
    public:
    float luminosity;
};

class scene
{
    public:
    std::vector<object*> objects;
    std::vector<light*> lights;
};

class wall : public object
{
    raycast_result on_hit(int) override;
};

class camera : public object
{
    public:
    int fov;
};