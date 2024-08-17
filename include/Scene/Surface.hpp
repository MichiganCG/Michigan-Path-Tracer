#pragma once

#include <vector>
#include <cstdint>

#include "Scene/Primitive.hpp"

namespace mpt
{
    class Surface : public Object
    {
        public:
            void setPosition(const Vec3f& position) override;
            void setRotation(const Vec3f& rotation) override;
        private:
            std::vector<Triangle> m_primitives;
    };
}