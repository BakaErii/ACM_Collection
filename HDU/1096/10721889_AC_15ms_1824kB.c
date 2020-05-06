#include <stdio.h>

int r, line, li, num, numi, tmp;

int main(void)
{
	// getline
	scanf("%d", &line);
	for (li = 0; li < line; li++)
	{
		r = 0;
		// get num
		scanf("%d", &num);
		for (numi = 0; numi < num; numi++)
		{
			scanf("%d", &tmp);
			r = r + tmp;
		}
		printf("%d", r);
		if (line != (li + 1))
		{
			printf("\n\n");
		}
		else
		{
			printf("\n") ;
		}
	}
	return 0;
}