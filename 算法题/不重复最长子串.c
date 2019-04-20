#include<stdio.h>
#include<string.h>
int in (char c,char son[])//存在于子串返回1，否则0 
{
	int i,sl=strlen(son);
	if(!sl)//子串空时直接返回0 
		return 0;
	for(i=0;i<sl;i++)
		if(c==son[i])
			return 1;
	return 0;
}
int main(void)
{
	int i=0,j=0,k,result=0;
	char mon[100],son[100]={0};
	scanf("%s",mon);
	int n=strlen(mon);
	while(i<n&&j<n)//设置滑动窗口 
	{
		if(in(mon[j],son))//如果当前字符在字串中则将子串第一个字符（即重复的字符）删去，窗口左边界向右滑动 
		{
			 for(k=0;k<strlen(son);k++)
			 	son[k]=son[k+1];
			 	i++;
		}
		else//不在字串中则将当前字符放入子串中，窗口右边右移 
		{
			son[j-i]=mon[j];
			j++;
			if((j-i)>result)//窗口长度最大值最终储存在result中 
				result=j-i;
		}
	}
	printf("%d",result);
}
