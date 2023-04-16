//无向图创建与遍历 
 
#include<iostream>
using namespace std;
#include<queue>
#define MaxSize 100
 
typedef struct{
	int data;
	int vertex[MaxSize];    //数组中存储保存的节点值 
	int arc[MaxSize][MaxSize];   //这个二维数组保存邻接矩阵
	int vertexnum;   //记录图中节点个数 
	int arcnum; 	// 记录图中边的个数 
}Graph;
 
 
 
int visited[MaxSize];   //全局遍历，用于记录节点是否被访问过 
 
void DFSTraverse(Graph G, int v)   
{
	cout<<G.vertex[v];
	visited[v]=1;
	
	for(int i=0; i<G.vertexnum; i++)
	{
		if(G.arc[v][i]==1 && visited[i]==0)  //arc[v][i]=1表示: 顶点v到邻接点i有边，且这个邻接点没有被访问过。 则深度优先递归访问这个邻接点。 
		{
			DFSTraverse(G,i);
		}
	}
}
 
 
 
void BFSTraverse(Graph G, int v, queue<int> Q)
{
	cout<<G.vertex[v];
	visited[v]=1;
	
	Q.push(G.vertex[v]);
	
	while(!Q.empty())
	{
		int val = Q.front();   //队列是队头出队，队尾进队 
		Q.pop();
		
		for(int i=0; i<G.vertexnum; i++)
		{
			if(G.arc[val][i]==1 && visited[i]==0)
			{
				cout<<G.vertex[i];
				visited[i]=1;
				Q.push(G.vertex[i]);
			}
		}
	 } 
	
 } 
 
void Creat_Graph(Graph &G, int n, int e, int arr[])   //如果不是在类里面，要传入图G的引用。否则创建图不成功 
{
	G.vertexnum=n;
	G.arcnum=e;
	
	for(int i=0; i<G.vertexnum; i++)  //把数组中的每个节点值保存在图中 
	{
		G.vertex[i]=arr[i];
	}
	//让visited[]数组值为0， 表示没有被访问过。 **调用过一次深度遍历或广度遍历，都需要重新给visited赋值， 
//	for(int i=0; i<G.vertexnum; i++)
//	{
//		visited[i]=0;
//	}
	
	for(int i=0; i<G.vertexnum; i++)    //当有n的节点的时候， n*n的矩阵，初始值都为0，表示任何两个顶点之间都没边 
	{
		for(int j=0; j<G.vertexnum; j++)
		{
			G.arc[i][j]=0;
		}
	}
	
	//开始生成边  无向图中，如果1->2有条边，则2->1也有条边， 
	for(int i=0; i<G.arcnum; i++)
	{
		int a,b;
		cin>>a>>b;
		
		G.arc[a][b]=1;
		G.arc[b][a]=1;	
	 } 
}
 
 
void set_visited(Graph G)
{
	for(int i=0; i<G.vertexnum; i++)
	{
		visited[i]=0;
	}
 } 
 
int main()
{
	queue<int> Q;
	int n,e;   //n是节点数，e是边数 
	Graph G;
	cin>>n>>e;
	
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	Creat_Graph(G,n,e,arr);
	set_visited(G);
	cout<<" DFSTraverse: ";
	DFSTraverse(G,0);
	set_visited(G);
	cout<<endl<<" BFSTraverse: ";
	BFSTraverse(G, 0, Q);
	return 0; 
}
 
 