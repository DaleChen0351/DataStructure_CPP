#include <iostream>
#include <list>
using namespace std;

class Vertex
{

};


template<class T>
class Graph
{
public:
    Graph(const int ver) :n(ver) {
        nVerts = 0;
        VertexList = new T*[n];// 指针数组
        headNodes = new list<int>[n];
    }
    ~Graph()
    {
        delete[] VertexList;
        delete[] headNodes;
    }

    void addVertex(T* v);
    void addEdge(int start, int end);
    void printVertice();
    void printAdjList(); 

private:
    T** VertexList;//所有的顶点的地址的数组首地址？
    list<int>* headNodes;// list<int>类型的数组的首地址
    
    int n;
    int nVerts;
};


template<class T>
void Graph<T>::addVertex(T * v)
{
    VertexList[nVerts++] = v;
}

template<class T>
void Graph<T>::addEdge(int start, int end)
{
    headNodes[start].push_back(end);
}

template<class T>
void Graph<T>::printVertice()
{
    for (int i = 0; i < nVerts; i++)
    {
        cout << *VertexList[i] << " ";
    }
}
template<class T>
void Graph<T>::printAdjList()
{
    for (int i = 0; i < nVerts; i++)
    {
        cout << i << "->";
        for (list<int>::iterator iter = headNodes[i].begin(); iter != headNodes[i].end(); ++iter)
        {
            cout << *iter << "->";
        }
        cout << "end" << endl;
    }

}


void test_02()
{
    Graph<char> g(5);
    char nodeA = 'A';
    g.addVertex(&nodeA);

    char nodeB = 'B';
    g.addVertex(&nodeB);

    char nodeC = 'C';
    g.addVertex(&nodeC);

    char nodeD = 'D';
    g.addVertex(&nodeD);

    char nodeE = 'E';
    g.addVertex(&nodeE);

    g.addEdge(0, 1);//A-B,用数组下标来增加边，此处为在A,B间增加一条边
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(3, 4);//
    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 3);

    g.printVertice();
    cout << endl;
    g.printAdjList();
}
