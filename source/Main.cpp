//
// Created by Timothée Couble on 17/10/2019.
//

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "scene/Scene.hpp"

int main(int argc, const char ** argv) {
    stbi_set_flip_vertically_on_load(true);
    scene::Scene app;

    app.start();
    return 0;
}
