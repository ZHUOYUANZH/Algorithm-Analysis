//
//  main.cpp
//  Search
//
//  Created by ZHUOYUAN on 2021/3/22.
//
#include<iostream>
using namespace std;
int BinarySearch(int T[], int value, int n)
{
    cout<<"BinarySearch:"<<endl;
    int left=0,right=n-1,mid;
    while(left<=right)
    {
        mid=(left+right)/2;//中点
        if(T[mid]==value)//相等则return
            return mid+1;
        if(T[mid]>value)//太大
        right=mid-1;//right左移至中点
        else//太小则left右移至中点
        left=mid+1;
    }
    return 0;//没有找到返回0
}
int InsertionSearch(int T[], int value,int n)
{
    cout<<"InsertionSearch:"<<endl;
    int left=0,right=n-1,mid;
    while(left<=right)
    {
        int mid = left+(value-T[left])/(T[right]-T[left])*(right-left);
        if(T[mid]==value)//相等则return
            return mid+1;
        if(T[mid]>value)//太大
        right=mid-1;//right左移至中点
        else//太小则left右移至中点
        left=mid+1;
    }
    return 0;//没有找到返回0
}
int main(){
    int T[]={1,3,5,6,8,10,15,23,43,55,62,67,68,89};
    int n=sizeof(T)/sizeof(int);//数组长度
    cout<<BinarySearch(T,15,n)<<endl;//二分查找
    cout<<InsertionSearch(T,15,n)<<endl;//插值查找
}
