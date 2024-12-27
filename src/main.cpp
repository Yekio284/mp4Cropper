#include <iostream>
#include "../mp4Crop/mp4Crop.hpp"

int main(int argc, char **argv) {
    if (argc != 6) {
        std::cerr << "Usage: ./cropper <fileName>.mp4 <x> <y> <width> <height>\n";
        return -1;
    }

    MP4Cropper cropper(argv[1]);
    cropper.crop(std::stoul(argv[2]), std::stoul(argv[3]), std::stoul(argv[4]), std::stoul(argv[5]));

    return 0;
}