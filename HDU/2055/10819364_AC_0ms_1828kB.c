#include <stdio.h>

int main(void) {
	int r, addnum;
	int i, l;
	char tmp;
	scanf("%d", &l);
	//去除换行
	getchar();
	for (i = 0; i < l; i++)
	{
		//获取字符
		tmp = getchar();
		//获取空格
		getchar();
		//获取数字
		scanf("%d", &addnum);
		//获取换行
		getchar();
		// 输出测试
		// printf("[%c][%f]\n", tmp, addnum);
		//运算
		/*大写字符*/
		if (tmp >= 65 && tmp <= 90)
		{
			r = (int)tmp - 64;
		}
		/*小写字符*/
		if (tmp >= 97 && tmp <= 122)
		{
			r = -((int)tmp - 96);
		}
		//相加运算
		r = r + addnum;
		//输出
		printf("%d\n", r);
	}
	return 0;
}