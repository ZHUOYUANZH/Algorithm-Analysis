#include <iostream>
#include <cmath> 
#include <algorithm>
using namespace std;
const int N = 1000;

typedef struct Point {//��Ľṹ�壬x��y��ʾ�������� 
	float x;
	float y;
}Point;

float distance(Point a, Point b) {//���������ĺ��� 
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(Point a, Point b) {//��x������������
	return a.x < b.x;
}

//���η������� 
float closest(Point* points, int n, Point& a, Point& b) {
	//�ݹ麯������,������ֱ�ӷ��ؾ���,һ����ʱ���������
	if (n == 2) {
		a = points[0];
		b = points[1];
		return distance(a, b);
	}
	else if (n == 1) {
		return 99999;
	}
	//���� 
	else {
		int n1 = n / 2;
		int n2 = n - n1;
		float d1, d2, dis, mid;
		Point points1[N];
		Point points2[N];
		Point a1, a2, b1, b2;
		mid = points[n1].x;
		for (int i = 0; i < n1; i++) {
			points1[i] = points[i];
		}
		for (int i = 0; i < n2; i++) {
			points2[i] = points[i + n1];
		}
		//������������ 
		d1 = closest(points1, n1, a1, b1);
		d2 = closest(points2, n2, a2, b2);
		if (d1 <= d2) {
			a = a1;
			b = b1;
			dis = distance(a, b);
		}
		else {
			a = a2;
			b = b2;
			dis = distance(a, b);
		}
		//�м�����
		Point points3[N];
		int k = -1;
		for (int i = 0; i < n; i++) {
			if (fabs(points[i].x - mid) <= dis) {
				points3[++k] = points[i];
			}
		}
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < i + 7 && j < k; j++) {
				if (distance(points3[i], points3[j]) < dis) {
					a = points3[i];
					b = points3[j];
					dis = distance(a, b);
				}
			}
		}
		return dis;

	}
}
int main(void) {
	Point points[7] = { {1.0,2.0},{1.1,6.2},{5.0,7.0},{15.0,12.5},{2.6,2.5},{5.9,4.6},{9.1,15.8} };
	for (int i = 0; i < 7; i++) {
		printf("(%f,%f)\n", points[i].x, points[i].y);
	}

	Point a, b;
	sort(points, points + 7, cmp);
	float dis = closest(points, 7, a, b);
	printf("����%f����a��%f��%f������b��%f��%f��", dis, a.x, a.y, b.x, b.y);
}

