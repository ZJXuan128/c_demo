#include <stdio.h>
#include <string.h>
int nums[30];
int length;
int count=0;

int len(int n)
{
	int count=0;
    while(n)
	{
        n/=10;
        count+=1;
    }
    return count;
}

int fib(char str[],int start)
{
	int i,j;
	int n1,n2,n3,sum,t;
	char s2[30]={0},s3[30]={0},s1[30];
	for(i=start;i<length-2;i++)
	{ 
		for(j=i+1;j<length;j++)
		{
			strncpy(s1,str+start,i+1-start);
			strncpy(s2,str+i+1,j-i);
			if((s1[0]=='0'||s2[0]=='0')&&strcmp(s1,"0")!=0&&strcmp(s2,"0")!= 0) 
				break;
			n1=atoi(s1);
			n2=atoi(s2);
			sum=n1+n2;
			t=len(sum);
			strncpy(s3,str+j+1,t);
			n3=atoi(s3);
			if(n3==sum)
			{
				nums[count]=n1;
				nums[count+1]=n2;
				nums[count+2]=n3;
				count++;
				if(j+t+1==length||fib(str,i+1))
					return 1;
				else
					count--;	
				break;
			}			
		}
	}
	return 0;
}

int main()
{
	int i;
	char str[30];
	gets(str);
	length=strlen(str);
	if(fib(str,0))
		for(i=0;i<count+2;i++)
			printf("%d\t",nums[i]);
	else
		printf("");
}
 
