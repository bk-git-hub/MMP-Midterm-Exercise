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
			CvScalar sc = cvGet2D(src, y, x);

			if (y < h / 2)
			{
				if (x < w / 2)
					cvSet2D(dst, h/2 - y , w/2 - x, sc);
				else
					cvSet2D(dst, h/2 -y , w*3/2-1-x, sc);
			}
			else
			{
				if (x < w / 2)
					cvSet2D(dst, h*3/2-1 -y, w/2-x, sc);
				else
					cvSet2D(dst, h*3/2-1 - y, w*3/2-1-x, sc);

			}
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}