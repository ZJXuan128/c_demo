#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
							//宏定义&全局变量&函数声明
#define LEN sizeof(struct Student)
int n = 0;
struct Student * creat(void);

struct Student				//定义结构体，包含学号、年龄、性别、姓名、宿舍号;下一节点指针
{
	long num;
	int age;
	char sex;
	char name[10];
	char addr[15];
	struct Student * next;
};
							//学生管理系统-----主函数部分------
int main(void)
{

}
							//------调用函数部分----
									//信息录入链表
struct Student * creat(void)
{
	struct Student * p1, * p2;
	struct Student * head=NULL;
	n = 0;
	p1 = p2 = (struct Student *)malloc(LEN);
	printf("开始录入学生信息：（学号,年龄,性别,姓名,宿舍号）\n");
	scanf("%ld,%d,%c,%s,%s", &p1->num, &p1->age, &p1->sex, &p1->name, &p1->addr);
	while (p1->num != 0)
	{
		n += 1;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Student *)malloc(LEN);
		scanf("ld,%d,%c,%s,%s", &p1->num, &p1->age, &p1->sex, &p1->name, &p1->addr);
		getchar();
	}
	p2->num = NULL;
	return(head);
}


									//查找目标节点
void search(struct Student * head)
{
	int option;
	printf("请选择查找方式：\n");
	printf("1、学号查找\n2、姓名查找\n3、宿舍号查找（输出某个宿舍全部人员信息）\n");
	scanf("%d", &option);
	getchar();
	switch (option)
	{
	case 1:numsearch(head); break;
	case 2:namesearch(head); break;
	case 3:addrsearch(head); break;
	default:printf("请输入正确的指令!\n");
	}
}
void numsearch(struct Student * head)		//学号查找函数
{
	if (head != NULL)
		{
			struct Student* p1;
			long a;
			int i=0;
			printf("请输入要查找的学号：");
			scanf("%ld", &a);
			getchar();
			for (p1=head;p1!=NULL;p1=p1->next)
			{
				if (p1->num == a)
				{
					printf("%ld,%d,%c,%s,%s\n", p1->num, p1->age, p1->sex, p1->name, p1->addr);
					break;
				}
				else
					i++;
			}
			if (i == n)
				printf("未找到该学生信息！");
		}
	else
		printf("还未录入信息！");
}
void namesearch(struct Student * head)				//姓名查找函数
{
	if (head != NULL)
	{
		struct Student* p1;
		char tempname[10];
		int i=0;
		printf("请输入要查找的学生姓名：");
		scanf("%s", tempname);
		getchar();
		for (p1 = head; p1 != NULL; p1 = p1->next)
		{
			if (!strcmp(p1->name,tempname))
			{
				printf("%ld,%d,%c,%s,%s\n", p1->num, p1->age, p1->sex, p1->name, p1->addr);
				break;
			}
			else
				i++;
		}
		if (i == n)
			printf("未找到该学生信息！");
	}
	else
		printf("还未录入信息！");
}
void addrsearch(struct Student * head)				//宿舍查找函数
{
	if (head != NULL)
	{
		struct Student* p1;
		char tempaddr[15];
		int i=0,t=0;
		printf("请输入要查找的学生姓名：");
		scanf("%s", tempaddr);
		getchar();
		for (p1 = head; p1 != NULL; p1 = p1->next)
		{
			if (!strcmp(p1->name, tempaddr))
			{
				printf("%ld,%d,%c,%s,%s\n", p1->num, p1->age, p1->sex, p1->name, p1->addr);
				t += 1;
			}
			else
				i++;
			if (t == 6)
				break;
		}
		if (i == n)
			printf("未找到该宿舍人员信息！");
	}
	else
		printf("还未录入信息！");
}


									//链表排序
void order(struct Student * head)
{

}