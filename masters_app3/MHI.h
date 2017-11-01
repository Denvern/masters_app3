#include <opencv2/optflow/motempl.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>



#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;
using namespace cv;
using namespace motempl;

#define MHI_DURATION 1.5
#define MAX_TIME_DELTA 0.5
#define MIN_TIME_DELTA 0.05



class MHI
{
public:
	MHI();
	~MHI();
	void updateMHI(Mat &img, Mat &dst, int thresh);
	//void videoCapture();
	
	



	


};

