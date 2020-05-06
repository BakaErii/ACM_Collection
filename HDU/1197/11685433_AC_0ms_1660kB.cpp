/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 18:16:24
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, hex, duo, ten, tmp;
	for (i = 1000; i <= 9999; i++)
	{
		//初始化变量
		hex = 0;
		duo = 0;
		ten = 0;
		//十进制
		tmp = i;
		ten += tmp % 10;
		tmp /= 10;
		ten += tmp % 10;
		tmp /= 10;
		ten += tmp % 10;
		tmp /= 10;
		ten += tmp % 10;
		//十二进制
		tmp = i;
		duo += tmp % 12;
		tmp /= 12;
		duo += tmp % 12;
		tmp /= 12;
		duo += tmp % 12;
		tmp /= 12;
		duo += tmp % 12;
		//十六进制
		tmp = i;
		hex += tmp % 16;
		tmp /= 16;
		hex += tmp % 16;
		tmp /= 16;
		hex += tmp % 16;
		tmp /= 16;
		hex += tmp % 16;
		//判断输出
		if (ten == duo && duo == hex)
			cout << i << endl;
	}
	return 0;
}