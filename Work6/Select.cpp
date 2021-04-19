#include <iostream>
#include <algorithm> 
using namespace std;
int N = 7;//���鳤��
int A[] = { 99,11,22,1000,1,100,121 };//����
int Select(int A[], int left, int right, int k)
{
	int p = right - left;//���������С
	if (p < 5)//��ģС��ֱ������
	{
		sort(A + left, A + right);
		return A[left + k - 1];
	}
	int q = p / 5;//��Ϊq��
	int* M = new int[q];
	for (int i = 0; i < q; i++)
	{	//�����õ���λ��
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
	if (count1 >= k) //��С��mid��������k��
		return Select(A1, 0, count1, k);
	if (count1 + count2 >= k)
		return Mid;
	return Select(A3, 0, count3, k - count1 - count2);
}

int main()
{
	cout << "���飺";
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	int k = 3;
	cout << endl << "��" << k << "СԪ��Ϊ:" << Select(A, 0, N, k);
}
