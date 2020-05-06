#include <stdio.h>
#include <string.h>

int main(void) {
	int line, add, i, len;
	float num;
	char type[2];
	scanf("%d", &line);
	add = 0;
	for (i = 0; i < line; i++)
	{
		add++;
		scanf("%f %s", &num, type);
		//判断类型
		len = strlen(type);
		if (len == 1)
		{
			if (type[0] == 'l')
			{
				num = num * 0.2642;
				strcpy(type, "g");
				printf("%d %.4f", add, num );
				printf(" %s\n", type);
			} else {
				num = num * 3.7854;
				strcpy(type, "l");
				printf("%d %.4f", add, num );
				printf(" %s\n", type);
			}
		} else {
			if (type[0] == 'l')
			{
				num = num * 0.4536;
				strcpy(type, "kg");
				printf("%d %.4f", add, num );
				printf(" %s\n", type);
			} else {
				num = num * 2.2046;
				strcpy(type, "lb");
				printf("%d %.4f", add, num );
				printf(" %s\n", type);
			}
		}
	}
	return 0;
}