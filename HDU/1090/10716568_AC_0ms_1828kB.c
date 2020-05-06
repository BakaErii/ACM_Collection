#include <stdio.h>

int a, b, count, r, i;
count = 233;
int main(void)
{
	for (i = -1; i < count; i++){
	if (i == -1)
	{
		scanf("%d", &count);
	}
	else
	{
		scanf("%d %d", &a, &b);
		r = a + b;
		printf("%d\n", r);
	}
	}
	return 0;
}

/*emmm 看来还是不能拿php的思维来理解C*/