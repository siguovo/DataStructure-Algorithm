#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"









void test01()
{
	GNode* MG;		//声明一个指向图结构的指针
	int VertexNum = 5;	//声明有多少个顶点
	MG = CreateGraph(VertexNum);//根据顶点的个数创建一个图
	/*一个图有顶点还有边*/
	//创建了有顶点的图，我们现在向图中插入边
	ENode* E1;
	E1 = InitEdge(3, 1, 20);
	/*E1 = (ENode*)malloc(sizeof(ENode));
	if (E1 == NULL)
	{
		exit(-1);
	}
	E1->V1 = 3;
	E1->V2 = 1;
	E1->Weight = 20;*/

	//MG = GraphInsert(MG, E1);
	InsertEdge(&MG, E1);

}

GNode* BuiltGraph()
{
	GNode* Graph;	//建立一个图结点
	ENode* E;		//建立边结点
	//Vertex V;		//顶点里面的数据
	int Nv;			//顶点的个数
	//测试数据 5 1 3 1 20
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	sacnf("%d", &(Graph->Ne));
	if (Graph->Ne != 0)
	{
		E = (ENode*)malloc(sizeof(ENode));
		if (NULL == E)
		{
			exit(-1);
		}
		for (int i = 0; i < Graph->Ne; i++)
		{
			scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
			InsertEdge(&Graph, E);
		}
	}
	///*如果顶点有数据的话，读入数据*/
	//for (V = 0; V < Graph->Nv; V++)
	//{
	//	scanf(" %c", &(Graph->Data[V]));
	//}
	return Graph;
}
void test02()
{
	GNode* MG;
	MG = BuiltGraph();

}


int main()
{
	//test01();
	test02();

	return 0;
}