// OpenCV accessing video camera and saving the result
#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // Open the first camera attached to your computer
    cv::VideoCapture cap(0);
    if(!cap.isOpened()) {
        std::cout << "Unable to open the camera\n";
        std::exit(-1);
    }

    cv::Mat image;
    double FPS = 10.0;

    // Get the width/height of the camera frames
    int width = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));

    // Open a video file for writing (the MP4V codec works on OS X and Windows)
    cv::VideoWriter out("output.mov", CV_FOURCC('m','p', '4', 'v'), FPS, cv::Size(width, height));
    if(!out.isOpened()) {
        std::cout <<"Error! Unable to open video file for output." << std::endl;
        std::exit(-1);
    }

    while(true) {
        cap >> image;
        if(image.empty()) {
            std::cout << "Can't read frames from your camera\n";
            break;
        }

        // Save frame to video
        out << image;

        cv::imshow("Camera feed", image);

        // Stop the camera if the user presses the "ESC" key
        if(cv::waitKey(1000.0/FPS) == 27) break;
    }

    return 0;
}
