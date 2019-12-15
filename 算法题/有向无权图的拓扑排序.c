#include<stdio.h>
#include<stdlib.h>
/*
 已知有向无权图G，求出其拓扑有序序列。

要求：用邻接矩阵存储图，用栈存储度为0的结点。

输入
第一行输入两个正整数n和m（空格间隔）， 分别表示图G的顶点总数和弧的总数。
第二行连续输入n个字母，分别表示n个顶点的信息。
第三行连续输入m条弧的信息，每条弧的输入格式为<v1,v2>，表示一条从顶点v1到v2的弧。

输出
依拓扑序列输出各个顶点（各顶点间无间隔符号）。


样例输入
8 10
ABCDEFGH
<A,C><A,G><B,G><B,H><C,D><G,D><G,F><H,F><D,E><F,E>


样例输出
BHAGFCDE


8 10
12345678
<1,3><1,7><2,7><2,8><3,4><7,4><7,6><,8,6><4,5><6,5>

*/
#define MAXVEX 128 
typedef struct 
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX+1];//输入顶点集的时候按字符串输入，会存在结束符导致字符数组定义时长度需要加一 
	int vexnum;
	int arcnum; 
	
	int map[MAXVEX+1];//使用map方便根据字母找到其在顶点集中的位置
	int indegree[MAXVEX];//记录每个结点的入度 
} AdjMatrix;
typedef struct
{
	char vex[MAXVEX];
	int top;
} stack;

void init (stack* s)
{
	s->top=-1;
}
void push(stack* s,char c)
{
	s->top++;
	s->vex[s->top]=c;
}
void pop(stack*s ,char *c)
{
	*c=s->vex[s->top];
	s->top--;
}
void intostack(AdjMatrix *G,stack*s,int (*record)[])//将所有入度为零的入栈 
{
	int i=0;
	for(i=0;i<G->vexnum;i++)
		if(G->indegree[i]==0 && (*record)[i]==0)  //当前的顶点入度为空且之前没有入过栈，则入栈并修改入栈记录
		{
			push(s,G->vex[i]);
			(*record)[i]=1; 
		}
}
/*
拓扑排序具体实现时，采用邻接矩阵作为存储结构，将寻找没有前驱的结点变为寻找
入度为零的点，每找到一个就入栈一个，直到当前情况下所有的0度结点都入栈，然后出栈
每出栈一个结点，就将以它为头的结点入度减一。
*/ 
int TopoSort(AdjMatrix G)
{
	stack s;
	int i,k=0,j;
	int record[G.vexnum];//需要考虑防止重复入栈，设置一个记录是否入过栈的数组，没有入过栈则置为0
	for(i=0;i<G.vexnum;i++)  record[i]=0;	
	char cur;
	init(&s);
	
//当入度为零的结点全部入栈后，出栈一个元素，输出，将以他为头的结点入度减一，再将此时所有入度为零的结点入队重复至栈空 
	do
	{
		k++;
		intostack(&G,&s,&record);
		pop(&s,&cur);
		printf("%c",cur);
		i=G.map[cur%32];
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j]!=0)
			{
				G.indegree[j]--;
			}
		}
	}while(k!=G.vexnum);
}

void creat(AdjMatrix* G)
{
	scanf("%d %d",&(G->vexnum),&(G->arcnum));//获取总的顶点数和边数
	 
	int i=0,j,len,degree;
	char a,b;
	
	scanf("%s",G->vex);
	while(G->vex[i++])
	{
		len++;
		G->map[G->vex[i-1]%32]=i-1;//循环判断结束后i自增了，以适用于下一次判断，故在当前循环内需要使用的应该是i-1 
	}
	
	for(i=0;i<G->vexnum;i++)//初始化邻接矩阵为全零数组，当有弧存在改值为一 
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=0;
	getchar();
	for(i=0;i<G->arcnum;i++)//改值 
	{
		scanf("<%c,%c>",&a,&b);
		G->arcs[G->map[a%32]][G->map[b%32]]=1; //第a行第b列的值置为1 
	}
	//因为将indegree设置在定义的数据结构中， 故在初始化时一并创建，拓扑排序时因为传入的形参是实参的复制，可以直接在形参的成员中修改，不影响原矩阵 
	//可以先将indegree复制一份，避免对原数据结构中存在的值进行改动。 
	for(i=0;i<G->vexnum;i++)
	{
		degree=0;
		for(j=0;j<G->vexnum;j++)//i为某一列，遍历当前列的所有行，统计入度 
		{
			if(G->arcs[j][i]) degree++;//构建邻接矩阵时，列存储的是每列对应顶点的入度，需要遍历该列的每一行 
		}
		G->indegree[i]=degree;
	}
}



int main(void)
{
	AdjMatrix G;
	creat(& G);
	TopoSort(G);
}
