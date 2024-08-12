#pragma once

#include <cstdint>
#include <algorithm>

namespace mpt {
	// temp vec3 class
	struct Vec3 {
		float x;
		float y;
		float z;
	};

	class Texture
	{
	public:
		Texture();
		~Texture();

		// creating, writing, loading image
		void createImage(uint32_t width, uint32_t height);
		void loadImage(const char* file);
		void writeImage(const char* file);

		// pixel manipulation
		Vec3 getPixel(uint32_t x, uint32_t y);
		void writePixel(uint32_t x, uint32_t y, Vec3 color);

		// getters
		inline uint32_t getWidth() const { return m_width; };
		inline uint32_t getHeight() const { return m_height; };

	private:
		bool m_fromFile;

		uint8_t* m_textureData;
		uint32_t m_width;
		uint32_t m_height;

		void removeTextureData();
	};
}
