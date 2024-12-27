#include <iostream>
#include <string>
#include <cstdlib>

#include "mp4Crop.hpp"

MP4Cropper::MP4Cropper(const std::string &inputFileName) : inputName(inputFileName), 
    outputName("/output/output_" + inputFileName) {
}

unsigned MP4Cropper::getFPS(const cv::VideoCapture &cap) const {
    return static_cast<unsigned>(cap.get(cv::CAP_PROP_FPS)); 
}

void MP4Cropper::crop(const unsigned x, const unsigned y, const unsigned w, const unsigned h) const {
    cv::VideoCapture cap(inputName);
    if (!cap.isOpened()) {
        std::cerr << "Can't open video file.\n";
        return;
    }

    const std::string tmpVideo = "tmp_" + inputName;
    cv::VideoWriter tmpWriter(tmpVideo, cv::VideoWriter::fourcc('m', 'p', '4', 'v'), getFPS(cap), cv::Size(w, h));

    if (!tmpWriter.isOpened()) {
        std::cerr << "Can't open video writer (for tmp).\n";
        return;
    }

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        cv::Rect region(x, y, w, h);
        cv::Mat croppedFrame = frame(region);

        tmpWriter.write(croppedFrame);
    }

    cap.release();
    tmpWriter.release();

    std::string cmd = "ffmpeg -i " + tmpVideo + " -i " + inputName + 
                      " -c:v copy -c:a aac -map 0:v:0 -map 1:a:0 " + outputName;
    std::cout << "cmd = " << cmd << std::endl;

    if (std::system(cmd.c_str()) != 0) {
        std::cerr << "Error while running FFmpeg command.\n";
        return;
    }

    std::cout << "Done: " << outputName << std::endl;
}