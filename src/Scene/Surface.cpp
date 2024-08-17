#include "Scene/Surface.hpp"

namespace mpt
{
    void Surface::setPosition(const Vec3f& position)
    {
        for(Triangle& triangle : m_primitives)
        {
            triangle.setPosition(position);
        }

        m_position = position;
    }

    void Surface::setRotation(const Vec3f& rotation)
    {
        for(Triangle& triangle : m_primitives)
        {
            triangle.setRotation(rotation);
        }

        m_rotation = rotation;
    }
}