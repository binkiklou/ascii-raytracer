#include "raycast.hpp"

#include <iostream>

namespace raycaster
{
    raycast_result ray(
        vector3 dir,
        int limit,
        std::vector<object*> group
    )
    {
        raycast_result result;

        for(int i = 0; i < limit; i++)
        {
            if(result.hit)
            {
                break;
            }
            
            vector3 lpos;

            lpos.x = dir.x * i;
            lpos.y = dir.y * i;
            lpos.z = dir.z * i;

            for(object* obj : group)
            {
                if(result.hit)
                {
                    break;
                }

                vector3 tpos = obj->position;// Target position

                if(
                    abs(tpos.x - lpos.x) <= 0.1 && 
                    abs(tpos.y - lpos.y) <= 0.1 && 
                    abs(tpos.z - lpos.z) <= 0.1
                    )
                {
                    std::vector<vector3> gvox = obj->voxels; // global voxels;

                    for(vector3& vox : gvox)
                    {
                        vox.x += obj->position.x;
                        vox.y += obj->position.y;
                        vox.z += obj->position.z;
                    }

                    for(int n = 0; n < gvox.size(); n++)
                    {
                        vector3 vox = gvox.at(n);

                        if(
                            // X
                            lpos.x >= (vox.x - 1) && lpos.x <= (vox.x + 1) &&
                            // Y
                            lpos.y >= (vox.y - 1) && lpos.y <= (vox.y + 1) &&
                            // Z
                            lpos.z >= (vox.z - 1) && lpos.z <= (vox.z + 1)
                        )
                        {
                            //std::cout<<"Hit something at:["<<lpos.x<<","<<lpos.y<<","<<lpos.z<<"]"<<std::endl;

                            result.hit_pos = vector3(lpos.x,lpos.y,lpos.z);
                            result.limit = i;
                            result.hit = true;
                            float w2 = obj->on_hit(n).w;
                            result.w = w2;
                        }
                    }
                }
            }
        }

        return result;
    }
}