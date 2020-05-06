/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-18 20:29:37
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	char command[10];
	char astack[200][71];
	char bstack[200][71];
	int ptra, ptrb;
	char tmp[71];
	strcpy(astack[0],"http://www.acm.org/");
	ptra = 1;
	ptrb = 0;
	while (scanf("%s", command) != EOF) {
		//初始化变量
		if (strcmp(command, "VISIT") == 0)
		{
			//获取网址
			scanf("%s", tmp);
			//将网址放在栈A 指针向后移动 此时指针指向栈顶
			strcpy(astack[ptra], tmp);
			ptra++;
			//将B栈的指针归零
			ptrb = 0;
			printf("%s\n", astack[ptra - 1] );
		}
		if (strcmp(command, "BACK") == 0)
		{
			//判断栈内是否有数据且指针所指位置是否有效
			if (ptra >= 2)
			{
				//将栈A顶部的元素放入B栈 指针下移
				strcpy(bstack[ptrb], astack[ptra - 1]);
				ptra--;
				ptrb++;
				//输出当前网址
				printf("%s\n", astack[ptra - 1] );
			} else {
				printf("Ignored\n");
			}
		}
		if (strcmp(command, "FORWARD") == 0)
		{
			//判断栈内是否有数据且指针所指位置是否有效
			if (ptrb >= 1)
			{
				strcpy(astack[ptra], bstack[ptrb - 1]);
				ptra++;
				ptrb--;
				printf("%s\n", astack[ptra - 1] );
			} else {
				printf("Ignored\n");
			}
		}
		if (strcmp(command, "QUIT") == 0)
		{
			return 0;
		}
	}
	return 0;
}