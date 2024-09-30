#pragma once

#include <vector>
#include <cstdint>

#include "Scene/Primitive.hpp"

namespace mpt
{
    class Surface : public Object
    {
        public:
            virtual const std::vector<Triangle>& getTriangles() const = 0;

        protected:
            std::vector<Triangle> m_primitives;
    };

    class Cube : public Surface
    {
        public:
            Cube() : m_position{ 0.f, 0.f, 0.f }, m_size{ 1.f, 1.f, 1.f } { };
            Cube(Vec3f position, Vec3f size) : m_position{ position }, m_size{ size } { };

            const std::vector<Triangle>& getTriangles() const override;

        private:
            Vec3f m_position;
            Vec3f m_size;

            void createCube();
    };
}