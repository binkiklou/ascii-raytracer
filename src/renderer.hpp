#pragma once

#include "io.hpp"
#include "objects.hpp"

#include <vector>

namespace renderer
{
    void render(
        camera* cam,
        scene* s,
        terminal* t
    );
}