char * convert(char * s, int numRows)
{
    if(numRows==1) return s;
    int len=0,i=0,j,t=0;
	while(s[i++]);
	len=i-1;
    char * news=(char*)malloc(sizeof(char)*(len+1));
    int T=2*numRows-2;
    for(i=0;i<numRows;i++)
    {
    	for(j=0;j+i<len;j+=T)
    	{
    		news[t++]=s[j+i];
    		if (i!=0&&i!=numRows-1&&j+T-i<len)
                news[t++]=s[j+T-i];
		}
	}
	news[t]=0;
    return news;
}
/*
行0中的字符位于索引k*(2*numRows-2)处;
行numRows-1中的字符位于索引k*(2*numRows-2)+numRows-1处;
内部的行i中的字符位于索引k*(2*numRows-2)+i以及(k+1)*(2*numRows-2)-i处;
*/
int main(void)
{
	char s[]={"LEETCODEISHIRING"};
	int numsRow=4;
	char * n=convert(s,numsRow);
	printf("%s",n);
}
