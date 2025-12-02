#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include "old_image_resize.h"
#include "Render.h"
#include <iostream>

void Render::Initialize(const char* path)
{
    pixel = stbi_load(path, &width, &height, &bpp, 4);
    if (!pixel) {
    std::cerr << "Failed to load image!" << std::endl;
    std::cerr << stbi_failure_reason() << std::endl;
    return;
        }
}

void Render::Update(const char* path)
{
    //リサイズ
    stbir_resize_uint8(pixel, width, height, 0, pixel_resize, reWidth, reWidth, 0, bpp);

	//出力
	stbi_write_png(path, reWidth, reWidth, bpp, pixel_resize,  0);
}