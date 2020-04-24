//
// Created by Timothée Couble on 17/10/2019.
//

#include <iostream>
#include <opencv2/opencv.hpp>

int opencvTest(int argc, const char **argv) {
    if (argc != 2) {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    cv::Mat image;
    image = cv::imread( argv[1], 1 );

    if (!image.data) {
        std::cout << "No image data \n";
        return -1;
    }
    namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
    imshow("Display Image", image);

    cv::waitKey(0);
    return 0;
}

int main(int argc, const char **argv) {
    opencvTest(argc, argv);
    return 0;
}