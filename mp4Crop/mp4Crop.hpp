#pragma once

#include <string>
#include <opencv2/opencv.hpp>

class MP4Cropper {
private:
    std::string inputName, outputName;
    unsigned getFPS(const cv::VideoCapture &cap) const;

public:
    explicit MP4Cropper(const std::string &inputFileName);
    void crop(const unsigned x, const unsigned y, const unsigned w, const unsigned h) const;
};