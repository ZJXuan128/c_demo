#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct node)
struct node
{
	int num;
	struct node * next;
};
struct node * creat(void)//创建链表 
{
	int m,i;
	struct node * head=NULL,* p1;
	printf("输入要创建的节点个数(节点索引从零开始)：");
	scanf("%d",&m);
	for(i=0;i<m;i++)//直接初始化每个节点 
	{
		if(!i)//头节点初始化 
		{
			head=(struct node *)malloc(len);
			head->num=i;
			p1=head;
			if(m==1);//只有一个头节点
			head->next=NULL; 
		}
		else
		{
			p1->next=(struct node *)malloc(len);
			p1->next->num=i;
			if(i==m-1)//尾节点归零 
				p1->next->next=NULL;
			else
				p1=p1->next;
		}
	}
	return head;
}
void print(struct node * head)//输出链表 
{
	struct node * p1=head;
	while(p1!=NULL)
	{
		printf("%d\n",p1->num);
		p1=p1->next;
	}
}
void del(struct node * head)//删除节点 快慢指针 
{
	struct node * fast=head,* slow;//先初始化快指针 
	int n,i=0;
	printf("输入要删除的节点的倒数索引：");
	scanf("%d",&n); 
	while(1)//保证有效输入时，在链表循环遍历时，找到删除后跳出即可 
	{
		if(i==n)//当快指针领先n-1个时，初始化慢指针 
			slow=head;
		fast=fast->next;
		i++; 
		if(fast==NULL)//当快指针知道尾节点时，慢指针指向第n-1个节点 
		{
			slow->next=slow->next->next;//删除第n个节点 
			break;
		}
		slow=slow->next;
	}
}
int main(void)
{
	struct node * head;
	head=creat();
	printf("删除前：\n");
	print(head); 
	del(head);
	printf("删除后：\n");
	print(head);
}
