#include<stdio.h>
#include<stdlib.h>
/*
 ��֪������ȨͼG������������������С�

Ҫ�����ڽӾ���洢ͼ����ջ�洢��Ϊ0�Ľ�㡣

����
��һ����������������n��m���ո������� �ֱ��ʾͼG�Ķ��������ͻ���������
�ڶ�����������n����ĸ���ֱ��ʾn���������Ϣ��
��������������m��������Ϣ��ÿ�����������ʽΪ<v1,v2>����ʾһ���Ӷ���v1��v2�Ļ���

���
��������������������㣨��������޼�����ţ���


��������
8 10
ABCDEFGH
<A,C><A,G><B,G><B,H><C,D><G,D><G,F><H,F><D,E><F,E>


�������
BHAGFCDE


8 10
12345678
<1,3><1,7><2,7><2,8><3,4><7,4><7,6><,8,6><4,5><6,5>

*/
#define MAXVEX 128 
typedef struct 
{
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX+1];//���붥�㼯��ʱ���ַ������룬����ڽ����������ַ����鶨��ʱ������Ҫ��һ 
	int vexnum;
	int arcnum; 
	
	int map[MAXVEX+1];//ʹ��map���������ĸ�ҵ����ڶ��㼯�е�λ��
	int indegree[MAXVEX];//��¼ÿ��������� 
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
void intostack(AdjMatrix *G,stack*s,int (*record)[])//���������Ϊ�����ջ 
{
	int i=0;
	for(i=0;i<G->vexnum;i++)
		if(G->indegree[i]==0 && (*record)[i]==0)  //��ǰ�Ķ������Ϊ����֮ǰû�����ջ������ջ���޸���ջ��¼
		{
			push(s,G->vex[i]);
			(*record)[i]=1; 
		}
}
/*
�����������ʵ��ʱ�������ڽӾ�����Ϊ�洢�ṹ����Ѱ��û��ǰ���Ľ���ΪѰ��
���Ϊ��ĵ㣬ÿ�ҵ�һ������ջһ����ֱ����ǰ��������е�0�Ƚ�㶼��ջ��Ȼ���ջ
ÿ��ջһ����㣬�ͽ�����Ϊͷ�Ľ����ȼ�һ��
*/ 
int TopoSort(AdjMatrix G)
{
	stack s;
	int i,k=0,j;
	int record[G.vexnum];//��Ҫ���Ƿ�ֹ�ظ���ջ������һ����¼�Ƿ����ջ�����飬û�����ջ����Ϊ0
	for(i=0;i<G.vexnum;i++)  record[i]=0;	
	char cur;
	init(&s);
	
//�����Ϊ��Ľ��ȫ����ջ�󣬳�ջһ��Ԫ�أ������������Ϊͷ�Ľ����ȼ�һ���ٽ���ʱ�������Ϊ��Ľ������ظ���ջ�� 
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
	scanf("%d %d",&(G->vexnum),&(G->arcnum));//��ȡ�ܵĶ������ͱ���
	 
	int i=0,j,len,degree;
	char a,b;
	
	scanf("%s",G->vex);
	while(G->vex[i++])
	{
		len++;
		G->map[G->vex[i-1]%32]=i-1;//ѭ���жϽ�����i�����ˣ�����������һ���жϣ����ڵ�ǰѭ������Ҫʹ�õ�Ӧ����i-1 
	}
	
	for(i=0;i<G->vexnum;i++)//��ʼ���ڽӾ���Ϊȫ�����飬���л����ڸ�ֵΪһ 
		for(j=0;j<G->vexnum;j++)
			G->arcs[i][j]=0;
	getchar();
	for(i=0;i<G->arcnum;i++)//��ֵ 
	{
		scanf("<%c,%c>",&a,&b);
		G->arcs[G->map[a%32]][G->map[b%32]]=1; //��a�е�b�е�ֵ��Ϊ1 
	}
	//��Ϊ��indegree�����ڶ�������ݽṹ�У� ���ڳ�ʼ��ʱһ����������������ʱ��Ϊ������β���ʵ�εĸ��ƣ�����ֱ�����βεĳ�Ա���޸ģ���Ӱ��ԭ���� 
	//�����Ƚ�indegree����һ�ݣ������ԭ���ݽṹ�д��ڵ�ֵ���иĶ��� 
	for(i=0;i<G->vexnum;i++)
	{
		degree=0;
		for(j=0;j<G->vexnum;j++)//iΪĳһ�У�������ǰ�е������У�ͳ����� 
		{
			if(G->arcs[j][i]) degree++;//�����ڽӾ���ʱ���д洢����ÿ�ж�Ӧ�������ȣ���Ҫ�������е�ÿһ�� 
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
