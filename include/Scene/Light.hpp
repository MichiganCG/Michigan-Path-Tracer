#pragma once

#include "Scene/Object.hpp"

namespace mpt
{
    class Light
    {
    public:
        virtual Color sample(const Ray& ray) const;
    };

    class InfiniteLight : public Light
    {
    public:
        InfiniteLight(Color color) : m_color{ color } { };

        Color sample(const Ray& ray) const override;
    private:
        Color m_color;
    };
}