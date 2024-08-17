#pragma once

namespace mpt
{
    // placeholder class
    struct Vec3f
    {
        float x;
        float y;
        float z;
    };
    using Color = Vec3f;
    struct Ray
    {
        Vec3f origin;
        Vec3f direction;
    };

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