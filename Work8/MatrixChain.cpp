#include<iostream>
using namespace std;
const int N = 100;
int P[]={5,6,2,9,7,6}, m[N][N] = { 0 }, s[N][N] = { 0 };
int n = sizeof(P) / sizeof(int);
void Print(int i, int j) {
	if (i == j)
		cout << "a" << i;
	else {
		cout << "(";
		Print(i, s[i][j]);
		Print(s[i][j] + 1, j);
		cout << ")";
	}
}
void Print(int s[][N], int i, int j) {
	if (i == j) 
		cout << "A" << i;
	else{
		cout << "(";
		Print(s, i, s[i][j]);
		Print(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int MatrixChain(int P[], int n){
for(int i = 1; i < n; i++)
	for (int j = 1; j < n; j++)
		m[i][j] = 0;
	
	for (int r = 2; r < n; r++) {//r为当前问题规模长度
		for (int i = 1; i < n - r + 1; i++) {//i根据r变化，不同起点
			int j = i + r - 1;//不同终点
			m[i][j] = m[i + 1][j] + P[i - 1] * P[i] * P[j];
			s[i][j] = i;//存储i记录分割位置
			for (int k = i; k < j; k++) {
				int temp = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
				if (temp < m[i][j]) {
					m[i][j] = temp;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][n - 1];
}
int main() {
	cout << MatrixChain(P, n) << endl;
	Print(s,1, n-1);
}

