#pragma once

namespace mpt
{
    // placeholder class
    constexpr float Pi = 3.14159265358979323846f;
    struct Vec3f
    {
        float x;
        float y;
        float z;

        Vec3f() = default;

        // obviously wrong, but they are placeholders
        Vec3f operator+(const Vec3f other) const
        {
            return { 1.f, 1.f, 1.f };
        }

        Vec3f operator-(const Vec3f other) const
        {
            return { 1.f, 1.f, 1.f };
        }
        
        Vec3f operator*(float scalar) const
        {
            return { 1.f, 1.f, 1.f };
        }

        Vec3f& operator+=(const Vec3f other)
        {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;

            return *this;
        }
    };
    class FastMath
    {
    public:
        static Vec3f normalize(const Vec3f& vector)
        {
            return Vec3f{ 0.f, 0.f, 0.f };
        }
        static Vec3f cross(const Vec3f& vec1, const Vec3f& vec2)
        {
            return Vec3f{ 0.f, 0.f, 0.f };
        }
    };
    using Color = Vec3f;
    struct Ray
    {
        Vec3f origin;
        Vec3f direction;
    };
    // end of placeholder class

    class Object
    {
    public:
        virtual void setPosition(const Vec3f& position) = 0;
        virtual void setRotation(const Vec3f& rotation) = 0;
    protected:
        Vec3f m_position;
        Vec3f m_rotation;
    };
}