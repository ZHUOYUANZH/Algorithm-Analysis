#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int weight;//权重
    int lchild, rchild, parent;//双亲和左右孩子下标
}HTNode, * HuffmanTree;
typedef char** HuffmanCode;
HuffmanCode HC;
HuffmanTree HT;
int s1, s2;
void SelectMin(HuffmanTree tree, int n) { //找出权值最小的两棵树
    int min = 1;//存放临时最小值
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == 0) {//找出一个暂时的最小值
            min = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == 0 && tree[i].weight < tree[min].weight) {//找出第一个最小值
            min = i;
        }
    }
    s1 = min;
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == 0 && i != s1) {//找出一个暂时的最小值
            min = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == 0 && tree[i].weight < tree[min].weight && i != s1) {//找出第二个最小值
            min = i;
        }
    }
    s2 = min;
}
void Huffman(HuffmanTree tree, int* w, int n) {//哈夫曼编码
    int m = 2 * n - 1;//哈夫曼树的节点数
    tree = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for (int i = 1; i <= m; i++) {//初始化树
        tree[i].lchild = 0;
        tree[i].rchild = 0;
        tree[i].parent = 0;
        if (i <= n) {//设置权值
            tree[i].weight = w[i];
        }
        else {
            tree[i].weight = 0;
        }
    }
    for (int i = n + 1; i <= m; i++) {
        SelectMin(tree, i - 1);
        tree[s1].parent = tree[s2].parent =i;
        tree[i].lchild = s1,tree[i].rchild = s2;
        tree[i].weight = tree[s1].weight + tree[s2].weight;//i的权值为s1与s2的和
    }
    HC = (HuffmanCode)malloc((n + 1) * (sizeof(char*)));//存放n个哈夫曼编码
    char* cd;
    cd = (char*)malloc(n * sizeof(char));//暂存哈夫曼编码
    cd[n - 1] = '\0';//编码结束符
    int start;
    for (int i = 1; i <= n; i++) {
        start = n - 1;//初始点
        for (int j = i, f = tree[i].parent; f != 0; j = f, f = tree[f].parent) { //逆向求哈夫曼编码
            if (tree[f].lchild == j) cd[--start] = '0'; //向左为0
            else cd[--start] = '1';//向右为1
        }
        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);//将该字符的哈夫曼编码赋到HC中
    }
    free(cd);
}
int main() {
    int n = 8;
    int w[100] = { 0,8,6,4,1,2,3,3,1 };//存放每个字符的权值
    Huffman(HT, w, n);
    for (int i = 1; i <= n; i++) {//输出每个字符的哈夫曼编码
        printf("%d:%s\n", w[i],HC[i]);
    }
}
