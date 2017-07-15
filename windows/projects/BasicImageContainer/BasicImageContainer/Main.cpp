#include <opencv2/opencv.hpp>
#include <iostream>

// Namespace for OpenCV
using namespace cv;

int main(int argc, char ** argv)
{
	std::cout << "This tutorial goes over the class Mat" << std::endl;

	/*
	Mat A, C;									// Mat declaration, creates just the header parts
	A = imread(argv[1], IMREAD_COLOR);			// Loads an image from a file
												//	* If image cannot be loaded imread returns an empty Matrix (i.e. Mat::data == NULL) 
												//	* Has multiple flags for different options, e.g. IMREAD_COLOR

	Mat B(A); C = A;							// Mat A, B, and C all have different headers, but share the same data
												
												// Mat D and E share the same data but have a "region of interest"
	Mat D (A, Rect(10, 10, 100, 100) );			// ROI using a rectangle
	Mat E = A(Range::all(), Range(1,3));		// ROI using row and column boundaries

	Mat F = A.clone();							// Mat F and G now have a copy of the data of A. Modifying Mat F and G will not affect Mat A
	Mat G;  A.copyTo(G);
	
	*/
	char* imageName = argv[1];
	Mat image;
	image = imread(imageName, 1);
	
	if (image.data == nullptr)
	{
		std::cout << "Couldn't open Image" << std::endl;
		return 0;
	}

	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);
	imwrite("Gray_Image.jpg", gray_image);
	//namedWindow(imageName, WINDOW_AUTOSIZE);
	//namedWindow("Gray image", WINDOW_AUTOSIZE);
	//imshow(imageName, image);
	//imshow("Gray image", gray_image);
	//waitKey(0);

	return 0;
}