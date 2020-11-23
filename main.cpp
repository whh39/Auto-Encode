#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat frame = imread("timg.jpg");
	cvtColor(frame, frame, CV_RGB2GRAY);

	int col = 20;
	//相当于把图片按列降维
	PCA pca(frame, Mat(), CV_PCA_DATA_AS_ROW, col);

	cout << "均值的规格：" << pca.mean.size() << endl;
	cout << "特征值的规格：" << pca.eigenvalues.size() << endl;
	cout << "特征向量的规格：" << pca.eigenvectors.size() << endl;

	Mat dst = pca.project(frame);//映射
	Mat src = pca.backProject(dst);//反映射

	imwrite("PCA处理.jpg", dst);
	imwrite("反映射.jpg", src);


	imshow("原图", frame);
	imshow("PCA处理", dst);
	imshow("反映射", src);

	waitKey(-1);

	return 0;


}