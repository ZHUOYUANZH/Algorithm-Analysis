#include <iostream>
#include <algorithm> 
using namespace std;
int N = 7;//数组长度
int A[] = { 99,11,22,1000,1,100,121 };//数组
int Select(int A[], int left, int right, int k)
{
	int p = right - left;//计算数组大小
	if (p < 5)//规模小，直接排序
	{
		sort(A + left, A + right);
		return A[left + k - 1];
	}
	int q = p / 5;//分为q组
	int* M = new int[q];
	for (int i = 0; i < q; i++)
	{	//排序后得到中位数
		sort(A + left + 5 * i, A + left + 5 * (i + 1) );
		M[i] = A[left + i * 5 + 2];
	}
	sort(M, M + q);
	int Mid = M[q / 2];
	int* A1 = new int[p];
	int* A2 = new int[p];
	int* A3 = new int[p];
	int count1 = 0, count2 = 0, count3 = 0;
	for (int i = left; i < right; i++)
	{
		if (A[i] < Mid)
			A1[count1++] = A[i];
		else if (A[i] == Mid)
			A2[count2++] = A[i];
		else
			A3[count3++] = A[i];
	}
	if (count1 >= k) //若小于mid的数超过k个
		return Select(A1, 0, count1, k);
	if (count1 + count2 >= k)
		return Mid;
	return Select(A3, 0, count3, k - count1 - count2);
}

int main()
{
	cout << "数组：";
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	int k = 3;
	cout << endl << "第" << k << "小元素为:" << Select(A, 0, N, k);
}
