#include <iostream>
#include <cmath>
#include "Image_Class.h"
#include <string>
using namespace std;
Image ResizeTo(Image &src, int newWidth, int newHeight)
{
    Image resized(newWidth, newHeight);

    for (int y = 0; y < newHeight; y++)
    {
        for (int x = 0; x < newWidth; x++)
        {
            // نحسب مكان البكسل في الصورة الأصلية
            int srcX = x * src.width / newWidth;
            int srcY = y * src.height / newHeight;

            resized(x, y, 0) = src(srcX, srcY, 0);
            resized(x, y, 1) = src(srcX, srcY, 1);
            resized(x, y, 2) = src(srcX, srcY, 2);
        }
    }

    return resized;
}

void black_white(Image &image,string&save_name)
{
    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            unsigned char red = image(x, y, 0);
            unsigned char green = image(x, y, 1);
            unsigned char blue = image(x, y, 2);
            unsigned char gray = (red + green + blue) / 3;
            unsigned char bw;
            if (gray > 127)
            {
                bw = 255;
            }
            else
            {
                bw = 0;
            }
            image(x, y, 0) = bw;
            image(x, y, 1) = bw;
            image(x, y, 2) = bw;
        }
    }
    image.saveImage(save_name);
}

void horizontal_flip(Image &image,string&save_name)
{
    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width / 2; x++)
        {
            for (int c = 0; c < image.channels; c++)
            {
                swap(image(x, y, c), image(image.width - 1 - x, y, c));
            }
        }
    }
    image.saveImage(save_name);
}

void vertical_flip(Image &image,string&save_name)
{
    for (int y = 0; y < image.height / 2; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            for (int c = 0; c < image.channels; c++)
            {
                swap(image(x, y, c), image(x, image.height - 1 - y, c));
            }
        }
    }
    image.saveImage(save_name);
}

void frame(const Image &z, int &n, string &save_name)
{
    Image x = z;
    if (n == 1)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int i = 0; i < z.width; i++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int j = z.height - 1; j >= z.height - 25; j--)
        {
            for (int i = 0; i < z.width; i++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < z.height; j++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int i = z.width - 1; i >= z.width - 25; i--)
        {
            for (int j = 0; j < z.height; j++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        x.saveImage(save_name);
    }
    else if (n == 2)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int i = 0; i < z.width; i++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int j = z.height - 1; j >= z.height - 25; j--)
        {
            for (int i = 0; i < z.width; i++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < z.height; j++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int i = z.width - 1; i >= z.width - 25; i--)
        {
            for (int j = 0; j < z.height; j++)
            {
                x.setPixel(i, j, 0, 0);
                x.setPixel(i, j, 1, 200);
                x.setPixel(i, j, 2, 200);
            }
        }
        for (int i = 0; i < z.width; i++)
        {
            x.setPixel(i, 25, 0, 255);
            x.setPixel(i, 25, 1, 255);
            x.setPixel(i, 25, 2, 255);
        }
        for (int i = 0; i < z.width; i++)
        {
            x.setPixel(i, 30, 0, 255);
            x.setPixel(i, 30, 1, 255);
            x.setPixel(i, 30, 2, 255);
        }
        for (int j = 0; j < z.height; j++)
        {
            x.setPixel(25, j, 0, 255);
            x.setPixel(25, j, 1, 255);
            x.setPixel(25, j, 2, 255);
        }
        for (int j = 0; j < z.height; j++)
        {
            x.setPixel(30, j, 0, 255);
            x.setPixel(30, j, 1, 255);
            x.setPixel(30, j, 2, 255);
        }
        for (int i = 0; i < z.width; i++)
        {
            x.setPixel(i, z.height - 26, 0, 255);
            x.setPixel(i, z.height - 26, 1, 255);
            x.setPixel(i, z.height - 26, 2, 255);
        }
        for (int i = 0; i < z.width; i++)
        {
            x.setPixel(i, z.height - 31, 0, 255);
            x.setPixel(i, z.height - 31, 1, 255);
            x.setPixel(i, z.height - 31, 2, 255);
        }
        for (int j = 0; j < z.height; j++)
        {
            x.setPixel(z.width - 26, j, 0, 255);
            x.setPixel(z.width - 26, j, 1, 255);
            x.setPixel(z.width - 26, j, 2, 255);
        }
        for (int j = 0; j < z.height; j++)
        {
            x.setPixel(z.width - 31, j, 0, 255);
            x.setPixel(z.width - 31, j, 1, 255);
            x.setPixel(z.width - 31, j, 2, 255);
        }
        x.saveImage(save_name);
    }
}
void invert(const Image &z, string &name2)
{
    Image inverted = z;
    for (int j = 0; j < inverted.height; j++)
    {
        for (int i = 0; i < inverted.width; i++)
        {
            for (int c = 0; c < 3; c++)
            {
                inverted(i, j, c) = 255 - inverted(i, j, c);
            }
        }
    }
    inverted.saveImage(name2);
}
void blurring(const Image &f, string &save_name)
{
    Image c = f;
    for (int j = 0; j < f.height; j++)
    {
        for (int i = 0; i < f.width; i++)
        {
            int sumR = 0;
            int sumG = 0;
            int sumB = 0;
            int d = 0;
            for (int y = -7; y <= 7; y++)
            {
                for (int x = -7; x <= 7; x++)
                {
                    if (i + x < 0 || y + j < 0 || j + y >= f.height || i + x >= f.width)
                    {
                        continue;
                    }
                    else
                    {
                        sumR += f(i + x, j + y, 0);
                        sumG += f(i + x, j + y, 1);
                        sumB += f(i + x, j + y, 2);
                        d++;
                    }
                }
            }
            int avgR = sumR / d;
            int avgG = sumG / d;
            int avgB = sumB / d;
            c(i, j, 0) = avgR;
            c(i, j, 1) = avgG;
            c(i, j, 2) = avgB;
        }
    }
    c.saveImage(save_name);
}
void Rotation(const Image &z, int &n, string &save_name)
{
    int original_height = z.height;
    int original_width = z.width;
    if (n == 1 || n == 3)
    {
        Image w(original_height, original_width);
        if (n == 1)
        {
            for (int j = 0; j < z.height; j++)
            {

                for (int i = 0; i < z.width; i++)
                {
                    int newi = (original_height - 1) - j;
                    int newj = i;
                    w(newi, newj, 0) = z(i, j, 0);
                    w(newi, newj, 1) = z(i, j, 1);
                    w(newi, newj, 2) = z(i, j, 2);
                }
            }
            w.saveImage(save_name);
        }
        else if (n == 3)
        {
            for (int j = 0; j < z.height; j++)
            {
                for (int i = 0; i < z.width; i++)
                {
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
    else if (n == 2)
    {
        Image w(original_width, original_height);
        for (int j = 0; j < z.height; j++)
        {
            for (int i = 0; i < z.width; i++)
            {
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
void Grayscale(Image &image,string&save_name)
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
    image.saveImage(save_name);
}

void Brightness(Image &image, float gamma_value,string&save_name)
{
    if (gamma_value <= 0)
    {
        cout << "Brightness factor must be greater than 0" << endl;
        return;
    }
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
    image.saveImage(save_name);
}

void Merge(Image &img1, Image &img2, string&save_name)
{
    int option;
    cout << "There are two options in case your images are not same size \n"
         << "option 1 : Resize to biggest dimensions \n"
         << "option 2 : Merge common area \n";
    cin >> option;

    if (option == 1) // resize الصغير على حجم الكبير
    {
        int newWidth = max(img1.width, img2.width);
        int newHeight = max(img1.height, img2.height);

        Image r1 = ResizeTo(img1, newWidth, newHeight);
        Image r2 = ResizeTo(img2, newWidth, newHeight);

        Image img3(newWidth, newHeight);

        for (int y = 0; y < newHeight; y++)
        {
            for (int x = 0; x < newWidth; x++)
            {
                img3(x, y, 0) = (r1(x, y, 0) + r2(x, y, 0)) / 2;
                img3(x, y, 1) = (r1(x, y, 1) + r2(x, y, 1)) / 2;
                img3(x, y, 2) = (r1(x, y, 2) + r2(x, y, 2)) / 2;
            }
        }

        img3.saveImage(save_name);
    }
    else if (option == 2) // resize الكبير على حجم الصغير
    {
        int newWidth = min(img1.width, img2.width);
        int newHeight = min(img1.height, img2.height);

        Image r1 = ResizeTo(img1, newWidth, newHeight);
        Image r2 = ResizeTo(img2, newWidth, newHeight);

        Image img3(newWidth, newHeight);

        for (int y = 0; y < newHeight; y++)
        {
            for (int x = 0; x < newWidth; x++)
            {
                img3(x, y, 0) = (r1(x, y, 0) + r2(x, y, 0)) / 2;
                img3(x, y, 1) = (r1(x, y, 1) + r2(x, y, 1)) / 2;
                img3(x, y, 2) = (r1(x, y, 2) + r2(x, y, 2)) / 2;
            }
        }

        img3.saveImage(save_name);
    }
    else
    {
        cout << "invalid" << endl;
    }
}

void Edge_Detect(Image &image,string&save_name)
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

    edged_img.saveImage(save_name);
}
void Menu()

{
    string st;
    string st_2;
    float n;

    cout << "Upload your photo";
    cin >> st;
    Image img_1(st);
    bool running = true;
    while (running)
    {
        cout << "Select the number for the filter you want to apply! \n ";
        cout << "1: Gray scale \n "
             << "2: Black & White \n "
             << "3:Invert image\n"
             << "4: Brightness \n "
             << "5: Flip \n "
             << "6:Rotate image\n"
             << "7: Merge\n "
             << "9:Adding a frame\n"
             << "10: Edge Detect \n "
             << "12:Blur image\n"
             << "0:EXITE\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            running = 0;
            break;
        }
        case 1:
        {
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            Grayscale(img_1,save_name);
            break;
        }
        case 2:
        {
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            black_white(img_1,save_name);
            break;
        }
        case 3:
        {
            string name2;
            cout << "enter the name of the image after being inverted and its extension:\n";
            cin >> name2;
            invert(img_1, name2);
            break;
        }
        case 4:
        {

            cout << "Enter the Percintage of Brightness you want ";
            cin >> n;
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            Brightness(img_1, n,save_name);
            break;
        }
        case 5:
        {
            
            int flip_type;
            cout << "Do you want flip it vertical or horizontal\n"
                 << "1:vertical"
                 << "2:horizontal";
            cin >> flip_type;
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            switch (flip_type)
            {
            case 1:
            {
                vertical_flip(img_1,save_name);
                break;
            }
            case 2:
            {
                horizontal_flip(img_1,save_name);
                break;
            }
            }
        }
        case 6:
        {
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            cout << "choose the rotation angle:\n"
                 << "1. 90 degrees\n"
                 << "2. 180 degrees\n"
                 << "3. 270 degrees\n";
            int n;
            cin >> n;
            Rotation(img_1, n, save_name);
            break;
        }
        case 7:

        {
            cout << "Upload anther Image to Merge them ";
            cin >> st_2;
            Image img_2(st_2);
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            Merge(img_1, img_2,save_name);
            break;
        }
        case 9:
        {
            string save_name;
            cout << "enter the name you want to save the image with:\n";
            cin >> save_name;
            int n;
            cout << "choose : \n"
                 << "1. simple frame\n"
                 << "2. simple frame + white lines\n ";
            cin >> n;
            frame(img_1, n, save_name);
            break;
        }
        case 10:
        {
            string save_name;
            cout << "enter the name you want to save the image with and the extension like( filename.jpg , filename.bmp , filename.png ):\n";
            cin >> save_name;
            Edge_Detect(img_1,save_name);
            break;
        }
        case 12:
        {
            string save_name;
            cout << "enter the name you want for the blurred image and its extension:\n";
            cin >> save_name;
            blurring(img_1, save_name);
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
int main()
{
    Menu();
    return 0;
}
