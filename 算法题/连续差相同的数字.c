#include<stdio.h>
void dfs(int current,int N,int K)
{
    if(N==0)
	{	
		printf("%d\t",current);
        return;
    }
    int last=current%10;
    if (last+K<=9)
        dfs(current*10+last+K,N-1,K);
    if (last-K>=0)
        dfs(current*10+last-K,N-1,K);
}
void numsSameConsecDiff(int N,int K)
{
	int i;
    for(i=1;i<10;i++)
        dfs(i,N-1,K);      
}
int main(void)
{
	int N,K;
	scanf("%d %d",&N,&K);
	numsSameConsecDiff(N,K);
 } 
