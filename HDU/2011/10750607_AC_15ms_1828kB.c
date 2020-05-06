#include <stdio.h>

int main()
{
	int num, i, nya,fuck;
	float r, rua,a;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &nya);
		r = 0;
		for (fuck = 0; fuck < nya; fuck++)
		{
		    a=fuck;
			rua = 1 / (a + 1);
			if (fuck % 2 != 0)
			{
				rua = - rua;
			}
			r = r + rua;
		}
		printf("%.2f\n", r);
	}
	return 0;
}