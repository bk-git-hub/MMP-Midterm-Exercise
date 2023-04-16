#include <opencv2/opencv.hpp>
CvScalar conDown(CvScalar f)
{
	f.val[0] *= 0.5;
	f.val[1] *= 0.5;
	f.val[2] *= 0.5;

	return f;
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
			CvScalar g;
			int cx = (float)x / w * 4;
			int cy = (float)y / h * 4;

			float nx = 2 * ((float)x - cx * w / 4)/w*4.0 - 1;
			float ny = 2 * ((float)y - cy * h / 4)/h*4.0 - 1;

			float alpha = sqrt((nx * nx) + (ny * ny));
			if (alpha > 1)
				g = conDown(f);
			else
				g = f;


			cvSet2D(dst, y, x, g);
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}