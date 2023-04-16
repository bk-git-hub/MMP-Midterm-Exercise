#include <opencv2/opencv.hpp>

int main()
{
	IplImage* src = cvLoadImage("C:\\temp\\Lena.png");
	CvSize size = cvGetSize(src);
	IplImage* dst = cvCreateImage(size, 8, 3);
	int w = size.width;
	int h = size.height;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			CvScalar f = cvGet2D(src, y, x);
			CvScalar g;
			int cx = (float)x / w * 8;
			int cy = (float)y / h * 8;

			if ((cx + cy) % 2 == 0)
			{
				g = f;
			}
			else
			{
				g = cvScalar(0, 0, 0);
			}
			cvSet2D(dst, y, x, g);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}