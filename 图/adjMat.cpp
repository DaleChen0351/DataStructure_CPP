#include <iostream>
#include <stack>
#include <queue>
#define MAX_VERTS 20
using namespace std;

//����
//������ �������ǶԳ�
// �Խ���Ϊ0


//Vertex ����
class Vertex
{
public:
    Vertex(char lab) :Label(lab),isVisited(false) {}
public:
    char Label;
    bool isVisited;// �Ƿ񱻷��ʹ��ˣ����������в������ظ�����
};

ostream& operator<<(ostream& os, const Vertex v)
{
    os << v.Label;
    return os;
}

// �������飬�������ڽӾ���
class Graph
{
public:
    Graph();
    ~Graph();
    void addVertex(char lab);
    void addEdge(int start, int end);
    void printMatrix();
    void showVertex(int index);//��ʾĳ�����������
    void DFS();
    void BFS();

private:
    Vertex* vertexList[MAX_VERTS];// ADT Graph ��������ݶ���
    int adjMat[MAX_VERTS][MAX_VERTS];// ADT Graph ��������ݹ�ϵ��

    int nVerts;// ͼ�а����Ķ�����
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
    s.push(0);//�ѷ��ʹ��Ķ���ѹ���ջ
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
    //������һ���Ϊ�����ظ�����
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
        vert1 = q.front();//���ʶ��е�һ��
        q.pop();//������ʹӶ�����ɾ��
        vert2 = getAdjUnvisitedVertex(vert1);//��vert1���ڽӵģ�δ���ʹ���
        while (vert2 != -1)//���ڽӵĿ��ܲ�ֹһ��
        {
            vertexList[vert2]->isVisited = true;
            showVertex(vert2);
            q.push(vert2);//������һ���ʹӶ�����ɾ���Ǹ�
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

//�������