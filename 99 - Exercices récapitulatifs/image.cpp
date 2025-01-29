//
// Created by Aryeth on 29/01/2025.
//
#include <vector>
#include <limits>
using namespace std;

using Pixel_value = unsigned short;
using Image = vector<vector<Pixel_value>>;

Image make_image(Pixel_value L = numeric_limits<Pixel_value>::epsilon(), Pixel_value H = numeric_limits<Pixel_value>::epsilon(), Pixel_value p) {
    Image img(H, vector<Pixel_value>(L, p));
    return img;
}

int main() {
    Pixel_value black = 0;
    Image image = make_image(1920,1080,black);

    for(size_t i = 0; i < 20; ++i)
        image[200 + i][300 - i] = 65535; // dessine une ligne oblique blanche

    Kernel kernel { Pt{0,0}, Pt{-1,0}, Pt{1,0}, Pt{0,1}, Pt{0,-1}};
    Image dilated = dilate(image, kernel, black);
}