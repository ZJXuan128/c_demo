#include <stdio.h>
int main(void)
{
	struct k
	{
		double a;
		int b;
		char c;
	};
	int a=sizeof(struct k);
	printf("%d",a);
}

