#include <iostream>
#include <cmath>
#include "Image_Class.h"
using namespace std;

void Grayscale(Image &image)
{
    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            unsigned char red = image(x, y, 0);
            unsigned char green = image(x, y, 1);
            unsigned char blue = image(x, y, 2);

            unsigned char gray_value = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);

            image(x, y, 0) = gray_value;
            image(x, y, 1) = gray_value;
            image(x, y, 2) = gray_value;
        }
    }
    image.saveImage("gray.png");
}

void Brightness(Image &image, float gamma_value)
{
    float inverse_gamma = 1.0f / gamma_value;

    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            for (int c = 0; c < image.channels; ++c)
            {
                float normalized_avg = image(x, y, c) / 255.0f;
                float corrected_avg = pow(normalized_avg, inverse_gamma);
                int final_avg_value = static_cast<int>(corrected_avg * 255.0f);

                if (final_avg_value > 255)
                {
                    final_avg_value = 255;
                }

                image(x, y, c) = static_cast<unsigned char>(final_avg_value);
            }
        }
    }
    image.saveImage("BR.png");
}

void Merge(Image &img1, Image &img2)
{
    Image img3(img1.width, img1.height);
    for (int y = 0; y < img1.height; ++y)
    {
        for (int x = 0; x < img1.width; ++x)
        {
            img3(x, y, 0) = (img2(x, y, 0) + img1(x, y, 0)) / 2;
            img3(x, y, 1) = (img2(x, y, 1) + img1(x, y, 1)) / 2;
            img3(x, y, 2) = (img2(x, y, 2) + img1(x, y, 2)) / 2;
        }
    }
    img3.saveImage("Merge.jpg");
}

void Edge_Detect(Image &image)
{

    Image edged_img(image.width, image.height);
    int avg = 0;

    // Sobel kernels
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};

    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}};

    // loop through image (skip border avgs)
    for (int y = 1; y < image.height - 1; y++)
    {
        for (int x = 1; x < image.width - 1; x++)
        {

            double sumX = 0;
            double sumY = 0;

            // convert to grayscale on the fly (use only one channel)
            for (int ky = -1; ky <= 1; ky++)
            {
                for (int kx = -1; kx <= 1; kx++)
                {
                    int avg = (image(x + kx, y + ky, 0) + // red
                               image(x + kx, y + ky, 1) + // green
                               image(x + kx, y + ky, 2)   // blue
                               ) /
                              3;

                    sumX += avg * Gx[ky + 1][kx + 1];
                    sumY += avg * Gy[ky + 1][kx + 1];
                }
            }

            // calculate gradient magnitude
            int magnitude = (int)std::sqrt(sumX * sumX + sumY * sumY);

            // clamp value between 0–255
            if (magnitude > 255)
                magnitude = 255;

            // set all channels the same (grayscale edge map)
            for (int c = 0; c < image.channels; c++)
            {
                edged_img(x, y, c) = (unsigned char)(255 - magnitude);
            }
        }
    }

    edged_img.saveImage("edged_img.png");
}
void Menue(){
    cout<<"choose filter";

}
int main()
{
    Image img("photographer.jpg");
    Edge_Detect(img);
    return 0;
}
