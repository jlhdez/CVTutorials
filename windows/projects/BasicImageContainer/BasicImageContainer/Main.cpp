#include <opencv2/opencv.hpp>
#include <iostream>

// Namespace for OpenCV
using namespace cv;

int main(int argc, char ** argv)
{
	std::cout << "This tutorial goes over a small portion of the class Mat" << std::endl;

	char* imageName = argv[1]; 

	Mat image;
	// Store image in Mat `image`
	image = imread(imageName, 1); 

	// Check if everything went well
	if (image.data == nullptr) 
	{
		std::cout << "Couldn't open Image" << std::endl;
		return 0;
	}

	Mat gray_image;

	// Convert image to greyscale
	cvtColor(image, gray_image, COLOR_BGR2GRAY); 

	// Write the image
	imwrite("Gray_Image.jpg", gray_image); 

	// Get ready to display images
	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("Gray image", WINDOW_AUTOSIZE);

	// Show the images
	imshow(imageName, image);
	imshow("Gray image", gray_image);
	// Wait for user key press
	waitKey(0);
	
	return 0;
}