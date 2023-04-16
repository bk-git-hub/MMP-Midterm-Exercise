#include <opencv2/opencv.hpp>
int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
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
			float nx = (float)(min(x, w - x))/(float)(w/2);
			float ny = (float)(min(y, h - y))/(float)(w/2);

			float alpha = sqrt((nx * nx) + (ny * ny));

			if (alpha > 1)
			{
				float avg = f.val[0] + f.val[1] + f.val[2];
				avg /= 3.0;
				f = cvScalar(avg, avg, avg);
			}

			cvSet2D(dst, y, x, f);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}