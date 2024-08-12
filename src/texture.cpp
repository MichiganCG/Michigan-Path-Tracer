#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stb_image.h>
#include <stb_image_write.h>

#include "texture.hpp"

namespace mpt {
	Texture::Texture()
		: m_textureData{nullptr}, m_width{0}, m_height{0}, m_fromFile{false}
	{ }

	Texture::~Texture()
	{
		removeTextureData();
	}

	void Texture::createImage(uint32_t width, uint32_t height)
	{
		// remove previous texture
		removeTextureData();

		// create a new texture
		m_textureData = new uint8_t[width * height * 3];
		m_width = width;
		m_height = height;
		m_fromFile = false;
	}

	void Texture::loadImage(const char* file)
	{
		// remove previous texture
		removeTextureData();

		// load the image
		int32_t width, height, channels;
		m_textureData = stbi_load(file, &width, &height, &channels, 0);
		if (!m_textureData)
		{
			std::cout << "Failed to load image: " << file << "\n";
			return;
		}

		// set the metadata
		m_width = width;
		m_height = height;

		m_fromFile = true;
	}

	void Texture::writeImage(const char* file)
	{
		if (!m_textureData) return;

		int32_t result = stbi_write_jpg(file, m_width, m_height, 3, m_textureData, 100);
		//if (result == 0) throw std::exception("write file failed!");
	}

	Vec3 Texture::getPixel(uint32_t x, uint32_t y)
	{
		// if the image is not created or loaded
		if (!m_textureData) return {0.f, 0.f, 0.f};
		// if the coordinate is out of bounds
		if (x >= m_width || y >= m_height) return {0.f, 0.f, 0.f};

		uint32_t index = (y * m_width + x) * 3;
		// convert from char to float and normalize
		float red = static_cast<float>(m_textureData[index]) / 255.f;
		float green = static_cast<float>(m_textureData[index]) / 255.f;
		float blue = static_cast<float>(m_textureData[index]) / 255.f;

		return {red, green, blue};
	}

	void Texture::writePixel(uint32_t x, uint32_t y, Vec3 color)
	{
		// if the image is not created or loaded
		if (!m_textureData) return;
		// if the coordinate is out of bounds
		if (x >= m_width || y >= m_height) return;

		// ensure all the colors are properly clamped
		std::clamp(color.x, 0.f, 1.f);
		std::clamp(color.y, 0.f, 1.f);
		std::clamp(color.z, 0.f, 1.f);

		uint32_t index = (y * m_width + x) * 3;
		// convert from float to char
		uint8_t red = static_cast<uint8_t>(color.x * 255.f);
		uint8_t green = static_cast<uint8_t>(color.y * 255.f);
		uint8_t blue = static_cast<uint8_t>(color.z * 255.f);

		// set the pixels
		m_textureData[index    ] = red;
		m_textureData[index + 1] = green;
		m_textureData[index + 2] = blue;
	}

	void Texture::removeTextureData()
	{
		// if the texture already not loaded
		if (!m_textureData) return;
		// if it's loaded from stb_image, use stbi_image_free
		if (m_fromFile) stbi_image_free(m_textureData);
		// if it's created with new uint8_t[], use delete[]
		else delete[] m_textureData;
	}
}
