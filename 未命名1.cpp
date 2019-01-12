#include <stdio.h>
int main(void)
{
	struct k
	{
		double a;
		int b;
	};
	int a=sizeof(struct k);
	printf("%d",a);
}

