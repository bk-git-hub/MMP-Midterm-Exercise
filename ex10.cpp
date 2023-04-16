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
			if (y < h / 3)
			{
				f.val[0] = 0;
				f.val[1] = 0;
			}
			else if (y < h / 3 * 2)
			{
				f.val[1] = 0;
				f.val[2] = 0;
			}
			else
			{
				f.val[0] = 0;
				f.val[2] = 0;
			}
			cvSet2D(dst, y, x, f);
		}

		
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}