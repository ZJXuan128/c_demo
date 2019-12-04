#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct
{
	int v1 , v2;//顶点 
	int weight;//权重 
}road,*Road;

typedef struct
{
	char vex[MAXSIZE];//存顶点 
	int vexnum;//顶点个数 
	int roadnum;//边的个数 
	road roads[MAXSIZE];//每条边的信息 
}graph , *Graph;

int root[MAXSIZE];//并查集 

int getIndex(Graph G , char v)
{
	int i , t;
	for(i = 0 ; i < G->vexnum ; i++)
	{
		if(G->vex[i] == v)	//把顶点v1存进去 
			return i;
	}
}

void initGraph(Graph G)
{
	int i, j; 
	char v1, v2;
	scanf("%d %d", &G->vexnum, &G->roadnum);//输入顶点和边的个数 
	getchar();
	for (i = 0; i < G->vexnum; i++)//输入各个顶点 
		scanf("%c", &G->vex[i]);
	getchar();
	for (i = 0; i < G->roadnum; i++)//输入每条边信息 
	{
		scanf("(%c,%c,%d)", &v1, &v2, &G->roads[i].weight); 
		G->roads[i].v1 = getIndex(G , v1);//找到每个顶点的下标存进路径数组中 
		G->roads[i].v2 = getIndex(G , v2);
	}
	for (i = 0; i < G->roadnum; i++)//初始化并查集 
		root[i] = i;//每个点的上级是本身 
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
	for(i = 0 ; i < g->roadnum ; i++)//遍历每条边 
	{
		t = 0;
		if(getRoot(g->roads[i].v1) != getRoot(g->roads[i].v2))//如果两个点无法构成回路，（搜索并查集取得的上级值不同）则可以选中 
		{
			root[getRoot(g->roads[i].v2)] = getRoot(g->roads[i].v1);//在并查集中让v2顶点的上级为v1顶点 
			t = 1;
		}
		printf("(%c,%c,%d,%d)" , g->vex[g->roads[i].v1] , g->vex[g->roads[i].v2] , g->roads[i].weight , t);	 
	}
}

int main()
{
	Graph g = (Graph) malloc (sizeof(graph)); 
	initGraph(g);//初始化图 
	order(g);//排序 
	kruskal(g); 
}
