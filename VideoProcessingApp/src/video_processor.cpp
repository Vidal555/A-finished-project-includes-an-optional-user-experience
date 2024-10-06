#include "video_processor.h"
#include <iostream>

VideoProcessor::VideoProcessor(const std::string& filePath) : inputFile(filePath) {
    cap.open(inputFile);
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file: " << inputFile << std::endl;
    }
}

void VideoProcessor::processVideo(double startSec, double endSec, int width, int height, int angle, const std::string& text, const cv::Point& position, const std::string& outputFile) {
    // Open VideoWriter
    writer.open(outputFile, cv::VideoWriter::fourcc('M','J','P','G'), cap.get(cv::CAP_PROP_FPS), cv::Size(width, height));
    
    if (!writer.isOpened()) {
        std::cerr << "Error opening output file: " << outputFile << std::endl;
        return;
    }

    cap.set(cv::CAP_PROP_POS_MSEC, startSec * 1000); // Start at the desired second
    while (cap.read(frame) && cap.get(cv::CAP_PROP_POS_MSEC) <= endSec * 1000) {
        // Resize the video
        cv::resize(frame, frame, cv::Size(width, height));

        // Rotate the video
        if (angle != 0) {
            cv::rotate(frame, frame, angle == 90 ? cv::ROTATE_90_CLOCKWISE : (angle == 180 ? cv::ROTATE_180 : cv::ROTATE_90_COUNTERCLOCKWISE));
        }

        // Add text overlay
        if (!text.empty()) {
            cv::putText(frame, text, position, cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 255, 255), 2);
        }

        // Apply grayscale filter
        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        // Write the frame to the output file
        writer.write(frame);

        // Display the frame on the screen
        cv::imshow("Processed Video", frame);
        if (cv::waitKey(30) >= 0) break; // Exit the loop if a key is pressed
    }

    writer.release(); // Release the video writer
}
