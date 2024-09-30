#include "Scene/Surface.hpp"

namespace mpt
{
    Cube::Cube()
        : m_position{ 0.f, 0.f, 0.f }, m_size{ 1.f, 1.f, 1.f }
    {
        createCube();
    }

    Cube::Cube(Vec3f position, Vec3f size)
        : m_position{ position }, m_size{ size }
    {
        createCube();
    }

    const std::vector<Triangle>& Cube::getTriangles() const
    {
        return m_primitives;
    }

    void Cube::createCube()
    {
        // define the vertices
        Vec3f vertex_ftl = { // front top left vertex
            m_position.x - m_size.x / 2.f,
            m_position.y + m_size.y / 2.f,
            m_position.z + m_size.z / 2.f
        };
        Vec3f vertex_ftr = { // front top right vertex
            m_position.x + m_size.x / 2.f,
            m_position.y + m_size.y / 2.f,
            m_position.z + m_size.z / 2.f
        };
        Vec3f vertex_fbl = { // front bottom left vertex
            m_position.x - m_size.x / 2.f,
            m_position.y - m_size.y / 2.f,
            m_position.z + m_size.z / 2.f
        };
        Vec3f vertex_fbr = { // front bottom right vertex
            m_position.x + m_size.x / 2.f,
            m_position.y - m_size.y / 2.f,
            m_position.z + m_size.z / 2.f
        };
        Vec3f vertex_btl = { // back top left vertex
            m_position.x - m_size.x / 2.f,
            m_position.y + m_size.y / 2.f,
            m_position.z - m_size.z / 2.f
        };
        Vec3f vertex_btr = { // back top right vertex
            m_position.x + m_size.x / 2.f,
            m_position.y + m_size.y / 2.f,
            m_position.z - m_size.z / 2.f
        };
        Vec3f vertex_bbl = { // back bottom left vertex
            m_position.x - m_size.x / 2.f,
            m_position.y - m_size.y / 2.f,
            m_position.z - m_size.z / 2.f
        };
        Vec3f vertex_bbr = { // back bottom right vertex
            m_position.x + m_size.x / 2.f,
            m_position.y - m_size.y / 2.f,
            m_position.z - m_size.z / 2.f
        };

        // create the faces
        if (m_primitives.size() < 12)
            m_primitives.resize(12);

        // front face
        m_primitives[0].setVertices(vertex_ftl, vertex_ftr, vertex_fbr);
        m_primitives[1].setVertices(vertex_ftl, vertex_fbr, vertex_fbl);
        // back face
        m_primitives[2].setVertices(vertex_btr, vertex_btl, vertex_bbl);
        m_primitives[3].setVertices(vertex_btr, vertex_bbl, vertex_bbr);
        // left face
        m_primitives[4].setVertices(vertex_btl, vertex_ftl, vertex_fbl);
        m_primitives[5].setVertices(vertex_btl, vertex_fbl, vertex_bbl);
        // right face
        m_primitives[6].setVertices(vertex_ftr, vertex_btr, vertex_bbr);
        m_primitives[7].setVertices(vertex_ftr, vertex_bbr, vertex_fbr);
        // top face
        m_primitives[8].setVertices(vertex_btl, vertex_btr, vertex_ftr);
        m_primitives[9].setVertices(vertex_btl, vertex_ftr, vertex_ftl);
        // bottom face
        m_primitives[10].setVertices(vertex_fbl, vertex_fbr, vertex_bbr);
        m_primitives[11].setVertices(vertex_fbl, vertex_bbr, vertex_bbl);
    }
}