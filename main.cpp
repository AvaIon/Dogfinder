#include"stdafx.h"
#include<opencv2/opencv.hpp>
#include<vector>
using namespace cv;
using namespace std;
int main()
{
	CascadeClassifier haarfaceCascader;
	String dogfile = "C://Users/A/Desktop/文件/xml/xml/dogcascade.xml";

	Mat src = imread("dog7.jpg");
	Mat gray;
	vector<Rect> faces;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	equalizeHist(gray, gray);

	if (!haarfaceCascader.load(dogfile))
	{
		printf("can not load the haar file \n");
		return -1;
	}
	haarfaceCascader.detectMultiScale(gray, faces, 1.1, 3, 0, Size(50, 50), Size(200, 200));


	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(src, faces[i], Scalar(0, 255, 0), 2, 8, 0);
	}

	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	waitKey(0);
	return 0;
}
