#include <iostream>
#include <string>
#include "commonDefine.h"

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
}VNode, AdjList[MAXNUM];

// �ڽӱ�߽ڵ�
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* nextarc;
    OtherInfo info;
};
//�ڽӱ�ͼ����
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
    cin >> G.vexnum >> G.arcnum;
    //��ʼ��ͷ���
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
}
void InsertArc(ALGraph&G, VertexType v1, VertexType v2, OtherInfo info)
{
    int i = LocateVex(G, v1);//�� i �� j
    int j = LocateVex(G, v2);
    //��Ϊ������ͼ������Ҫ���������߽ڵ�
    ArcNode* p1 = new ArcNode;
    //ͷ�巨
    p1->adjvex = j;
    p1->info = info;
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;

    //�Գƽڵ�
    ArcNode* p2 = new ArcNode;
    p2->adjvex = i;
    p2->info = info;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
}