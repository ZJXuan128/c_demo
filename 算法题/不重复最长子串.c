#include<stdio.h>
#include<string.h>
int in (char c,char son[])//�������Ӵ�����1������0 
{
	int i,sl=strlen(son);
	if(!sl)//�Ӵ���ʱֱ�ӷ���0 
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
	while(i<n&&j<n)//���û������� 
	{
		if(in(mon[j],son))//�����ǰ�ַ����ִ������Ӵ���һ���ַ������ظ����ַ���ɾȥ��������߽����һ��� 
		{
			 for(k=0;k<strlen(son);k++)
			 	son[k]=son[k+1];
			 	i++;
		}
		else//�����ִ����򽫵�ǰ�ַ������Ӵ��У������ұ����� 
		{
			son[j-i]=mon[j];
			j++;
			if((j-i)>result)//���ڳ������ֵ���մ�����result�� 
				result=j-i;
		}
	}
	printf("%d",result);
}
