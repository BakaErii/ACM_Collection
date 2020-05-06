/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-06 15:44:00
 * seed(x+1)=[seed(x)+STEP]%MOD
 */

//(x+y)%m 对任意正整数x存在使x+y的值取到所有可能

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int step, mod, numadd, num;
	//暴力循环
	while (cin >> step >> mod) {
		//初始化计数器
		numadd = 0;
		num = 1;
		do {
			num = (num + step) % mod;
			numadd++;
		} while (num != 1);
		if (numadd != mod)
			printf("%10d%10d    Bad Choice\n\n", step, mod );
		else
			printf("%10d%10d    Good Choice\n\n", step, mod );
	}
	return 0;
}