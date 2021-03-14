//
//  Kruskal.cpp
//  
//
//  Created by ZHUOYUAN on 2021/3/14.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=100;
int n,m,father[MAX];//边数，定点数，各点连通分量的根节点（并查集）

struct Edge{
    int u,v,cost;
}t[MAX*MAX/2];// 无向连通带权图的邻接矩阵

int cmp(Edge &a,Edge &b){//根据权值排序
    return a.cost<b.cost;
}
int find(int x){//判断连通分支
    return (x==father[x])?x:father[x]=find(father[x]);
}
void merge(int x,int y){//加入同一连通分支
    father[find(x)]=find(y);
}
int Kruskal()
{
        cout<<"Kruskal:"<<endl;
        sort(t+1, t+m+1, cmp);//排序
        for(int i=1;i<=n;i++) father[i]=i;//并查集初始化为自身
        int total=0;//所选取的边数
        int sumweight=0;//权重和
        for(int i=1;i<=m;i++){
            if(total==n-1) break; //n-1时形式最小生成树
            int x=t[i].u,y=t[i].v;
            if(find(x)!=find(y)){//若不是同一连通分支
                cout<<x<<"--"<<y<<":"<<t[i].cost<<endl;
                sumweight+=t[i].cost;
                merge(x,y);//加入同一连通分支
                total++;
            }
        }
        return sumweight;//返回权重和
}
int main(){
        int x,y,cost;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>cost;
            t[i].u=x;t[i].v=y;t[i].cost=cost;
        }
        cout<<"the minimum sumweight is "<<Kruskal()<<endl;
        
}
