#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int weight;
	int parent,left,right;
}node,HuffTree[12];
typedef char* Huffmancode[7];
int m;
void select(HuffTree tree,int i,int* s1,int* s2)
{
	int j,flag=1;//flag�ж��Ƿ񸳳�ֵ 
	for(j=1;j<i+1;j++)	//����Сֵ 
	{
		if(tree[j].parent==0)//û��˫�ײŽ����ж� 
		{
			if(flag)	//δ����ֵ 
			{
				*s1=j;	//����ֵ 
				flag=0;	//�޸ı�־λ 
			}
			else	//�Ѿ�����ֵ 
			{
				*s1=(tree[*s1].weight  <   tree[j].weight)?*s1:j;//��Ȩֵ��С���±��s1 
			}
		}
	}
	flag=1;	//�޸ı�־λ 
	for(j=1;j<i+1;j++)
	{
		if(tree[j].parent==0 && j!=*s1)//û��˫�ף��Ҳ�����s1 
		{
			if(flag)
			{
				*s2=j;
				flag=0;
			}
			else
			{
				*s2=(tree[*s2].weight  <  tree[j].weight)?*s2:j;
			}
		}
	}
}
void creat(HuffTree tree,int power[],int max)
{
	int s1,s2;
	m=2*max-1;
	int i;
	node n1={0,0,0,0};
	for(i=1;i<max+1;i++)
	{
		tree[i]=n1;
		tree[i].weight=power[i];
	}
	for(i=max+1;i<m+1;i++)
	{
		tree[i]=n1;
	}
	for(i=max+1;i<m+1;i++)
	{
		select(tree,i-1,&s1,&s2);
		tree[i].weight=tree[s1].weight+tree[s2].weight;
		tree[i].left=s1;tree[i].right=s2;
		tree[s1].parent=i;tree[s2].parent=i;
	}
}
void crehc(HuffTree ht,Huffmancode hc,int n)
{
	char *cd;
	int start,i,c,p;
	cd=(char * )malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<n+1;i++)
	{
		start=n-1;c=i;p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].left==c)
				cd[start]='0';
			else cd[start]='1';
			c=p;p=ht[p].parent;
		}
		hc[i]=(char  * )malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}
void print(Huffmancode hc)
{
	int i;
	char s[6]={'A','B','C','D','E','F'};
	for(i=1;i<7;i++)
	{
		printf("%c:%s\n",s[i-1],hc[i]);
	}
}
void Encode(char s[],Huffmancode hc)
{
	char result[600]={0};
	int i;
	for(i=0;s[i];i++)
	{
		strcat(result,hc[s[i]%32]);
	}
	printf("%s",result);
}
void Decode(char s[],Huffmancode hc)
{
	int i=0,j=0,x=0;
	char t[5]={0},mode[7]={0,'A','B','C','D','E','F'};
	char result[50]={0};
	while(s[i])	//����������� 
	{ 
		char temp[2]={0};
		temp[0]=s[i];		 
		strcat(t,temp);		//s[i]�ŵ��Ƚ�����t���� 
		for(j=1;j<7;j++)
		{
			if(strcmp(t,hc[j])==0)	//�ҵ�Ψһ���� 
			{	
				printf("%c",mode[j]);
				for(x=0;x<5;x++)
				{
					t[x]=0;	//���t 
				}
			} 
		}
			i++;
	}
	printf("%s",result);
}
int main(void)
{
	int power[7],i;
	char string1[100]={0};
	char string2[100]={0};
	HuffTree tree;
	Huffmancode hc;
	for(i=1;i<7;i++)
		scanf("%d",&power[i]);
	scanf("%s",string1);
	scanf("%s",string2);
	creat(tree,power,6);
	crehc(tree,hc,6);
	print(hc);
	Encode(string1,hc);
	printf("\n"); 
	Decode(string2,hc);
}
