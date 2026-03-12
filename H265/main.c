#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

#define VIDEO_DEVICE "/dev/video19" // Thay đổi theo thiết bị HEVC của bạn

int main() {
    int fd = open(VIDEO_DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Không mở được thiết bị V4L2");
        return -1;
    }

    // Cấu hình định dạng đầu vào (H.265)
    struct v4l2_format fmt = {0};
    fmt.type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
    fmt.fmt.pix_mp.pixelformat = V4L2_PIX_FMT_HEVC;
    fmt.fmt.pix_mp.width = 1920; // Độ phân giải camera
    fmt.fmt.pix_mp.height = 1080;
    fmt.fmt.pix_mp.num_planes = 1;

    if (ioctl(fd, VIDIOC_S_FMT, &fmt) < 0) {
        perror("Không đặt được định dạng đầu vào");
        close(fd);
        return -1;
    }

    // Cấu hình định dạng đầu ra (YUV)
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
    fmt.fmt.pix_mp.pixelformat = V4L2_PIX_FMT_YUV420M;

    if (ioctl(fd, VIDIOC_S_FMT, &fmt) < 0) {
        perror("Không đặt được định dạng đầu ra");
        close(fd);
        return -1;
    }

    // Tiếp tục với việc đọc luồng từ camera và gửi vào thiết bị V4L2
    // (Cần thêm logic để đọc RTSP hoặc luồng camera)

    close(fd);
    return 0;
}
