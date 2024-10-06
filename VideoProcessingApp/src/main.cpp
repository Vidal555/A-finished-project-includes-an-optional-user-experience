#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/video_processor.h"

void displayMenu() {
    std::cout << "Welcome to the Video Processing Application!\n";
    std::cout << "Select an option:\n";
    std::cout << "1. Convert to another format\n";
    std::cout << "2. Trim the video\n";
    std::cout << "3. Resize the video\n";
    std::cout << "4. Rotate the video\n";
    std::cout << "5. Add text overlay\n";
    std::cout << "6. Apply filter\n";
    std::cout << "0. Exit\n";
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_video>" << std::endl;
        return -1;
    }

    std::string inputFile = argv[1];
    VideoProcessor processor(inputFile);

    int choice = -1;
    while (choice != 0) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string outputFile;
                std::cout << "Enter output file name: ";
                std::cin >> outputFile;
                processor.processVideo(0, 10, 640, 480, 0, "", cv::Point(0, 0), outputFile);
                break;
            }
            case 2: {
                double start, end;
                std::cout << "Enter start time in seconds: ";
                std::cin >> start;
                std::cout << "Enter end time in seconds: ";
                std::cin >> end;
                processor.processVideo(start, end, 640, 480, 0, "", cv::Point(0, 0), "output_trimmed.avi");
                break;
            }
            case 3: {
                int width, height;
                std::cout << "Enter new width: ";
                std::cin >> width;
                std::cout << "Enter new height: ";
                std::cin >> height;
                processor.processVideo(0, 10, width, height, 0, "", cv::Point(0, 0), "output_resized.avi");
                break;
            }
            case 4: {
                int angle;
                std::cout << "Enter rotation angle (90, 180, 270): ";
                std::cin >> angle;
                processor.processVideo(0, 10, 640, 480, angle, "", cv::Point(0, 0), "output_rotated.avi");
                break;
            }
            case 5: {
                std::string text;
                int x, y;
                std::cout << "Enter text to overlay: ";
                std::cin.ignore();
                std::getline(std::cin, text);
                std::cout << "Enter X position: ";
                std::cin >> x;
                std::cout << "Enter Y position: ";
                std::cin >> y;
                processor.processVideo(0, 10, 640, 480, 0, text, cv::Point(x, y), "output_text.avi");
                break;
            }
            case 6: {
                processor.processVideo(0, 10, 640, 480, 0, "", cv::Point(0, 0), "output_filtered.avi");
                break;
            }
            case 0:
                std::cout << "Exiting the application...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    }

    return 0;
}
