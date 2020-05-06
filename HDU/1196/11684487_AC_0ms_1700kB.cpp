/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 17:13:27
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int array[100];
	int a, ptr, i, sum;
	while (cin >> a && a != 0) {
		ptr = 0;
		while (a != 0) {
			array[ptr] = a % 2;
			if (array[ptr++] == 1)
				break;
			a /= 2;
		}
		//ptr向前位数
		sum = 1;
		for (i = 1; i < ptr; i++)
		{
			sum *= 2;
		}
		cout << sum << endl;
	}
	return 0;
}