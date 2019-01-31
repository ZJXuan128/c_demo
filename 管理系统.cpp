#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
							//宏定义&全局变量&函数声明
#define LEN sizeof(struct Movie)
int n = 0;
char ran_con[10];
struct Movie * creat(void);

struct Movie				//定义影片结构体，包含编号、年代、导演名、主演名、热度、产国、类型、画质;下一节点指针
{
	long num;
	int age;
	char dir_nam[10];
	char lead_actor_name[10];
	int hot;
	char country[5];
	char type[5];
	char quality[5];
	struct Movie * next;
};

							//影院管理系统-----主函数部分------
int main(void)
{

}

							//------调用函数部分----
								//信息录入链表
struct Movie * creat(void)
{
	struct Movie * p1, * p2;
	struct Movie * head=NULL;
	n = 0;
	p1 = p2 = (struct Movie *)malloc(LEN);
	printf("开始录入影片信息：（编号，年代，导演名，主演名，类型，热度，产国，画质）\n");
	scanf("%ld,%d,%s,%s,%d,%s,%s,%s", &p1->num, &p1->age, &p1->dir_nam, &p1->lead_actor_name, &p1->type,&p1->hot,&p1->country,p1->quality);
	while (p1->num != 0)
	{
		n += 1;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct Movie *)malloc(LEN);
		scanf("%ld,%d,%s,%s,%d,%s,%s,%s", &p1->num, &p1->age, &p1->dir_nam, &p1->lead_actor_name, &p1->type, &p1->hot, &p1->country, &p1->quality);
		getchar();
	}
	p2->num = NULL;
	return(head);
}


									//查找目标节点
void search(struct Movie * head)
{
	int option;
	struct Movie * tep_head;
	int End = 0;
	char already_choice[4][20] = {"姓名：未选择","年代：未选择","类型：未选择","产国：未选择"};
	char tep_choice[10];
	int i = 0;
	printf("请选择查找方式：\n");
	printf("1、编号查找\n2、范围查询\n");
	scanf("%d", &option);
	getchar();
	if (option == 1)
		numsearch(head);
	else
	{
		tep_head = head;
		printf("选择范围：\n1、导演/主演名查找\n2、年代查找\n3、类型查找\n4、产国查找");
		scanf("%d", &option);
		getchar();
		while (End != 1)
		{
			switch (option)
			{
			case 1:
				tep_head = namesearch(tep_head);
				strcpy(already_choice[i], "姓名：");
				strcat(already_choice[i], ran_con);
				i += 1;
				break;
			case 2:
				tep_head = agersearch(tep_head); 
				already_choice[i];
				i += 1;
				break;
			case 3:
				tep_head = typesearch(tep_head);
				already_choice[i];
				i += 1;
				break;
			case 4:
				tep_head = countrysearch(tep_head);
				already_choice[i];
				i += 1;
				break;
			default:
				printf("请输入正确的指令!\n\t再次选择\n");
			}
			printf("%s", already_choice);
			printf("是否继续缩小范围？(0——继续||1——退出)");
			scanf("%d", &End);
			if (End == 0)
			{
				printf("选择范围：\n1、导演/主演名查找\n2、年代查找\n3、产国查找");
				scanf("%d", &option);
			}
		}
	}
}
struct Movie * numsearch(struct Movie * head)		//编号查找函数
{
	if (head != NULL)
		{
			struct Movie* p1;
			long a;
			int i=0;
			printf("请输入要查找的编号：");
			scanf("%ld", &a);
			getchar();
			for (p1=head;p1!=NULL;p1=p1->next)
			{
				if (p1->num == a)
				{
					printf("%ld,%d,%s,%s,%d,%s,%s,%s", p1->num, p1->age, p1->dir_nam, p1->lead_actor_name, p1->type, p1->hot, p1->country, p1->quality);
					break;
				}
				else
					i++;
			}
			if (i == n)
				printf("未找到该影片信息！");
		}
	else
		printf("还未录入信息！");
}
struct Movie * namesearch(struct Movie * head)				//姓名查找函数
{
	if (head != NULL)
	{
		struct Movie* p1;
		char tep_name[10];
		int i=0;
		printf("请输入要查找的导演/主演姓名：");
		scanf("%s", tep_name);
		getchar();
		for (p1 = head; p1 != NULL; p1 = p1->next)
		{
			if (!strcmp(p1->name,tep_name))
			{
				printf("%ld,%d,%s,%s,%d,%s,%s,%s", p1->num, p1->age, p1->dir_nam, p1->lead_actor_name, p1->type, p1->hot, p1->country, p1->quality);
				
			}
			else
				i++;
		}
		if (i == n)
			printf("未找到该影片信息！");
	}
	else
		printf("还未录入信息！");
}
struct Movie * agersearch(struct Movie * head)				//宿舍查找函数
{
	if (head != NULL)
	{
		struct Movie* p1;
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
			printf("未找到该年代影片信息！");
	}
	else
		printf("还未录入该年代信息！");
}
struct Movie * typesearch(struct Movie * head)
{

}
struct Movie * countrysearch(struct Movie * head)
{

}



									//链表排序

									
void order(struct Movie * head)
{

}


									//登陆模块
int i = 0;//当前账号标记
int flag1 = 0;//登录成功标记
struct user
{
	char user_Name[6];
	char user_Pass[7];
}stu[3] = { {"A0001","111111"},{"A0002","222222"},{"admin","333333"} };//初始化用户名和对应密码,后期改为文件储存
void login()
{
	void print_Passwd(void);
	void xiugai_Passwd(void);
	while (1)
	{
		print_Passwd();
	}
}
void print_Passwd(void)
{
	int flag = 0;//密码正确标记
	char p[5];//临时用户名
	char s[6];//临时密码
	char num = 0;//密码次数
	char temp;//登录后改密码
	printf("请输入登录名:\n");
	scanf("%s", p);
	for (i = 0; i < 3; i++)
	{
		if (strcmp(stu[i].user_Name, p) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (1 == flag)
	{
		printf("请输入密码:\n");
		scanf("%s", s);
	}
	else
	{
		printf("没有此用户:\n");
		exit(0);
	}

	while (strcmp(stu[i].user_Pass, s) != 0)
	{
		num++;
		if (3 == num)
		{
			printf("密码输入错误超过3次,系统自动退出!\n");
			exit(0);
		}
		printf("密码错误!\n");
		printf("请重新输入密码:\n");
		scanf("%s", s);
	}
	printf("登录成功!\n");
	flag1 = 1;
	if (flag1 == 1)
	{
		if (strcmp("admin", p) == 0)
		{
			printf("注:你是VIP超级用户!\n");
		}
		else
			printf("注:你是普通用户\n");
		printf("请按1修改密码,其他键进入管理出系统:\n");
		scanf("%d", &temp);
		if (1 == temp)
		{
			xiugai_Passwd();
		}
	}
}
void xiugai_Passwd(void)//修改密码
{
	char p[10];//新密码
	printf("请输入新密码:\n");
	scanf("%s", p);
	strcpy(stu[i].user_Pass, p);
	printf("修改密码成功:\n");
	printf("请重新登录:\n");
}