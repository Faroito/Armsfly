//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef SCENE_HPP
# define SCENE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <set>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "App.hpp"
#include "Camera.hpp"

namespace scene {

    class Scene : public gl_wrapper::App {

        typedef void (scene::Camera::*change_camera_t)();

    public:
        Scene();

        void init();

        void onDraw() override;
        void onMouseScroll(double x, double y) override;

    private:
        void checkKey() override;

    private:
        GLenum _mode = GL_FILL;
//Camera_ptr_t _camera = std::make_unique<Camera>(Camera());

        const std::unordered_map<int, change_camera_t> _keyMap = {
                {GLFW_KEY_W, &scene::Camera::moveForward},
                {GLFW_KEY_S, &scene::Camera::moveBackward},
                {GLFW_KEY_R, &scene::Camera::moveUp},
                {GLFW_KEY_F, &scene::Camera::moveDown},
                {GLFW_KEY_A, &scene::Camera::moveLeft},
                {GLFW_KEY_D, &scene::Camera::moveRight},
                {GLFW_KEY_Q, &scene::Camera::rotateLeft},
                {GLFW_KEY_E, &scene::Camera::rotateRight}
        };
    };
}
#endif /* !SCENE_HPP */
