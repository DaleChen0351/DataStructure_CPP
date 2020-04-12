#include <iostream>
#include <string>
#include "commonDefine.h"
using namespace std;



typedef struct
{
    VertexType vexs[MAXNUM];// 顶点表
    ArcType arcs[MAXNUM][MAXNUM];// 邻接矩阵
    // 图的当前点数和边数
    int vexnum;
    int arcnum;
}AMGraph;// Adjacency Matrix Graph



int LoacatVex(AMGraph G, VertexType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (v == G.vexs[i])//?
        {
            return i;
        }
    }
    return -1;
}
Status CreateUDN(AMGraph &G)
{
    cout << "请输入顶点总数和边数:" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入所有的顶点：" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vexs[i];
    }

    //Init 
    for (int i = 0; i < G.arcnum; i++)
    {
        for (int j = 0; j < G.arcnum; j++)
        {
            G.arcs[i][j] = MAXINT;// 边的权值均置为最大值
        }
    }
    // 输入边和权值
    cout << "请输入边和权值：" << endl;
    for (int k = 0; k < G.arcnum; k++)
    {
        
    }
    return true;
}
