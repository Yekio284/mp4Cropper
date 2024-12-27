FROM alpine:latest

RUN apk add --no-cache g++ cmake make ffmpeg opencv-dev opencv

WORKDIR /app

COPY . .

RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build .

ENTRYPOINT ["./build/src/cropper"]