// 带权值的有向图的建立
#include <iostream>
using namespace std;

class DirectAGraph{
private:
    int *vertexList;  // 顶点表
    int **edgeMatrix;  // 邻接矩阵
    int vertexNum;  // 顶点数
    int edgeNum;  // 边数
public:
    DirectAGraph (int vertexNum, int edgeNum){
        this->vertexNum = vertexNum;
        this->edgeNum = edgeNum;
        this->vertexList = new int[vertexNum]{0};
        this->edgeMatrix = new int *[vertexNum];
        for (int i = 0; i < vertexNum; i++){
            this->edgeMatrix[i] = new int[vertexNum]{0};
        }

        cout << "Input " << vertexNum << " vertexes" << endl;
        int index = 0;
        while (vertexNum--)
        {
            cin >> this->vertexList[index++];
        }
        cout << "Input " << edgeNum << " edges" << endl;
        while(edgeNum--)
        {
            int i, j;
            int weight;
            int a ,b;
            cin >> a >> b;
            cin >> weight;
            i = locateVertex(a);
            j = locateVertex(b);
            if (i!=-1 && j!=-1)
            {
                edgeMatrix[i][j] = weight;
            }else {
                cout << "Error";
                exit(0);
            }
        }
    }
    int locateVertex(int vertex){
        for (int i = 0; i < this->vertexNum;i++)
        {
            if (vertex == this->vertexList[i])
            {
                return i;
            }
        }
        return -1;
    }

    void showGraph(){
        cout << "Here show the data structure of adjacency graph" << endl;
        cout << "Vertex List:" << endl;
        for (int i =0 ;i<this->vertexNum;i++)
        {
            cout << this->vertexList[i] << " ";
        }
        cout << endl << "Edge Matrix:" << endl;
        for (int i = 0; i < this->vertexNum; i++)
        {
            for (int j = 0; j < this->vertexNum; j++)
            {
                cout << this->edgeMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    DirectAGraph graph(6,9);
    graph.showGraph();
}