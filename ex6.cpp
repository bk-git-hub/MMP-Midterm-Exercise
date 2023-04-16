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
			float nx = float(x) / (w - 1);
			float ny = float(y) / (h - 1);

			CvScalar f = cvGet2D(src, y, x);
			float avg = (f.val[0]+ f.val[1]+ f.val[2])/3.0;
			CvScalar g = cvScalar(avg, avg, avg);
			float a = (nx + ny) / 2;
			float b = (nx - ny) / 2;

			if (a >= 0.25 && a <= 0.75)
				if (b <= 0.25f && b >= -0.25f)
					g = f;

			cvSet2D(dst, y, x, g);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}