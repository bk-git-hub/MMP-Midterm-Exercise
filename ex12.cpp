#include <opencv2/opencv.hpp>
CvScalar function(CvScalar f)
{
	CvScalar g = f;
	for (int k = 0; k < 3; k++)
	{
		if (g.val[k] < 128)
		{
			g.val[k] = g.val[k] * 256 / 128;
		}

		else
		{
			g.val[k] = 512 - g.val[k]*256/128 ;
		}
	}

	return g;
}

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
			CvScalar g = function(f);


			cvSet2D(dst, y, x, g);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}