/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-15 18:49:12
 *
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	int Table[100001] = {0};
	int n, i, tmp, addtmp;
	//打表
	for (i = 0; i < 100001; i++) {
		tmp = i + 1;
		addtmp = i + 1;
		while (tmp > 0) {
			addtmp += tmp % 10;
			tmp /= 10;
		}
		if (Table[addtmp] == 0 || i + 1 < Table[addtmp])
			if (addtmp <= 100000)
				Table[addtmp] = i + 1;
	}
	while (cin >> n)
		while (n--) {
			cin >> i;
			cout << Table[i] << endl;
		}
	return 0;
}