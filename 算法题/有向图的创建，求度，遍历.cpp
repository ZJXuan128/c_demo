#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20//��󶥵���� 

typedef struct{
	int vex[MAXSIZE]; 
	int front;
	int rear;
}SqQueue;

typedef struct
{
	int arcs[MAXSIZE][MAXSIZE];	//����Ϣ 
	int visited[MAXSIZE];//������飬�����ж϶����Ƿ������ 
	char vex[MAXSIZE];//�涥�㣬�±��Ӧ��ĸ 
	int vexnum;//������Ŀ 
	int arcnum;//����Ŀ 
}AdjMatrix; //�ڽӾ��� 

void Create(AdjMatrix *G){ 
	int i,j,k,vex1,vex2;
	char Vex1,Vex2;
	scanf("%d %d",&G->vexnum,&G->arcnum);//���붥����Ŀ����Ŀ 
	
	for(i = 1;i<=G->vexnum;i++){
		for(j = 1;j<=G->vexnum;j++){
			G->arcs[i][j] = 0;
		}
	}//��ʼ���ڽӾ��� 
	getchar();
	
	for(i = 1;i<=G->vexnum;i++){
		scanf("%c",&G->vex[i]);
	}//�������ж��� 
	getchar();
	for(k = 0;k<G->arcnum;k++){
		scanf("%c",&Vex1);
		vex1 = Vex1-64;
		scanf("%c",&Vex2);
		vex2 = Vex2-64;
		getchar();
		G->arcs[vex1][vex2] = 1;//�������� 
	}
}

void initialise(AdjMatrix *G){//��ʼ���������� 
	int i; 
	for(i = 1;i<=G->vexnum;i++){
		G->visited[i] = 0;
	} 
}

void DFS(AdjMatrix *G,int Vo){
	int i;
	printf("%c",G->vex[Vo]);//������α������Ķ��� 
	G->visited[Vo] = 1; //��������ö����ڱ��������и�1   
	for(i = 1;i<=G->vexnum;i++){
		if(!G->visited[i]&&G->arcs[Vo][i]==1){//�������һ�����㶥��δ���������ҵ�ǰ���㵽�ö�����ڻ��������������� 
			DFS(G,i);//�ݹ����ȥ������һ�����㣬�����꣬�����ϴε��ã�����ִ���ϴ�ѭ�� 
		} 
	} 
}

int FirstAdj(AdjMatrix *G,int Vo){
	int i;
	for(i = 1;i<=G->vexnum;i++){ 
		if(G->arcs[Vo][i]==1&&G->visited[i]!=1){//����ö��㵽��һ�������л�����û�з��ʹ� 
			return i;
		}
	}
	return -1;
}

int NextAdj(AdjMatrix *G,int Vo,int w){
	int i;
	for(i = w+1;i<=G->vexnum;i++){//��w����һ����ʼ�� 
		if(G->arcs[Vo][i]==1&&G->visited[i]!=1){
			return i;
		}
	}
	return -1;
}

void BFS(AdjMatrix *G,int Vo){
	printf("%c",G->vex[Vo]);//���ʵ�ǰ�ڵ� 
	G->visited[Vo]= 1;//����ѱ����� 
	SqQueue *Q = (SqQueue *)malloc(sizeof(SqQueue));//��ջ 
	Q->front = 0;
	Q->rear = 0;//��ʼ��ջ 
	Q->front++;//ͷָ����� 
	Q->vex[Q->front] =Vo;//�Ȱѵ�һ������浽ջ�� 
	while(Q->front-Q->rear!=0){//ջ���� 
		Vo = Q->vex[Q->front];//Vo����ջ��Ԫ�� 
		Q->rear++;//βָ����� 
		int w = FirstAdj(G,Vo);//�ҵ�ǰ����ĵ�һ���ڽӵ� 
		while(w!=-1){//�ڽӵ���� 
			if(!G->visited[w]){//�����ǰ����û���ʹ� 
				printf("%c",G->vex[w]);//���� 
				G->visited[w]=1;//��� 
				Q->front++;//ͷָ����� 
				Q->vex[Q->front] = w;//��ǰ�ڵ���� 
			}
			w = NextAdj(G,Vo,w);//�ҵ�ǰ�ڵ����һ���ڽӵ� 
		}
	}
}

int main(void){
	int i,j;
	AdjMatrix *G = (AdjMatrix *)malloc(sizeof(AdjMatrix));//����ͼ�Ĵ�ſռ� 
	Create(G);//��������ͼ 
	int in[MAXSIZE];//������� 
	int on[MAXSIZE];//�������� 
	//�����
	for(i = 1;i<=G->vexnum;i++){//����ÿһ�� 
		int count = 0;
		for(j = 1;j<=G->vexnum;j++){ 
			if(G->arcs[i][j]==1){//���һ����Ϊ 1 �߸���Ϊ�ö���ĳ���  
				count++;
			}
		}
		on[i] = count;
	}
	//����� 
	for(i = 1;i<=G->vexnum;i++){
		int count = 0;
		for(j = 1;j<=G->vexnum;j++){
			if(G->arcs[j][i]==1){//���ÿһ����Ϊ 1 �ĸ���Ϊ�ö������� 
				count++;
			}
		}
		in[i] = count;
	}
	for(i = 1;i<=G->vexnum;i++){
		printf("%c %d %d %d\n",G->vex[i],on[i],in[i],in[i]+on[i]);//���ÿ������ĳ��ȣ���ȺͶ� 
	}

	initialise(G);//��ʼ����������ȫ��0 
	DFS(G,1);	//������ȱ��� 
	printf("\n");
	initialise(G);//��ʼ����������ȫ��0 
	BFS(G,1);//������ȱ��� 
}
