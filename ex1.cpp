#include <opencv2/opencv.hpp>

int main()
{
	IplImage* src = cvLoadImage("C:\\temp\\yeji.jpg");
	CvSize size = cvGetSize(src);
	IplImage* dst = cvCreateImage(size, 8, 3);
	int w = size.width;
	int h = size.height;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			CvScalar sc = cvGet2D(src, y, x);
			cvSet2D(dst, h - 1 - y, x, sc);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}