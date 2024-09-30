#include "Scene/Primitive.hpp"

namespace mpt
{
    Triangle::Triangle(Vec3f vertex_one, Vec3f vertex_two, Vec3f vertex_three)
    {
        setVertices(vertex_one, vertex_two, vertex_three);
    }

    void Triangle::setVertices(Vec3f vertex_one, Vec3f vertex_two, Vec3f vertex_three)
    {
        vertices[0] = vertex_one;
        vertices[1] = vertex_two;
        vertices[2] = vertex_three;
    }

    void Triangle::setPosition(const Vec3f& position)
    {
        Vec3f difference = position - m_position;
        for (int32_t i=0;i<3;++i)
        {
            vertices[i] = vertices[i] + difference;
        }
        m_position = position;
    }

    void Triangle::setRotation(const Vec3f& rotation)
    {
        // low priority: implement later
    }

    float Triangle::isHit(const Ray& ray) const
    {
        /*
        implement later after linalg lib is finished

        // Moller Trumbore algorithm
        Vec3f basis_one = -ray.direction
        Vec3f basis_two = vertex[1] - vertex[0] // 0 -> 1
        Vec3f basis_three = vertex[2] - vertex[0] // 0 -> 2

        Mat3f matrix(basis_one, basis_two, basis_three)

        Vec3f output = ray.origin - vertex[0]

        solve (matrix * <t, u, v> = output) using crammer's rule
        matrix_det = matrix.det()

        t = Mat3f(output, basis_two, basis_three).det() / matrix_det
        u = Mat3f(basis_one, output, basis_three).det() / matrix_det
        v = Mat3f(basis_one, basis_two, output).det() / matrix_det

        return t if (u + v = 1) AND (u > 0) AND (v > 0)
        return -1 otherwise since ray cannot go backwards
        */
        return -1.f;
    }
}