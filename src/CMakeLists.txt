add_executable(cropper main.cpp)

target_link_libraries(cropper mp4Crop ${OpenCV_LIBS})