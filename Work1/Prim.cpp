//
//  main.cpp
//  Work1
//  Prim
//  Created by ZHUOYUAN on 2021/3/14.
//

#include<iostream>
using namespace std;
const int MAX = 1000, INF = 9999999;
int cost[MAX][MAX];//二维数组定义全局变量否则容易溢栈，cost是无向连通带权图的邻接矩阵
int m,n,sumweight;//定义定点数，边数，权重和

int Prim(int start)//start为起始顶点
{
    int lowcost[MAX];//最小权值
    int closest[MAX];//前缀顶点
    bool S[MAX];//集合S
    cout<<"Prim:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        lowcost[i] = cost[start][i];//其余顶点与顶点start的最小距离
        closest[i] = start;
        S[i] = false;//初始化集合S为空
    }
    S[start] = true;//顶点start加入集合S
    for (int i = 1; i < n; i++)//处理其余n-1个顶点
    {
        int min = INF;
        int j = start;
        for (int k = 1; k <= n; k++)
        {
            if ((lowcost[k] < min) && (!S[k]))//找到不在集合S中的最小边权的顶点j
            {
                min = lowcost[k];
                j = k;
            }
        }
        sumweight += lowcost[j];
        S[j] = true;//顶点j加入S集合
        cout << closest[j] << "->" << j << ":" << lowcost[j] << endl;//输出这条路径
        for (int k = 1; k <= n; k++)//顶点j加入S集合后，要更新lowcost和closest
            if ((!S[k]) && (cost[j][k] < lowcost[k]))
            {
                lowcost[k] = cost[j][k];
                closest[k] = j;
            }
    }
    return sumweight;
}
int main() {
    int start;//起点
    int j, k, weight;//顶点j与k之间的权重weight
    cin >> n >> m >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = INF;//赋值无穷大
    for (int i = 1; i <= m; i++)
    {
        cin >> j >> k >> weight;
        cost[j][k] = cost[k][j] = weight;
    }
    cout << "the minimum sumweight is " << Prim(start) << endl;
}
