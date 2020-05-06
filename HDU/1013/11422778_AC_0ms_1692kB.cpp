/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-05 17:53:52
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	char str[10000];
	int len, n, i, tmp, cal;
	while (scanf("%s", str) != EOF) {
		n = 0;
		len = strlen(str);
		if (len == 1 && str[0] == '0')
		{
			return 0;
		}
		for (i = 0; i < len; i++)
		{
			n += str[i] - '0';
		}
		if (n < 10)
		{
			cout << n << endl;
		} else {
			tmp = n;
			cal = 10;
			while (cal >= 10) {
				cal = 0;
				while (tmp != 0) {
					cal += tmp % 10;
					tmp /= 10;
				}
				tmp = cal;
			}
			cout << cal << endl;
		}
	}
	return 0;
}