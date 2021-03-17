//
//  Dijkstra.cpp
//  Work2
//
//  Created by ZHUOYUAN on 2021/3/17.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define MAX 1000//顶点数
#define INF 0x3f3f3f3f//无穷大
using namespace std;
int distmap[MAX][MAX], dist[MAX], visited[MAX], path[MAX];//距离矩阵，到各点距离，访问集合
int n, m, start, End;//顶点数，边数,起点，终点
stack<int>Stack;//存储path的Stack
void Init()
{
    //初始化
    memset(path, 0, sizeof(path));
    memset(visited, 0, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    memset(distmap, INF, sizeof(distmap));
    cin >> n >> m;//输入顶点数和边数
    int u, v, dis;
    for (int i = 1; i <= m; i++)//输入边
    {
        cin >> u >> v >> dis;
        distmap[u][v] = dis;
    }
    for (int i = 1; i <= n; i++)//顶点自身初始化为0
        distmap[i][i] = 0;
    cin >> start >> End; //输入起点和终点
}
int Dijkstra(int start,int End)
{
    cout << "Dijkstra:" << endl;
    dist[start] = 0;  //到起点自身的距离为0
    for (int i = 1; i <= n; i++)
    {
        int u, MIN = INF;
        for (int j = 1; j <= n; j++)//寻找此时dist[]中的最小值
        {
            if (dist[j] < MIN && visited[j] == 0)
            {
                MIN = dist[j];
                u = j;
            }
        }
        //u为新的起点
        visited[u] = 1;  //在路径集合中加入该点
        for (int j = 1; j <= n; j++)
            if (dist[j] > dist[u] + distmap[u][j])
            {
                dist[j] = dist[u] + distmap[u][j];//更新与u相邻的dist
                path[j] = u;//并记录下路径
            }
        if(visited[End]==1) break;//若终点的最短路径找到，结束循环
    }
    return dist[End];
}
void PushPath(int End)
{
    int before= path[End];//先将path push入stack
    while (before!=start)
    {
        Stack.push(before);
        before = path[before];
    }
}
void PopPath() {
    cout << "Path:" << endl;
    cout << (char)('a' + start - 1) <<"->" ;
    while (Stack.size()!=0)//再逆序pop出路径
    {
        cout <<(char)('a'+Stack.top()-1) << "->";
        Stack.pop();
    }
    cout << (char)('a' + End - 1);
}
int main()
{
    Init();
    cout <<"shortest distance is " <<Dijkstra(start,End) << endl;;//执行Dijkstra算法
    PushPath(End);//将path push入stack
    PopPath();//再pop出路径
    return 0;
}


//样例
//8 11
//1 2 1
//2 4 2
//3 1 2
//4 3 1
//4 6 8
//5 4 2
//5 7 2
//6 5 2
//7 6 3
//7 8 3
//8 6 2
//1 8
