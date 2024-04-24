
Secondly, when you are running the ffmpeg command, you should specify the input format as rawvideo since you are writing raw image data into the named pipe. So the ffmpeg command should look like this:
```bash
ffmpeg -f rawvideo -pix_fmt rgb24 -s $widthx$height -i myfifo -c:v libx264 -preset slow -crf 20 Video.mp4
