#include <iostream>
#include <string>
#include "commonDefine.h"

using namespace std;


//前置申明
struct ArcNode;
struct OtherInfo
{
    float arcValue;
};
// 邻接表顶点
typedef struct VNode
{
    VertexType data;
    ArcNode* firstarc;// next point
}VNode, AdjList[MAXNUM];

// 邻接表边节点
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* nextarc;
    OtherInfo info;
};
//邻接表图定义
typedef struct
{
    AdjList vertices;// 如果前面定义成了数组，这里可以直接实例化，不需要加数组长度
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
    //初始化头结点
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
}
void InsertArc(ALGraph&G, VertexType v1, VertexType v2, OtherInfo info)
{
    int i = LocateVex(G, v1);//从 i 到 j
    int j = LocateVex(G, v2);
    //因为是无向图，所以要生成两个边节点
    ArcNode* p1 = new ArcNode;
    //头插法
    p1->adjvex = j;
    p1->info = info;
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;

    //对称节点
    ArcNode* p2 = new ArcNode;
    p2->adjvex = i;
    p2->info = info;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
}