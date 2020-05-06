#include <stdio.h>

int main(void)
{
	char nya[100], i;
	while (gets(nya))
	{
	    nya[0]=nya[0]-32;
		for (i = 0; nya[i] != '\0'; i++)
		{
		    if(nya[i]==' '){
		        nya[i+1]=nya[i+1]-32;
		    }
			printf("%c", nya[i]);
		}
		printf("\n");
	}
	return 0;
}