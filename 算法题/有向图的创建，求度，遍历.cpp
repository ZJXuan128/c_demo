#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20//最大顶点个数 

typedef struct{
	int vex[MAXSIZE]; 
	int front;
	int rear;
}SqQueue;

typedef struct
{
	int arcs[MAXSIZE][MAXSIZE];	//弧信息 
	int visited[MAXSIZE];//标记数组，用来判断顶点是否遍历过 
	char vex[MAXSIZE];//存顶点，下标对应字母 
	int vexnum;//顶点数目 
	int arcnum;//边数目 
}AdjMatrix; //邻接矩阵 

void Create(AdjMatrix *G){ 
	int i,j,k,vex1,vex2;
	char Vex1,Vex2;
	scanf("%d %d",&G->vexnum,&G->arcnum);//输入顶点数目边数目 
	
	for(i = 1;i<=G->vexnum;i++){
		for(j = 1;j<=G->vexnum;j++){
			G->arcs[i][j] = 0;
		}
	}//初始化邻接矩阵 
	getchar();
	
	for(i = 1;i<=G->vexnum;i++){
		scanf("%c",&G->vex[i]);
	}//输入所有顶点 
	getchar();
	for(k = 0;k<G->arcnum;k++){
		scanf("%c",&Vex1);
		vex1 = Vex1-64;
		scanf("%c",&Vex2);
		vex2 = Vex2-64;
		getchar();
		G->arcs[vex1][vex2] = 1;//输入有向弧 
	}
}

void initialise(AdjMatrix *G){//初始化访问序列 
	int i; 
	for(i = 1;i<=G->vexnum;i++){
		G->visited[i] = 0;
	} 
}

void DFS(AdjMatrix *G,int Vo){
	int i;
	printf("%c",G->vex[Vo]);//输出本次遍历到的顶点 
	G->visited[Vo] = 1; //遍历过后该顶点在遍历数组中赋1   
	for(i = 1;i<=G->vexnum;i++){
		if(!G->visited[i]&&G->arcs[Vo][i]==1){//如果存在一个顶点顶点未遍历过，且当前顶点到该顶点存在弧，则遍历这个顶点 
			DFS(G,i);//递归调用去遍历下一个顶点，遍历完，返回上次调用，继续执行上次循环 
		} 
	} 
}

int FirstAdj(AdjMatrix *G,int Vo){
	int i;
	for(i = 1;i<=G->vexnum;i++){ 
		if(G->arcs[Vo][i]==1&&G->visited[i]!=1){//如果该顶点到下一个顶点有弧，且没有访问过 
			return i;
		}
	}
	return -1;
}

int NextAdj(AdjMatrix *G,int Vo,int w){
	int i;
	for(i = w+1;i<=G->vexnum;i++){//从w的下一个开始找 
		if(G->arcs[Vo][i]==1&&G->visited[i]!=1){
			return i;
		}
	}
	return -1;
}

void BFS(AdjMatrix *G,int Vo){
	printf("%c",G->vex[Vo]);//访问当前节点 
	G->visited[Vo]= 1;//标记已遍历过 
	SqQueue *Q = (SqQueue *)malloc(sizeof(SqQueue));//建栈 
	Q->front = 0;
	Q->rear = 0;//初始化栈 
	Q->front++;//头指针后移 
	Q->vex[Q->front] =Vo;//先把第一个顶点存到栈中 
	while(Q->front-Q->rear!=0){//栈不空 
		Vo = Q->vex[Q->front];//Vo等于栈顶元素 
		Q->rear++;//尾指针后移 
		int w = FirstAdj(G,Vo);//找当前顶点的第一个邻接点 
		while(w!=-1){//邻接点存在 
			if(!G->visited[w]){//如果当前顶点没访问过 
				printf("%c",G->vex[w]);//访问 
				G->visited[w]=1;//标记 
				Q->front++;//头指针后移 
				Q->vex[Q->front] = w;//当前节点入队 
			}
			w = NextAdj(G,Vo,w);//找当前节点的下一个邻接点 
		}
	}
}

int main(void){
	int i,j;
	AdjMatrix *G = (AdjMatrix *)malloc(sizeof(AdjMatrix));//申请图的存放空间 
	Create(G);//创建有向图 
	int in[MAXSIZE];//入度数组 
	int on[MAXSIZE];//出度数组 
	//求出度
	for(i = 1;i<=G->vexnum;i++){//遍历每一行 
		int count = 0;
		for(j = 1;j<=G->vexnum;j++){ 
			if(G->arcs[i][j]==1){//求出一行中为 1 边个数为该顶点的出度  
				count++;
			}
		}
		on[i] = count;
	}
	//求入度 
	for(i = 1;i<=G->vexnum;i++){
		int count = 0;
		for(j = 1;j<=G->vexnum;j++){
			if(G->arcs[j][i]==1){//求出每一列中为 1 的个数为该顶点的入度 
				count++;
			}
		}
		in[i] = count;
	}
	for(i = 1;i<=G->vexnum;i++){
		printf("%c %d %d %d\n",G->vex[i],on[i],in[i],in[i]+on[i]);//输出每个顶点的出度，入度和度 
	}

	initialise(G);//初始化遍历序列全赋0 
	DFS(G,1);	//深度优先遍历 
	printf("\n");
	initialise(G);//初始化遍历序列全赋0 
	BFS(G,1);//广度优先遍历 
}
