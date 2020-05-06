/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-16 19:49:30
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, bit, len, t, mol;
	double  mm;
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		//初始化变量
		mol = 0;
		bit = 1;
		mm = 0;
		len = (int)str.length();
		//逆向判断
		for (i = len - 1; i >= 0; i--)
		{
			switch (str[i]) {
			case 'C':
				if (mol == 0)
					mm += 12.01;
				else {
					//计算
					mm += mol * 12.01;
					//清空计数器
					mol = 0;
					bit = 1;
				}
				break;
			case 'H':
				if (mol == 0)
					mm += 1.008;
				else {
					//计算
					mm += mol * 1.008;
					//清空计数器
					mol = 0;
					bit = 1;
				}
				break;
			case 'O':
				if (mol == 0)
					mm += 16.00;
				else {
					//计算
					mm += mol * 16.00;
					//清空计数器
					mol = 0;
					bit = 1;
				}
				break;
			case 'N':
				if (mol == 0)
					mm += 14.01;
				else {
					//计算
					mm += mol * 14.01;
					//清空计数器
					mol = 0;
					bit = 1;
				}
				break;
			default:
				//对当前的摩尔进行进位
				mol += bit * (str[i] - '0');
				bit *= 10;
				break;
			}
		}
		printf("%.3lf\n", mm );
	}
	return 0;
}