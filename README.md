# mp4Cropper
1. Скачать и разархивировать архив
2. Скопировать в корень проекта видео, подлежащее кадрированию
3. Из корня: docker build -t mp4cropper .
4. Из корня: docker run --rm -v $(pwd):/output mp4cropper &lt;name&gt;.mp4 &lt;xCoordinate&gt; &lt;yCoordinate&gt; &lt;Width&gt; &lt;Height&gt;

**Пример:** docker run --rm -v $(pwd):/output mp4cropper testvideo.mp4 150 330 960 540

#### Важно: тестирование производилось в WSL2 Ubuntu 22.04

#### Need to fix: пересмотреть Dockerfile
