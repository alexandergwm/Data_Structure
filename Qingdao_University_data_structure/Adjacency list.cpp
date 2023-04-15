// 邻接表的创建
#include<iostream>
#define MAXSIZE 100
using namespace std;


// 定义边表结点
typedef struct edgeNode{
    int adjID; // 邻接点域，存储该顶点对应的下标
    int weight; // 用于存储权值，对于非网图可以不需要
    edgeNode *next; // 链域，指向下一个邻接点
};


// 定义顶点的结构体
typedef struct vertexNode{
    int data;
    edgeNode *first; // 指向第一条依附该顶点的边的指针
};

// 定义图的结构体
typedef struct undirectedAGraph{
    int vertexNum; // 顶点数
    int edgeNum; // 边数
    vertexNode vertexList[MAXSIZE]; // 顶点数组
};

int locateVertex(undirectedAGraph *G,int v)
{
    for(int i =0;i<G->vertexNum;i++)
    {
        if (v==G->vertexList[i].data)
        {
            return i;
        }
    }
    return -1;
}

void initAGraph(undirectedAGraph *&G)
{
    G = new undirectedAGraph;
    cout << "请输入顶点数" << endl;
    cin >> G->vertexNum;
    cout << "请输入边数" << endl;
    cin >> G->edgeNum;
    for(int i = 0;i<G->vertexNum;i++)
    {
        G->vertexList[i].first = nullptr;
    }

}

void createAGraph(undirectedAGraph * &G)
{
    cout << "请输入顶点信息" << endl;
    int vertexNum = G->vertexNum;
    int index = 0;
    while(vertexNum--)
    {
        cin >> G->vertexList[index++].data;
    }
    cout << "请输入边信息" << endl;
    int edgeNum = G->edgeNum;
    while(edgeNum--)
    {
        int i,j,a,b,w;
        cin >> i >> j >> w;
        i = locateVertex(G,i);
        j = locateVertex(G,j);
        if (i!=1&&j!=1)
        {
            edgeNode *e1 = new edgeNode;
            edgeNode *e2 = new edgeNode;
            e1->weight = w;
            e2->weight = w;
            e1->adjID = j;
            e2->adjID = i;
            e1->next = G->vertexList[i].first;
            G->vertexList[i].first = e1;
            e2->next = G->vertexList[j].first;
            G->vertexList[j].first = e2;
        }
    }
}

void showAGraph(undirectedAGraph *G)
{
    cout << "顶点信息" << endl;
    for (int i =0;i<G->vertexNum;i++)
    {
        cout << G->vertexList[i].data << " ";
    }
    cout << endl;
    cout << "边信息" << endl;
    for (int i =0;i<G->vertexNum;i++)
    {
        edgeNode *e = G->vertexList[i].first;
        while(e)
        {
            cout << G->vertexList[i].data << " " << G->vertexList[e->adjID].data << " " << e->weight << endl;
            e = e->next;
        }
    }
}


int main() {
    printf("Declaring...\n");
    undirectedAGraph *g;
    printf("Initialing...\n");
    initAGraph(g);
    printf("Creating...\n");
    createAGraph(g);
    printf("Showing...\n");
    showAGraph(g);
}