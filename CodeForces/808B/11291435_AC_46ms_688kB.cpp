/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-28 19:49:47
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int array[200000];

int main(void) {
	//爆unsigned long long
	int i, ptr, n, k, times;
	double r;
	unsigned long long rtmp;
	scanf("%d %d", &n, &k);
	//初始化变量
	ptr = 0;
	r = 0;
	rtmp = 0;
	times = n - k + 1;
	//循环读入先
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	//先读取k个值 然后记录下最开始的一个数
	for (i = 0; i < k; i++)
	{
		rtmp += array[i];
	}
	//求出前面那几项的值
	r += rtmp / (double)times;
	//开始求剩下的值
	for (i = k; i < n; i++)
	{
		//先向后读取一个值
		rtmp += array[i];
		//然后删除掉前一个值 指针后移
		rtmp -= array[ptr];
		ptr++;
		//求和
		r += rtmp / (double)times;
	}
	//最后输出
	printf("%.7lf\n",r );
	return 0;
}