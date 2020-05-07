#include <opencv2/opencv.hpp>
#include <sstream>

int main(int argc, char* argv[])
{
  if (argc != 2)
    return 1;

  cv::VideoWriter writer;

  int num = 0;
  while (true) {
    std::stringstream ss;
    ss << argv[1] << "/" << std::setw(6) << std::setfill('0') << num << ".png";
    std::cout << ss.str() << std::endl;

    cv::Mat image = cv::imread(ss.str());
    if (image.empty()) break;

    cv::imshow("show", image);
    if (cv::waitKey(1) == 'q') break;
    if (!writer.isOpened()) writer.open("video.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, image.size());
    writer << image;

    num++;
  }
}
