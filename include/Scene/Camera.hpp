#pragma once

#include <cstdint>
#include <cmath>
#include <vector>

#include "Scene/Object.hpp"

namespace mpt
{
    class Camera : public Object
    {
    public:
        Camera();
        Camera(uint32_t width, uint32_t height, float fov);

        inline void move(Vec3f distance) { m_position += distance; };

        inline void setPosition(Vec3f position) { m_position = position; };
        inline void setLookat(Vec3f lookat) { m_lookat = lookat; };
        inline void setUp(Vec3f up) { m_upDirection = up; };

        std::vector<Ray> getRays() const;

    private:
        uint32_t m_width;
        uint32_t m_height;
        float m_fov;

        Vec3f m_position;
        Vec3f m_lookat;
        Vec3f m_upDirection;
    };
}