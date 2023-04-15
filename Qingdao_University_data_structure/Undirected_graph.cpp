#include<iostream>
#include<cstring>
#define MAXSIZE 100
typedef int vertexType;
typedef int edgeType;
using namespace std;

// 用两个数组分别存储顶点表和邻接矩阵
typedef struct{
    vertexType vertexList[MAXSIZE];
    edgeType edgeMatrix[MAXSIZE][MAXSIZE];
    int vertexNumber, edgeNumber;
}AMGraph;

// 用邻接矩阵表示法创建无向网
class UndirectedAMGraph{
public:
    AMGraph *G;

    UndirectedAMGraph(){
        G = new AMGraph;
        memset(G->edgeMatrix, 0, sizeof(G->edgeMatrix));  // 这里的memset主要是将G->edgeMatrix的值全部置为0
        memset(G->vertexList, 0, sizeof(G->vertexList));  // 这里的memset主要是将G->vertexList的值全部置为0
    }

    int locateVertex(vertexType v);
    void createVertexList();
    void createEdgeMatrix();
    void createAMGraph();
};

// 定位顶点在顶点表中的位置
int UndirectedAMGraph::locateVertex(vertexType v){
    for (int i =0 ;i <G->vertexNumber;i++)
    {
        if(G->vertexList[i] == v)
            return i;
    }
    return -1;
}

// 创建一个顶点表用来记录各个顶点信息
void UndirectedAMGraph::createVertexList(){
    cout << "Input Vertex Number of the undirected graph:" << endl;
    int vertexNumber;
    cin >> vertexNumber;
    G->vertexNumber = vertexNumber;

    cout << "Input all the Vertexes:" << endl;
    int i = 0;
    while(vertexNumber--)
    {
        int vertex;
        cin >> vertex;
        G->vertexList[i++] = vertex;
    }
}

// 创建一个邻接矩阵用来记录各个顶点之间的边信息
void UndirectedAMGraph::createEdgeMatrix(){
    cout << "Input Edge number of the undirected graph:" << endl;
    int edgeNumber;
    cin >> edgeNumber;
    G->edgeNumber = edgeNumber;

    while(edgeNumber--)
    {
        cout << "Input Edge:" << endl;
        int i,j,a,b;
        cin >> a >> b;
        i = locateVertex(a);
        j = locateVertex(b);
        if(i && j)
        {
            G->edgeMatrix[i][j] = 1;
            G->edgeMatrix[j][i] = 1;
        }
    }
}

// 创建一个无向网
void UndirectedAMGraph::createAMGraph()
{
    createVertexList();
    createEdgeMatrix();
}

int main()
{
    UndirectedAMGraph g;
    g.createAMGraph();
    cout << "Vertex List:" << endl;
    for(int i = 0;i<g.G->vertexNumber;i++)
    {
        cout << g.G->vertexList[i] << " ";
    } 
    cout << endl;

    cout << "Edge Matrix:" << endl;
    for(int i =0 ;i<g.G->vertexNumber;i++)
    {
        for(int j =0;j<g.G->vertexNumber;j++)
        {
            cout << g.G->edgeMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

