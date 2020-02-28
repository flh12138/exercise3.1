#include<opencv2/opencv.hpp>

using namespace cv;

int main() {
	uchar threshold = 100;
	cv::Mat srcMat = imread("C://112.jpg");
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {

			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold) {
				average = 255;
				srcMat.at<Vec3b>(j, i)[0] = average;
				srcMat.at<Vec3b>(j, i)[1] = average;
				srcMat.at<Vec3b>(j, i)[2] = average;
			}
			else {
				srcMat.at<Vec3b>(j, i)[0] = 0;
				srcMat.at<Vec3b>(j, i)[1] = 0;
				srcMat.at<Vec3b>(j, i)[2] = 0;
			}
		}
	}
	imshow("src", srcMat);
	waitKey(0);


}

