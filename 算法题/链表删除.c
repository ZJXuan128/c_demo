#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct node)
struct node
{
	int num;
	struct node * next;
};
struct node * creat(void)//�������� 
{
	int m,i;
	struct node * head=NULL,* p1;
	printf("����Ҫ�����Ľڵ����(�ڵ��������㿪ʼ)��");
	scanf("%d",&m);
	for(i=0;i<m;i++)//ֱ�ӳ�ʼ��ÿ���ڵ� 
	{
		if(!i)//ͷ�ڵ��ʼ�� 
		{
			head=(struct node *)malloc(len);
			head->num=i;
			p1=head;
			if(m==1);//ֻ��һ��ͷ�ڵ�
			head->next=NULL; 
		}
		else
		{
			p1->next=(struct node *)malloc(len);
			p1->next->num=i;
			if(i==m-1)//β�ڵ���� 
				p1->next->next=NULL;
			else
				p1=p1->next;
		}
	}
	return head;
}
void print(struct node * head)//������� 
{
	struct node * p1=head;
	while(p1!=NULL)
	{
		printf("%d\n",p1->num);
		p1=p1->next;
	}
}
void del(struct node * head)//ɾ���ڵ� ����ָ�� 
{
	struct node * fast=head,* slow;//�ȳ�ʼ����ָ�� 
	int n,i=0;
	printf("����Ҫɾ���Ľڵ�ĵ���������");
	scanf("%d",&n); 
	while(1)//��֤��Ч����ʱ��������ѭ������ʱ���ҵ�ɾ������������ 
	{
		if(i==n)//����ָ������n-1��ʱ����ʼ����ָ�� 
			slow=head;
		fast=fast->next;
		i++; 
		if(fast==NULL)//����ָ��֪��β�ڵ�ʱ����ָ��ָ���n-1���ڵ� 
		{
			slow->next=slow->next->next;//ɾ����n���ڵ� 
			break;
		}
		slow=slow->next;
	}
}
int main(void)
{
	struct node * head;
	head=creat();
	printf("ɾ��ǰ��\n");
	print(head); 
	del(head);
	printf("ɾ����\n");
	print(head);
}
