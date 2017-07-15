## TutorialCV

## Motivation
The intended purpose of this project is to learn `git`, `OpenCV`, and the new features of `c++11`.

## Windows setup for OpenCV

1. Download MS Visual Studio
 + Check if a sample program can be compiled and run. e.g.

 ```
 #include "stdafx.h"
 #include <iostream>

 int main(){
    std::cout << "Hello World\n";
    return 0;
 }
 ```
2. Download [OpenCV](http://opencv.org/releases.html)
_Version 3.2*_
 + Run the executable
 + Save OpenCV somewhere to remember; e.g. __C:/openCV/__.
 + Add a new entry to the _Environmental Variable_ __Path__.
    + In Windows 10, open _File explorer_ or any folder.
    + Right click on _This pc_ and choose _Properties_.
    + Click on _Advance system settings_.
    + The click on _Environmental Variables..._
    + On _Sytem Variables_ look for the variable __Path__
    + Edit it and add the new entry. Make sure it points to the bin directory found in `\build\x64\vc14\bin` in OpenCV; e.g. __C:\opencv\build\x64\vc14\bin__
    + Restarting the computer at this point might not be a bad idea.

3. In MS Visual Studio create a new project, a console application; e.g `Test`
4. Make sure the project knows where the OpenCV library is.
  + Go to _Project-> `Test` Properties_
    + In _C/C++ -> General_ add the include folder from OpenCV, e.g. __C:\opencv\build\include__, to _Additional Include Directories_
    + In _Linker -> General_ add the lib folder from OpenCV, e.g. __C:\opencv\build\x64\vc14\lib__, to _Additional Library Directories_
       + Make sure the lib folder in somewhere in the path `....\build\x64\vc14\lib`
    + In _Linker -> Input_ add the following to _Additional Dependencies_(320 represents the version number):
       + `opencv_world320d.lib`

5. Test any OpenCV project to see if the setup worked. e.g.

```
// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv\cv.h>  
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>

using namespace cv;

int main() {
	Mat image;          //Create Matrix to store image
	VideoCapture cap;          //initialize capture
	cap.open(0);
	namedWindow("window", 1);          //create window to show image
	while (1) {
		cap >> image;          //copy webcam stream to image
		imshow("window", image);          //print image to screen
		waitKey(33);          //delay 33ms
	}
	return 0;
}
```

 _*As of July 2017_
## References
_Most of these Links I looked at while trying to setup OpenCV in Windows 10, the first link, youtube video, helped me get it working. There are also other non related links of CMake that I would like to keep a reference to._

1. [Youtube Video: Setting Up OpenCV in Visual Studio](https://www.youtube.com/watch?v=l4372qtZ4dc)
1. http://dogfeatherdesign.com/2015/11/28/opencv-3-0-microsoft-visual-studio-2015-cmake-and-c/
1. https://stackoverflow.com/questions/36633177/cmake-with-git-for-windows-mingw-and-make
1. https://stackoverflow.com/questions/10851247/how-to-activate-c-11-in-cmake
1. https://stackoverflow.com/questions/13970377/configuring-an-c-opencv-project-with-cmake
1. http://answers.opencv.org/question/122696/is-it-possible-to-build-opencv-320-libraries-using-mingw-for-a-32bit-windows/
1. https://stackoverflow.com/questions/36633177/cmake-with-git-for-windows-mingw-and-make
1. http://www.mingw.org/wiki/mingw_for_first_time_users_howto
1. https://gist.github.com/evanwill/0207876c3243bbb6863e65ec5dc3f058
1. https://cmake.org/documentation/
1.	http://derekmolloy.ie/hello-world-introductions-to-cmake/
