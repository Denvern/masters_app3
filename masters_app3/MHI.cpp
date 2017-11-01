#include "MHI.h"

int last = 0;
const int N = 5;
int idx2;
vector<Mat> buf(N);
Mat mhi;

MHI::MHI()
{
}


MHI::~MHI()
{
}

void MHI::updateMHI(Mat & img, Mat & dst, int diff_threshold)
{
	double timestamp = (double)clock() / CLOCKS_PER_SEC;
	int idx1 = last, idx2;
	Mat silh, mask;

	cvtColor(img, buf[last], CV_BGR2GRAY); // convert frame to grayscale

	//buf[last] = img;

	idx2 = (last + 1) % N; // index of (last - (N-1))th frame
	last = idx2;

	if (buf[idx1].size() != buf[idx2].size())
		silh = Mat::ones(img.size(), CV_8U) * 255;
	else
		absdiff(buf[idx1], buf[idx2], silh); // get difference between frames

	//cvtColor(silh, silh, CV_BGR2GRAY);

	threshold(silh, silh, diff_threshold, 1, CV_THRESH_BINARY); // and threshold it
	if (mhi.empty())
		mhi = Mat::zeros(silh.size(), CV_32F);
	updateMotionHistory(silh, mhi, timestamp, MHI_DURATION); // update MHI

															 // convert MHI to blue 8u image
	mhi.convertTo(mask, CV_8U, 255. / MHI_DURATION,(MHI_DURATION - timestamp)*255. / MHI_DURATION);
	dst = Mat::zeros(mask.size(), CV_8UC3);
	insertChannel(mask, dst, 0);

}


