#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 10
typedef int WeightType;		//图的类型
typedef int DataType;		//顶点数据类型
typedef int Vertex;			//顶点类型


/*图结构的类型声明*/
typedef struct GNode
{
	int Nv;		/* 顶点数 */
	int Ne;		/* 边数 */
	WeightType G[MaxVertexNum][MaxVertexNum];
	//DataType Data[MaxVertexNum];	/* 存放顶点的数据 */
}GNode;

/*边的结构声明*/
typedef struct ENode
{
	Vertex V1, V2;	//每条边是由两个顶点构成
	WeightType Weight;	//有的边会有权重
}ENode;

//根据给定的顶点个数创建一个图
GNode* CreateGraph(int VertexNum);
//创建一条边
ENode* InitEdge(Vertex v1, Vertex v2, WeightType w);
//将边插入图中
GNode* GraphInsert(GNode* Graph, ENode* E);


//输入式创建图
GNode* BuiltGraph();
//将边插入图中
void InsertEdge(GNode** Graph, ENode* E);
