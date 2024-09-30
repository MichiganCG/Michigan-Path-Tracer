#include "Scene/Camera.hpp"

namespace mpt
{
    Camera::Camera()
        : m_width{ 1920 }, m_height(1080), m_fov{ Pi / 2.f }, m_position{ 0.f, 0.f, 0.f },
        m_lookat{ 0.f, 0.f, -1.f }, m_upDirection{ 0.f, 1.f, 0.f }
    { }

    Camera::Camera(uint32_t width, uint32_t height, float fov)
        : m_width{ width }, m_height{ height }, m_fov{ fov }, m_position{ 0.f, 0.f, 0.f },
        m_lookat{ 0.f, 0.f, -1.f }, m_upDirection{ 0.f, 1.f, 0.f }
    { }

    std::vector<Ray> Camera::getRays() const
    {
        // all rays share the same origin at the start
        std::vector<Ray> rays(m_width * m_height, { m_position, { 0.f, 0.f, 0.f } });

        // calculate the orthonormal up and right directions
        Vec3f ortho_right = FastMath::cross(m_upDirection, m_lookat);
        Vec3f ortho_up = FastMath::cross(m_lookat, ortho_right);

        float half_width = static_cast<float>(m_width) / 2.f;
        float half_height = static_cast<float>(m_height) / 2.f;
        float focal_distance = half_height / tan(m_fov / 2.f);
        Vec3f focal_distance_vector = { 0.f, 0.f, -focal_distance };
        for(uint32_t i=0;i<m_height;++i)
        {
            for(uint32_t j=0;j<m_width;++j)
            {
                Vec3f direction =
                    ortho_right * (static_cast<float>(i) - half_width) +
                    ortho_up * (half_height - static_cast<float>(j)) +
                    focal_distance_vector;

                direction = FastMath::normalize(direction);

                rays[i * m_width + j].direction = direction;
            }
        }

        // As you walk through this array, the rays go left to right,
        // top to bottom. Not too relevant unless a different pattern
        // is more cache friendly
        return rays;
    }
}