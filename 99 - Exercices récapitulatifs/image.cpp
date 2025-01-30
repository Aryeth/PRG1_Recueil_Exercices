//
// Created by Aryeth on 29/01/2025.
//
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

using Pixel_value = unsigned short;
using Image = vector<vector<Pixel_value>>;

struct Pt {
    int x;
    int y;
};

using Kernel = vector<Pt>;

Image make_image(Pixel_value L , Pixel_value H , Pixel_value p = 0) {
    Image img(H, vector<Pixel_value>(L, p));
    return img;
}

Image dilate(Image img, Kernel k,Pixel_value p) {
    Image result = img;

    for (size_t x = 0; x < img.size(); x++) {
        for (size_t y = 0; y < img[x].size(); y++) {
            Pixel_value max_val = img[x][y];
            for (auto i : k) {
                int new_x = x + i.x;
                int new_y = y + i.y;
                if (new_x >= 0 && new_x < img.size() &&
                    new_y >= 0 && new_y < img[0].size()) {
                    result[new_x][new_y] = max(result[new_x][new_y], img[x][y]);
                    }
            }
            result[x][y] = max_val;
        }
    }

    return result;
}

void print_image(const Image& img) {
    for (const auto& row : img) {
        for (Pixel_value px : row) {
            if (px > 60000) cout << "o";
            else cout << "x";
        }
        cout << '\n';
    }
}

int main() {
    Pixel_value black = 0;
    Image image = make_image(10,5,black);

    for(size_t i = 0; i < 2; ++i)
        image[3 + i][3 - i] = 65535; // dessine une ligne oblique blanche

    std::cout<<"img\n";
    print_image(image);


    Kernel kernel { Pt{0,0}, Pt{-1,0}, Pt{1,0}, Pt{0,1}, Pt{0,-1}};
    Image dilated = dilate(image, kernel, black);

    std::cout<< "dilated \n";
    print_image(dilated);

    //what in the hell is this exercice
    return 0;
}