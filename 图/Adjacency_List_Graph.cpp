#include <iostream>
#include <string>
#include "commonDefine.h"
#include <queue>

using namespace std;


//ǰ������
struct ArcNode;
struct OtherInfo
{
    float arcValue;
};
// �ڽӱ���
typedef struct VNode
{
    VertexType data;
    ArcNode* firstarc;// next point
    bool isVisted;
}VNode, AdjList[MAXNUM];

// �ڽӱ�߽ڵ�
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* nextarc;
    OtherInfo info;
}ArcNode;
//�ڽӱ���
typedef struct
{
    AdjList vertices;// ���ǰ�涨��������飬�������ֱ��ʵ����������Ҫ�����鳤��
    int vexnum;
    int arcnum;
}ALGraph;

int LocateVex(ALGraph G, VertexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (v == G.vertices[i].data)
        {
            return i;
        }
    }
    return -1;
}
Status CreateUDG(ALGraph & G)
{
    cout << "������ͷ������� �ͱ߽ڵ����" << endl;
    cin >> G.vexnum >> G.arcnum;
    //��ʼ��ͷ���
    cout << "������ͷ�ڵ���Ϣ" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
        G.vertices[i].isVisted = false;
    }
    return true;
}
void InsertArc(ALGraph&G, VertexType v1, VertexType v2, OtherInfo info)
{
    int i = LocateVex(G, v1);//�� i �� j
    int j = LocateVex(G, v2);
    //��Ϊ������ͼ������Ҫ���������߽ڵ�
    ArcNode* p1 = new ArcNode;
    //���ȱ�
    p1->adjvex = j;
    p1->info = info;
    // ͷ�巨
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;// �ӵ���β�ڵ�

    //��ȱ� �Գƽڵ�
    ArcNode* p2 = new ArcNode;
    p2->adjvex = i;
    p2->info = info;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
}

void printAdjList(ALGraph& G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << G.vertices[i].data << " : ";
        ArcNode* p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            cout << p->adjvex;
            p = p->nextarc;
            if (p != NULL)
            {
                cout << "-";
            }
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& os, const VNode& v)
{
    os << v.data;
    return os;
}

void bfs(ALGraph& G, const VertexType& v)
{
    queue<int>q;

    int root = LocateVex(G,v);
    
    cout << v << endl;
    G.vertices[root].isVisted = true;
    q.push(root);
    int cur;
    int next;
    while (q.size() > 0)
    {
        cur = q.front();
        q.pop();
        ArcNode* p = G.vertices[cur].firstarc;
        while (p != NULL)
        {
            next = p->adjvex;
            if (G.vertices[next].isVisted == false)
            {
                cout << G.vertices[next] << endl;
                G.vertices[next].isVisted = true;
                q.push(next);
            }
            p = p->nextarc;
            
        }

    }

}


void test_04()
{
    ALGraph g;
    CreateUDG(g);// 5, 5 
    OtherInfo oinfo;
    oinfo.arcValue = 0.0;

    InsertArc(g, 'A', 'B', oinfo);
    InsertArc(g, 'A', 'D', oinfo);
    InsertArc(g, 'B', 'E', oinfo);
    InsertArc(g, 'D', 'E', oinfo);
    InsertArc(g, 'E', 'C', oinfo);

    printAdjList(g);  
}

void test_042()
{
    ALGraph g;
    CreateUDG(g);// 5,6
    OtherInfo oinfo;
    oinfo.arcValue = 0.0;

    InsertArc(g, '1', '2', oinfo);
    InsertArc(g, '3', '4', oinfo);
    InsertArc(g, '3', '2', oinfo);
    InsertArc(g, '5', '2', oinfo);
    InsertArc(g, '3', '5', oinfo);
    InsertArc(g, '1', '4', oinfo);
    

    printAdjList(g);
}

void test_43()
{
    ALGraph g;
    CreateUDG(g);// 8,9
    OtherInfo oinfo;
    oinfo.arcValue = 0.0;

    InsertArc(g, '1', '2', oinfo);
    InsertArc(g, '1', '3', oinfo);
    InsertArc(g, '2', '4', oinfo);
    InsertArc(g, '2', '5', oinfo);
    InsertArc(g, '4', '8', oinfo);
    InsertArc(g, '5', '8', oinfo);
    InsertArc(g, '3', '6', oinfo);
    InsertArc(g, '3', '7', oinfo);
    InsertArc(g, '6', '7', oinfo);

    printAdjList(g);
    cout << endl;
    bfs(g, '1');
}