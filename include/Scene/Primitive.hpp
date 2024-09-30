#pragma once

#include <cstdint>

#include "Scene/Object.hpp"

namespace mpt
{
    class Primitive : public Object
    {
    public:
        inline void setColor(Color color) { m_color = color; };
        virtual Color getColor() = 0;
    protected:
        Color m_color;
    };

    class Triangle : public Primitive
    {
    public:
        Triangle(Vec3f vertex_one, Vec3f vertex_two, Vec3f vertex_three);

        void setVertices(Vec3f vertex_one, Vec3f vertex_two, Vec3f vertex_three);

        void setPosition(const Vec3f& position) override;
        void setRotation(const Vec3f& rotation) override;

        float isHit(const Ray& ray) const;

        Color getColor() override { return m_color; };
    private:
        Vec3f vertices[3];
    };
}