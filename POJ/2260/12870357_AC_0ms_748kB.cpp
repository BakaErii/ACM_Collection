/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-30 01:28:46
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int arr[100][100];
int col[100];
int row[100];

int main(void) {
	int i, j, n, ansi, ansj, ip, jp;
	while (~scanf("%d", &n) && n != 0) {
		//初始化变量
		ip = 0;
		jp = 0;
		for (i = 0; i < n; i++) {
			col[i] = 0;
			row[i] = 0;
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				row[i] += arr[i][j];
				col[j] += arr[i][j];
			}
		for (i = 0; i < n; i++) {
			if (row[i] % 2 == 1) {
				ip++;
				ansi = i;
			}
			if (col[i] % 2 == 1) {
				jp++;
				ansj = i;
			}
		}
		//判断
		if (ip == 0 && jp == 0) {
			cout << "OK" << endl;
		} else if (ip == 1 && jp == 1) {
			printf("Change bit (%d,%d)\n", ansi + 1, ansj + 1 );
		}else{
			cout<<"Corrupt"<<endl;
		}
	}
	return 0;
}