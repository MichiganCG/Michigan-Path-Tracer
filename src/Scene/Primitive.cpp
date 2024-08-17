#include "Scene/Primitive.hpp"

namespace mpt
{
    Triangle::Triangle(Vec3f vertex_one, Vec3f vertex_two, Vec3f vertex_three)
    {
        vertices[0] = vertex_one;
        vertices[1] = vertex_two;
        vertices[2] = vertex_three;
    }

    void Triangle::setPosition(const Vec3f& position)
    {
        /*
        Vec3 difference = m_position - position;
        apply translation using the difference
        */

        m_position = position;
    }

    void Triangle::setRotation(const Vec3f& rotation)
    {
        /*
        Vec3 difference = m_rotation - rotation;
        create a quaternion
        apply rotation using the quaternion
        */

        m_rotation = rotation;
    }
}