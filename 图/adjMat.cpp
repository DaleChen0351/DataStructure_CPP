#include <iostream>
#include <stack>
#include <queue>
#define MAX_VERTS 20
using namespace std;

//特征
//上三角 和下三角对称
// 对角线为0


//Vertex 顶点
class Vertex
{
public:
    Vertex(char lab) :Label(lab),isVisited(false) {}
public:
    char Label;
    bool isVisited;// 是否被访问过了，搜索过程中不允许重复访问
};

ostream& operator<<(ostream& os, const Vertex v)
{
    os << v.Label;
    return os;
}

// 定义数组，用来做邻接矩阵
class Graph
{
public:
    Graph();
    ~Graph();
    void addVertex(char lab);
    void addEdge(int start, int end);
    void printMatrix();
    void showVertex(int index);//显示某个顶点的内容
    void DFS();
    void BFS();

private:
    Vertex* vertexList[MAX_VERTS];// ADT Graph 里面的数据对象？
    int adjMat[MAX_VERTS][MAX_VERTS];// ADT Graph 里面的数据关系？

    int nVerts;// 图中包含的顶点数
    int getAdjUnvisitedVertex(int v);

};
Graph::Graph()
{
    nVerts = 0;
    for (int i = 0; i < MAX_VERTS; i++)
    {
        for (int j = 0; j < MAX_VERTS; j++)
        {
            adjMat[i][j] = 0;
        }
    }
}
void Graph::addVertex(char lab)
{
    vertexList[nVerts++] = new Vertex(lab);
}


void Graph::addEdge(int start, int end)
{
    adjMat[start][end] = 1;
    adjMat[end][start] = 1;
}



void Graph::printMatrix()
{
    for (int i = 0; i < nVerts; i++)
    {
        for (int j = 0; j < nVerts; j++)
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::showVertex(int index)
{
    cout << *vertexList[index] << " ";
}

int Graph::getAdjUnvisitedVertex(int v)
{
    for (int i = 0; i < nVerts; i++)
    {
        if (adjMat[v][i] == 1 && vertexList[i]->isVisited == false)
        {
            return i;
        }
    }
    return -1;
}

void Graph::DFS()
{
    stack<int>s;
    showVertex(0);
    vertexList[0]->isVisited = true;
    s.push(0);//把访问过的顶点压入堆栈
    while (s.size() > 0)
    {
        int next = getAdjUnvisitedVertex(s.top());
        if (next == -1)
        {
            s.pop();
        }
        else
        {
            vertexList[next]->isVisited = true;
            showVertex(next);
            s.push(next);
        }
    }
    cout << endl;
    //搜索完一遍后，为了能重复进行
    for (int j = 0; j < nVerts; j++)
        vertexList[j]->isVisited = false;
}

void Graph::BFS()
{
    queue<int> q;
    vertexList[0]->isVisited = true;
    showVertex(0);
    q.push(0);
    int vert1;
    int vert2;
    while (q.size() > 0)
    {
        vert1 = q.front();//访问队列第一个
        q.pop();//访问完就从队列里删掉
        vert2 = getAdjUnvisitedVertex(vert1);//和vert1相邻接的，未访问过的
        while (vert2 != -1)//相邻接的可能不止一个
        {
            vertexList[vert2]->isVisited = true;
            showVertex(vert2);
            q.push(vert2);//访问完一个就从队列里删掉那个
            vert2 = getAdjUnvisitedVertex(vert1);
        }
       
    }
}



Graph::~Graph()
{
    for (int i = 0; i < nVerts; i++)
    {
        delete vertexList[i];
    }
}


void test_01()
{
    Graph g;
    g.addVertex('A');// index = 0;
    g.addVertex('B'); // index = 1;
    g.addVertex('C');// index =2;
    g.addVertex('D');// index =3;
    g.addVertex('E'); // index =4;

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.printMatrix();

    cout << endl;
    g.DFS();
    cout << endl;
    g.BFS();
}

//深度优先