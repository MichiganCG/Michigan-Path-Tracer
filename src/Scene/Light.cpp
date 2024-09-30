#include "Scene/Light.hpp"

namespace mpt
{
    Color InfiniteLight::sample(const Ray& ray) const
    {
        return m_color;
    }
}