/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-05 22:24:04
 * QwQ 好难吖 希望这次尽可能减少循环不会TLE 哪怕WA也行啊
 */

/*大致思路:循环读入 判断是否是纯0 判断是否小数 去掉前导0 去掉后导0 字符串比较*/

#include <stdio.h>
#include <string.h>

int main(void) {
	int i, j, p, add, alen, blen, e;
	char a[233333], b[233333], ra[233333], rb[233333];
	int isAZero, isADecimals, isAFirst;
	int isBZero, isBDecimals, isBFirst;
	//读入数据
	while (scanf("%s %s", a, b) != EOF) {
		/*对A进行处理*/
		//初始化变量
		isAZero = 1;
		isADecimals = 0;
		add = 0;
		alen = strlen(a);
		isAFirst = 1;
		//对A小数点前进行循环处理
		for (i = 0; i < alen; i++)
		{
			//判断当前数不为0
			if (a[i] != '0')
			{
				if (a[i] == '.')
				{
					//判断是否小数点 结束掉小数点前的循环
					isADecimals = 1;
					p = i;
					i++;
					break;
				} else {
					//不是小数点 不是零 开始读入
					isAZero = 0;
					isAFirst = 0;
					ra[add] = a[i];
					add++;
				}
			} else {
				//如果输入为0 检查是否是前导0
				if (isAFirst == 0)
				{
					ra[add] = a[i];
					add++;
				}
			}
		}
		//对小数点后面进行逆向循环处理 此时p位小数点所在位数
		if (isADecimals == 1) {
			ra[add] = '.';
			add++;
			e = p;
			for (j = alen - 1; j > p; j--)
			{
				//寻找最后一个非0位
				if (a[j] != '0')
				{
					isAZero = 0;
					e = j;
					break;
				}
			}
			//然后输出剩余的去ra
			for (j = 0; i < e + 1; i++)
			{
				ra[add] = a[i];
				add++;
			}
		} else {
			ra[add] = '.';
			add++;
		}
		//结束对A的操作
		ra[add] = '\0';
		//判断A是否全0
		if (isAZero != 0)
		{
			strcpy(ra, "0");
		}
		//调试输出
		//printf("[%d]\n", isAZero );
		//puts(ra);

//---------------------------------------------------------------------------------------------------------------------------

		/*对B进行处理*/
		//初始化变量
		isBZero = 1;
		isBDecimals = 0;
		add = 0;
		blen = strlen(b);
		isBFirst = 1;
		//对B小数点前进行循环处理
		for (i = 0; i < blen; i++)
		{
			//判断当前数不为0
			if (b[i] != '0')
			{
				if (b[i] == '.')
				{
					//判断是否小数点 结束掉小数点前的循环
					isBDecimals = 1;
					p = i;
					i++;
					break;
				} else {
					//不是小数点 不是零 开始读入
					isBZero = 0;
					isBFirst = 0;
					rb[add] = b[i];
					add++;
				}
			} else {
				//如果输入为0 检查是否是前导0
				if (isBFirst == 0)
				{
					rb[add] = b[i];
					add++;
				}
			}
		}
		//对小数点后面进行逆向循环处理 此时p位小数点所在位数
		if (isBDecimals == 1) {
			rb[add] = '.';
			add++;
			e = p;
			for (j = blen - 1; j > p; j--)
			{
				//寻找最后一个非0位
				if (b[j] != '0')
				{
					isBZero = 0;
					e = j;
					break;
				}
			}
			//然后输出剩余的去rb
			for (j = 0; i < e + 1; i++)
			{
				rb[add] = b[i];
				add++;
			}
		}else{
			rb[add] = '.';
			add++;
		}
		//结束对A的操作
		rb[add] = '\0';
		//判断A是否全0
		if (isBZero != 0)
		{
			strcpy(rb, "0");
		}
		//调试输出
		//printf("[%d]\n", isBZero );
		//puts(rb);

//---------------------------------------------------------------------------------------------------------------------------

		//进行比较
		if (strcmp(ra, rb) != 0)
		{
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}