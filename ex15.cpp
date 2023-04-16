#include <opencv2/opencv.hpp>

int main()
{
	IplImage* src = cvLoadImage("C:\\temp\\Lena.png");
	CvSize size = cvGetSize(src);
	IplImage* dst = cvCreateImage(size, 8, 3);
	int w = size.width;
	int h = size.height;

	int blocksize = 30;
	for (int y = 0; y < h-blocksize; y+=blocksize)
	{
		printf("%d\n", y);
		for (int x = 0; x < w-blocksize; x+=blocksize)
		{
			float sum[3] = { 0 };
			for (int i = 0; i <  blocksize; i++)
			{
				for (int j = 0; j < blocksize; j++)
				{
					CvScalar f = cvGet2D(src, y+i,x+ j);

					for (int k = 0; k < 3; k++)
					{
						sum[k] += f.val[k];
					}
				}
			}
			for (int k = 0; k < 3; k++)
				sum[k] /= blocksize * blocksize;
			for (int i = 0; i < blocksize; i++)
			{
				for (int j = 0; j < blocksize; j++)
				{
					cvSet2D(dst, y + i, x + j, cvScalar(sum[0], sum[1], sum[2]));
				}
			}
			
		}
	}

	cvShowImage("src", src);
	cvShowImage("dst", dst);
	cvWaitKey();
	return 0;
}