#include <iostream>
#include <iomanip>
using namespace std;
const int N = 100;

int F[N][N], f[N][N], X[N][N];
int m,n;
int DPinvest() {
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= j; k++)
				if (f[i][k] + F[i - 1][j - k] > F[i][j]) {
					F[i][j] = F[i - 1][j - k] + f[i][k];
					X[i][j] = k;
				}
	cout << setw(4) << "X" << setw(10)
		<< "F1(x)" << setw(10) << "X1(x) "
		<< setw(6) << "F2(x)" << setw(10) << "X2(x) "
		<< setw(6) << "F3(x)" << setw(10) << "X3(x) "
		<< setw(6) << "F4(x)" << setw(10) << "X4(x) "
		<< endl;
	for (int i = 1; i <= n; i++) {
		cout << setw(4) << i;
		for (int j = 1; j <= m; j++) {
			cout << setw(8) << F[j][i] << setw(8) << X[j][i];
		}
		cout << endl;
	}
	return F[m][n];
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) 
		for (int j = 0; j <= n; j++) 
			cin >> f[i][j];//表示第i个项目投资j元
	cout << "最高收益：" << DPinvest();
}
/*
4 5
0 11 12 13 14 15
0 0 5 10 15 20
0 2 10 30 32 40
0 20 21 22 23 24
*/
