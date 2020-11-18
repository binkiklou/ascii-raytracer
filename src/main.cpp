#include "io.hpp"

#include "renderer.hpp"

#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    terminal t(80,24);

    camera* cam = new camera;
    cam->fov = 90;
    cam->position = vector3(0,0,0);
    cam->rotate(0,0,0);

    vector3 cf = cam->get_forward();
    //astd::cout<<"["<<cf.x<<","<<cf.y<<","<<cf.z<<"]"<<std::endl;

    wall* w = new wall();

    w->position = vector3(2,0,0);

    w->voxels.push_back(vector3(0,0,0));

    w->rotate(0,0,0);

    light* l = new light;
    l->position = vector3(1,0,0);
    l->luminosity = 10;

    scene* world = new scene();

    world->objects.push_back(cam);
    world->objects.push_back(w);
    
    world->lights.push_back(l);

    cam->fov = 80;
    t.clear();
    
    auto t1 = std::chrono::high_resolution_clock::now();

    renderer::render(cam,world,&t);

    auto t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    std::cout<<"Took "<<duration<<" milliseconds to render."<<std::endl;

    t.draw();
    //std::cout<<"---------------------"<<std::endl;

    return 0;
}