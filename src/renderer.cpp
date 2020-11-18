#include "renderer.hpp"

#include "raycast.hpp"

#include <cmath>
#include <iostream>

#define rad * (3.1415/180)

void renderer::render(
    camera* cam,
    scene* s,
    terminal* t
)
{
    int tw = t->get_width();
    int th = t->get_height();

    int a_rx = cam->fov / tw;
    int a_ry = cam->fov / th;

    std::cout<<a_rx<<std::endl;

    for(int y = 0; y < th; y++)
    {
        for(int x = 0; x < tw; x++)
        {
            float pitch = ((a_rx * x)) - (cam->fov / 2);
            float yaw = ((a_ry * y)) - (cam->fov / 2);


            raycast_result result = raycaster::ray(
                vector3(
                    std::cos(yaw rad)*std::cos(pitch rad),
                    std::sin(yaw rad)*std::cos(pitch rad),
                    std::sin(pitch rad)
                ),
                6,
                s->objects
            );

            float p = 0;

            if(result.hit)
            {
                p = result.w;
            }

            char c;

            if(p == 0)
            {
                c = ' ';
            }
            else if(p > 0 && p < 0.3)
            {
                c = '.';
            }
            else if(p >= 0.3 && p < 0.6)
            {
                c = ':';
            }
            else if(p >= 0.6 && p < 1)
            {
                c = '=';
            }
            else
            {
                c = '#';
            }

            t->set_char(x,y,c);
        }
    }
}