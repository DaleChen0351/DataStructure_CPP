#include <iostream>
#include <string>
#include "commonDefine.h"
using namespace std;



typedef struct
{
    VertexType vexs[MAXNUM];// �����
    ArcType arcs[MAXNUM][MAXNUM];// �ڽӾ���
    // ͼ�ĵ�ǰ�����ͱ���
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
    cout << "�����붥�������ͱ���:" << endl;
    cin >> G.vexnum >> G.arcnum;
    cout << "���������еĶ��㣺" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        cin >> G.vexs[i];
    }

    //Init 
    for (int i = 0; i < G.arcnum; i++)
    {
        for (int j = 0; j < G.arcnum; j++)
        {
            G.arcs[i][j] = MAXINT;// �ߵ�Ȩֵ����Ϊ���ֵ
        }
    }
    // ����ߺ�Ȩֵ
    cout << "������ߺ�Ȩֵ��" << endl;
    for (int k = 0; k < G.arcnum; k++)
    {
        
    }
    return true;
}
