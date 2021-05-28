#include "Graph.h"


GNode* CreateGraph(int VertexNum)
{
	Vertex V, W;
	GNode* Graph = (GNode*)malloc(sizeof(GNode));
	if (NULL == Graph)
	{
		exit(-1);
	}
	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	for (V = 0; V < Graph->Nv; V++)
	{
		for (W = 0; W < Graph->Nv; W++)
		{
			Graph->G[V][W] = 0;
		}
	}

	return Graph;
}

void InsertEdge(GNode** Graph, ENode* E)
{
	(*Graph)->G[E->V1][E->V2] = E->Weight;
	(*Graph)->G[E->V2][E->V1] = E->Weight;
}

ENode* InitEdge(Vertex v1, Vertex v2, WeightType w)
{
	ENode* NewE = (ENode*)malloc(sizeof(ENode));
	if (NewE == NULL)
	{
		exit(-1);
	}
	NewE->V1 = v1;
	NewE->V2 = v2;
	NewE->Weight = w;

	return NewE;
}

GNode* GraphInsert(GNode* Graph, ENode* E)
{
	/*插入边<V1,V2>*/
	Graph->G[E->V1][E->V2] = E->Weight;

	/*如果是无向图，还要插入边<V2,V1>*/
	Graph->G[E->V2][E->V1] = E->Weight;

	return Graph;
}