#include <iostream>
#include <cmath>
#include "Image_Class.h"
#include<string>
using namespace std;
void frame(Image& z, int& n, string& save_name) {
    if (n == 1) {
        for (int j = 0;j < 25;j++) {
            for (int i = 0;i < z.width;i++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int j = z.height - 1;j >= z.height - 25;j--) {
            for (int i = 0;i < z.width;i++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int i = 0;i < 10;i++) {
            for (int j = 0;j < z.height;j++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int i = z.width - 1;i >= z.width - 10;i--) {
            for (int j = 0;j < z.height;j++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        z.saveImage(save_name);
    }
    else if (n == 2) {
        for (int j = 0;j < 25;j++) {
            for (int i = 0;i < z.width;i++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int j = z.height - 1;j >= z.height - 25;j--) {
            for (int i = 0;i < z.width;i++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int i = 0;i < 10;i++) {
            for (int j = 0;j < z.height;j++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int i = z.width - 1;i >= z.width - 10;i--) {
            for (int j = 0;j < z.height;j++) {
                z.setPixel(i, j, 0, 0);
                z.setPixel(i, j, 1, 200);
                z.setPixel(i, j, 2, 200);
            }
        }
        for (int i = 0;i < z.width;i++) {
            z.setPixel(i, 25, 0, 255);
            z.setPixel(i, 25, 1, 255);
            z.setPixel(i, 25, 2, 255);
        }
        for (int i = 0;i < z.width;i++) {
            z.setPixel(i, 30, 0, 255);
            z.setPixel(i, 30, 1, 255);
            z.setPixel(i, 30, 2, 255);
        }
        for (int j = 0;j < z.height;j++) {
            z.setPixel(10, j, 0, 255);
            z.setPixel(10, j, 1, 255);
            z.setPixel(10, j, 2, 255);
        }
        for (int j = 0;j < z.height;j++) {
            z.setPixel(15, j, 0, 255);
            z.setPixel(15, j, 1, 255);
            z.setPixel(15, j, 2, 255);
        }
        for (int i = 0;i < z.width;i++) {
            z.setPixel(i, z.height - 26, 0, 255);
            z.setPixel(i, z.height - 26, 1, 255);
            z.setPixel(i, z.height - 26, 2, 255);
        }
        for (int i = 0;i < z.width;i++) {
            z.setPixel(i, z.height - 31, 0, 255);
            z.setPixel(i, z.height - 31, 1, 255);
            z.setPixel(i, z.height - 31, 2, 255);
        }
        for (int j = 0;j < z.height;j++) {
            z.setPixel(z.width - 11, j, 0, 255);
            z.setPixel(z.width - 11, j, 1, 255);
            z.setPixel(z.width - 11, j, 2, 255);
        }
        for (int j = 0;j < z.height;j++) {
            z.setPixel(z.width - 16, j, 0, 255);
            z.setPixel(z.width - 16, j, 1, 255);
            z.setPixel(z.width - 16, j, 2, 255);
        }
        z.saveImage(save_name);
    }
}
void invert(Image& inverted, string& save_name) {
    for (int j = 0;j < inverted.height;j++) {
        for (int i = 0;i < inverted.width; i++) {
            for (int c = 0;c < 3;c++) {
                inverted(i, j, c) = 255 - inverted(i, j, c);
            }
        }
    }
    inverted.saveImage(save_name);
}
void blurring(Image& f, string& save_name) {
    Image c = f;
    for (int j = 0;j < f.height;j++) {
        for (int i = 0;i < f.width;i++) {
            int sumR = 0;
            int sumG = 0;
            int sumB = 0;
            int d = 0;
            for (int y = -7;y <= 7;y++) {
                for (int x = -7;x <= 7;x++) {
                    if (i + x < 0 || y + j < 0 || j + y >= f.height || i + x >= f.width) {
                        continue;
                    }
                    else {
                        sumR += c(i + x, j + y, 0);
                        sumG += c(i + x, j + y, 1);
                        sumB += c(i + x, j + y, 2);
                        d++;

                    }



                }
            }
            int avgR = sumR / d;
            int avgG = sumG / d;
            int avgB = sumB / d;
            f(i, j, 0) = avgR;
            f(i, j, 1) = avgG;
            f(i, j, 2) = avgB;
        }
    }
    f.saveImage(save_name);
}
void Rotation(const Image& z, int& n, string& save_name) {
    int original_height = z.height;
    int original_width = z.width;
    if (n == 1 || n == 3) {
        Image w(original_height, original_width);
        if (n == 1) {
            for (int j = 0;j < z.height;j++) {

                for (int i = 0;i < z.width;i++) {
                    int newi = (original_height - 1) - j;
                    int newj = i;
                    w(newi, newj, 0) = z(i, j, 0);
                    w(newi, newj, 1) = z(i, j, 1);
                    w(newi, newj, 2) = z(i, j, 2);
                }
            }
            w.saveImage(save_name);

        }
        else if (n == 3) {
            for (int j = 0;j < z.height;j++) {
                for (int i = 0;i < z.width;i++) {
                    int newi = j;
                    int newj = (original_width - 1) - i;
                    w(newi, newj, 0) = z(i, j, 0);
                    w(newi, newj, 1) = z(i, j, 1);
                    w(newi, newj, 2) = z(i, j, 2);
                }
            }
            w.saveImage(save_name);
        }
    }
    else if (n == 2) {
        Image w(original_width, original_height);
        for (int j = 0;j < z.height;j++) {
            for (int i = 0;i < z.width;i++) {
                int newi = (original_width - 1) - i;
                int newj = (original_height - 1) - j;
                w(newi, newj, 0) = z(i, j, 0);
                w(newi, newj, 1) = z(i, j, 1);
                w(newi, newj, 2) = z(i, j, 2);
            }
        }
        w.saveImage(save_name);
    }
}
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
    int option;
    cout << "There are two options in case your images are not same size \n"
         << "option 1 : Resize to biggest dimensions \n"
         << "option 2 : Merge common area \n";
    cin >> option;

    int newWidth, newHeight;

    if (option == 1) // Resize to biggest dimensions
    {
        Image resized(max(img1.width, img2.width), max(img1.height, img2.height));

        for (int y = 0; y < resized.height; ++y)
        {
            for (int x = 0; x < resized.width; ++x)
            {
                resized(x, y, 0) = (img1(x, y, 0) + img2(x, y, 0)) / 2;
                resized(x, y, 1) = (img1(x, y, 1) + img2(x, y, 1)) / 2;
                resized(x, y, 2) = (img1(x, y, 2) + img2(x, y, 2)) / 2;
            }
        }
        resized.saveImage("Merge_Resize.jpg");
    }
    else if (option == 2) // Merge common area
    {
        newWidth = min(img1.width, img2.width);
        newHeight = min(img1.height, img2.height);

        Image img3(newWidth, newHeight);
        for (int y = 0; y < newHeight; ++y)
        {
            for (int x = 0; x < newWidth; ++x)
            {
                img3(x, y, 0) = (img1(x, y, 0) + img2(x, y, 0)) / 2;
                img3(x, y, 1) = (img1(x, y, 1) + img2(x, y, 1)) / 2;
                img3(x, y, 2) = (img1(x, y, 2) + img2(x, y, 2)) / 2;
            }
        }
        img3.saveImage("Merge_Common.jpg");
    }
    else
    {
        cout << "Invalid option" << endl;
    }
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
void Menue()
{
    string st;
    string st_2;
    float n;
    Image img_2();
    cout << "Upload your photo";
    cin >> st;
    Image img_1(st);
    cout << "Select the number for the filter you want to apply! \n ";
    int choice;
    cin >> choice;
    cout << "1: Gray scale \n "
         << "4: Brightness \n "
         << "7: Merge\n "
         << "10: Edge Detect \n "
         << "0:EXITE";
    switch (choice)
    {
         case 0:
    {
        break;
    }
    case 1:
    {
        Grayscale(img_1);
        break;
    }
    case 4:
    {

        cout << "Enter the Percintage of Brightness you want ";
        cin >> n;

        Brightness(img_1, n);
        break;
    }
    case 7:

    {
        cout << "Upload anther Image to Merge them ";
        cin >> st_2;
        Image img_2(st_2);
        Merge(img_1, img_2);
        break;
    }
    case 10:
    {
        Edge_Detect(img_1);
        break;
    }
    }
}
int main()
{
 Menue();
    return 0;
}
