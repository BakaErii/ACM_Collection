#include <stdio.h>
#include <string.h>

int main(void) {
	char ljb[51];
	int i, j, l, r, len;
	scanf("%d", &l);
	//消除换行符
	getchar();
	for (i = 0; i < l; i++)
	{
		//初始化变量
		r = 0;
		//循环读入字符串
		gets(ljb);
		//判断部分
		//整数
		for (j = 0; ljb[j] != '\0'; j++)
		{
			if (ljb[j] >= 48 && ljb[j] <= 57)
			{
				r++;
				break;
			}
		}
		//大写
		for (j = 0; ljb[j] != '\0'; j++)
		{
			if (ljb[j] >= 65 && ljb[j] <= 90)
			{
				r++;
				break;
			}
		}
		//小写
		for (j = 0; ljb[j] != '\0'; j++)
		{
			if (ljb[j] >= 97 && ljb[j] <= 122)
			{
				r++;
				break;
			}
		}
		//字符
		for (j = 0; ljb[j] != '\0'; j++)
		{
			if (((ljb[j] == '~' || ljb[j] == '!') || (ljb[j] == '@' || ljb[j] == '#')) || ((ljb[j] == '$' || ljb[j] == '%') || ljb[j] == '^'))
			{
				r++;
				break;
			}
		}
		//判断字数
		len = strlen(ljb);
		if (len < 8 || len > 16)
		{
			r = 0;
		}
		//输出
		if (r >= 3)
		{
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}