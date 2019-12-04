#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct
{
	int v1 , v2;//���� 
	int weight;//Ȩ�� 
}road,*Road;

typedef struct
{
	char vex[MAXSIZE];//�涥�� 
	int vexnum;//������� 
	int roadnum;//�ߵĸ��� 
	road roads[MAXSIZE];//ÿ���ߵ���Ϣ 
}graph , *Graph;

int root[MAXSIZE];//���鼯 

int getIndex(Graph G , char v)
{
	int i , t;
	for(i = 0 ; i < G->vexnum ; i++)
	{
		if(G->vex[i] == v)	//�Ѷ���v1���ȥ 
			return i;
	}
}

void initGraph(Graph G)
{
	int i, j; 
	char v1, v2;
	scanf("%d %d", &G->vexnum, &G->roadnum);//���붥��ͱߵĸ��� 
	getchar();
	for (i = 0; i < G->vexnum; i++)//����������� 
		scanf("%c", &G->vex[i]);
	getchar();
	for (i = 0; i < G->roadnum; i++)//����ÿ������Ϣ 
	{
		scanf("(%c,%c,%d)", &v1, &v2, &G->roads[i].weight); 
		G->roads[i].v1 = getIndex(G , v1);//�ҵ�ÿ��������±���·�������� 
		G->roads[i].v2 = getIndex(G , v2);
	}
	for (i = 0; i < G->roadnum; i++)//��ʼ�����鼯 
		root[i] = i;//ÿ������ϼ��Ǳ��� 
} 

void order(Graph g) 
{
	int i , j;
	int n = g->roadnum;
	for(i = 0 ; i < n ; i++)
	{
		for(j = i + 1 ; j < n ; j++)
		{
			if(g->roads[i].weight > g->roads[j].weight)
			{
				road t = g->roads[i];
				g->roads[i] = g->roads[j];
				g->roads[j] = t;
			}
		}
	}
}

int getRoot(int x)
{
	while(root[x] != x)
		x = root[x];
	return x;
}

void kruskal(Graph g)
{
	int i , t;
	for(i = 0 ; i < g->roadnum ; i++)//����ÿ���� 
	{
		t = 0;
		if(getRoot(g->roads[i].v1) != getRoot(g->roads[i].v2))//����������޷����ɻ�·�����������鼯ȡ�õ��ϼ�ֵ��ͬ�������ѡ�� 
		{
			root[getRoot(g->roads[i].v2)] = getRoot(g->roads[i].v1);//�ڲ��鼯����v2������ϼ�Ϊv1���� 
			t = 1;
		}
		printf("(%c,%c,%d,%d)" , g->vex[g->roads[i].v1] , g->vex[g->roads[i].v2] , g->roads[i].weight , t);	 
	}
}

int main()
{
	Graph g = (Graph) malloc (sizeof(graph)); 
	initGraph(g);//��ʼ��ͼ 
	order(g);//���� 
	kruskal(g); 
}
