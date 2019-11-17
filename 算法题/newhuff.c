#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//   AAAABBBBCCCCCDDDDDDDDEEEEEEFFFFF#
//    
typedef struct
{
	int weight;
	int parent,left,right;
}node,* HuffTree;
void print1(HuffTree tree,int len)
{
	int i=0;
	for(i=1;i<len;i++)
	{
		printf("%d %d %d %d\n",tree[i].weight,tree[i].parent,tree[i].left,tree[i].right);
	}
}
int *statistics(char s[],int * total)
{
	int i;
	int * power=(int *)malloc(sizeof(int)*128);
	for(i=0;i<128;i++)
		power[i]=0; 
	for(i=0;s[i]!='#';i++)
	{
		if(power[s[i]]==0)
			*total+=1;
		power[s[i]]+=1;
	}
	return power;
}
void select(HuffTree tree,int i,int*s1,int *s2)
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
				*s1=(tree[*s1].weight  <=   tree[j].weight)?*s1:j;//��Ȩֵ��С���±��s1 
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
				*s2=(tree[*s2].weight  <=  tree[j].weight)?*s2:j;
					
			}
		}
	}
}
void creat(HuffTree tree,int * power,int total)
{
	int s1,s2,i,j;
	int tablelen=total*2-1;
	node n1={0,0,0,0};
	for(i=1,j=1;i<128;i++)
	{
		if(power[i]!=0)
		{
			tree[j]=n1;
			tree[j].weight=power[i];
			j++;
		}
	}
	for(;j<tablelen+1;j++)
	{
		tree[j]=n1;
	}
	
	for(i=total+1;i<tablelen+1;i++)
	{
		
		select(tree,i-1,&s1,&s2);
		tree[i].weight=tree[s1].weight+tree[s2].weight;
		tree[i].left=s1;tree[i].right=s2;
		tree[s1].parent=i;tree[s2].parent=i;
	}
}
void crehc(HuffTree ht,char * hc[],int total)
{
	char *cd;
	int start,i,c, p;
	cd=(char * )malloc(total*sizeof(char));
	cd[total-1]='\0';
	for(i=1;i<total+1;i++)
	{
		start=total-1;c=i;p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].left==c)
				cd[start]='0';
			else cd[start]='1';
			c=p;p=ht[p].parent;
		}
		hc[i]=(char  * )malloc((total-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}
void print(char* hc[],char mode[],int total)
{
	int i;
	for(i=1;i<total+1;i++)
	{
		printf("%c:%s\n",mode[i],hc[i]);
	}
}
void Encode(char s[],char* hc[],char mode[],int total)
{
	char result[100000]={0};
	int i,j;
	for(i=0;s[i]!='#';i++)
	{
		for(j=1;j<total;j++)
		{
			if(s[i]==mode[j])
				break;
		}	
		strcat(result,hc[j]);
	}
	printf("%s",result);
}
void Decode(char s[],char* hc[],char mode[],int total)
{
	int i=0,j=0,x=0;
	char t[100]={0};
	char result[5000]={0};
	while(s[i])	//����������� 
	{ 
		char temp[2]={0};
		temp[0]=s[i];		 
		strcat(t,temp);		//s[i]�ŵ��Ƚ�����t���� 
		for(j=1;j<total+1;j++)
		{
			if(strcmp(t,hc[j])==0)	//�ҵ�Ψһ���� 
			{	
				printf("%c",mode[j]);
				for(x=0;x<100;x++)
				{
					t[x]=0;	//���t 
				}
			}
		}
		i++;
	}
	printf("%s",result);
}
double aver(char* hc[],int total,int *power,char mode[],char s[])
{
	double sum=0;
	double  len= (double)strlen(s)-1;
	int i;
	for(i=1;i<total+1;i++)
		sum  +=  (  strlen(hc[i])  *  (power[mode[i]])/len);	
	return sum;
}
int main(void)
{
	int * power,total=0,i,j; 
	char string1[200]={0};
	char string2[10000]={0};
	HuffTree tree;
	gets(string1);
	scanf("%s",string2);
	power=statistics(string1,&total);
	char mode [total];
	for(i=1,j=1;i<128;i++)
	{
		if(power[i]!=0)
		{
			mode[j]=i;
			j++;
		}
	}
	tree=(HuffTree)malloc(sizeof(node)*(2*total));
	creat(tree,power,total);
	char * hc[2*total];
	crehc(tree,hc,total);
	Encode(string1,hc,mode,total);
	printf("\n");
	Decode(string2,hc,mode,total);
	printf("\n%.2lf",aver(hc,total,power,mode,string1));
}
