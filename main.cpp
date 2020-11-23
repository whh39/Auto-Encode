#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat frame = imread("timg.jpg");
	cvtColor(frame, frame, CV_RGB2GRAY);

	int col = 20;
	//�൱�ڰ�ͼƬ���н�ά
	PCA pca(frame, Mat(), CV_PCA_DATA_AS_ROW, col);

	cout << "��ֵ�Ĺ��" << pca.mean.size() << endl;
	cout << "����ֵ�Ĺ��" << pca.eigenvalues.size() << endl;
	cout << "���������Ĺ��" << pca.eigenvectors.size() << endl;

	Mat dst = pca.project(frame);//ӳ��
	Mat src = pca.backProject(dst);//��ӳ��

	imwrite("PCA����.jpg", dst);
	imwrite("��ӳ��.jpg", src);


	imshow("ԭͼ", frame);
	imshow("PCA����", dst);
	imshow("��ӳ��", src);

	waitKey(-1);

	return 0;


}