/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-14 19:33:35
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int ans[1000], cmp[1000];

int main(void) {
	int N, add, i, j, A, B, c1, c2;
	add = 0;
	while (cin >> N && N != 0) {
		//先输出Game
		cout << "Game " << ++add << ":" << endl;
		//读入答案
		for (i = 0; i < N; i++)
			cin >> ans[i];
		//读入数据
		while (1) {
			//初始化变量
			A = 0;
			B = 0;
			for (i = 0; i < N; i++) {
				cin >> cmp[i];
				if (ans[i] == cmp[i])
					A++;
			}
			//判断数据的结束
			if (cmp[0] == 0)
				break;
			//判断答案
			for (i = 1; i <= 9; i++) {
				c1 = 0;
				c2 = 0;
				for (j = 0; j < N; j++) {
					if (ans[j] == i)
						c1++;
					if (cmp[j] == i)
						c2++;
				}
				B += min(c1, c2);
			}
			//输出答案
			cout << "    (" << A << "," << B - A << ")" << endl;
		}
	}
	return 0;
}