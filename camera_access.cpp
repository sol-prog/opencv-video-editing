// OpenCV accessing video camera
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
    double FPS = 24.0;
    // Read camera frames (at approx 24 FPS) and show the result
    while(true) {
        cap >> image;
        if(image.empty()) {
            std::cout << "Can't read frames from your camera\n";
            break;
        }

        cv::imshow("Camera feed", image);

        // Stop the camera if the user presses the "ESC" key
        if(cv::waitKey(1000.0/FPS) == 27) break;
    }

    return 0;
}
