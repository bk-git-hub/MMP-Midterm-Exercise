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
			float nx = (float)x / (w - 1);
			float ny = (float)y / (h - 1);

			float alpha = (nx + ny) / 2;

			CvScalar f = cvGet2D(src, y, x);
			float avg = (f.val[0] + f.val[1], f.val[2]) / 3.0;
			CvScalar g = cvScalar(avg, avg, avg);

			CvScalar sc;
			for (int k = 0; k < 3; k++)
			{
				sc.val[k] = (1-alpha) * f.val[k] +  alpha * g.val[k];
			}
			cvSet2D(dst, y, x, sc);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}