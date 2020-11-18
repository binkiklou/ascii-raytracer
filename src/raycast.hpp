#pragma once

#include "objects.hpp"

namespace raycaster
{
    raycast_result ray(
        vector3,
        int,
        std::vector<object*>);
};