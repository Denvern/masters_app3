#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>
#include "MHI.h"

using namespace std;
using namespace cv;



int main()
{
	//string path = "./wave1/wave%i.avi";
	VideoCapture capture;
	Mat motion;
	MHI *mhi = new MHI();

	cout << CV_VERSION << endl;
	char videos[20];
	char imageName[20];

	
	for (int i = 1; i < 10; i++)
	{
		sprintf(videos,"./wave1/wave%d.avi", i);
		capture.open(videos);

		for (;;)
		{
			Mat image;
			capture >> image;

			if (image.empty())
				break;

			mhi->updateMHI(image, motion, 20);
			//imshow("image", image);
			imshow("motion", motion);
			if (waitKey(50) >= 0)
				break;
		}
		sprintf(imageName, "wave%d.jpg", i);
		imwrite(imageName, motion);

	}
//	
//	imshow("mot", motion);

	system("pause");
	waitKey(0);
	return 0;
}
