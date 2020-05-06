/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-18 16:48:39
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

char arr[3][3];

int main(void) {
	int i, j, xnum = 0, onum = 0;
	bool isFirstWin = false, isSecondWin = false;
	//读入矩阵
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			arr[i][j] = getchar();
			if (arr[i][j] == 'X')
				xnum++;
			else if (arr[i][j] == '0')
				onum++;
		}
		getchar();
	}
	//没下的特殊情况
	if (xnum == 0 && onum == 0) {
		cout << "first" << endl;
		return 0;
	}
	//判断非法
	if (!(xnum - onum == 0 || xnum - onum == 1)) {
		cout << "illegal" << endl;
		return 0;
	}
	//判断输赢 横向
	for (i = 0; i < 3; i++) {
		for (j = 1; j < 3; j++)
			if (arr[i][0] != arr[i][j] && arr[i][0] != '.')
				break;
		if (arr[i][0] == 'X' && j == 3) {
			isFirstWin = true;
		}
		else if (arr[i][0] == '0' && j == 3) {
			isSecondWin = true;
		}
	}
	//判断输赢 竖向
	for (j = 0; j < 3; j++) {
		for (i = 1; i < 3; i++)
			if (arr[0][j] != arr[i][j] && arr[0][j] != '.')
				break;
		if (arr[0][j] == 'X' && i == 3) {
			isFirstWin = true;
		}
		else if (arr[0][j] == '0' && i == 3) {
			isSecondWin = true;
		}
	}
	//判断输赢 斜向
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.' && arr[0][0] == 'X') {
		isFirstWin = true;
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] != '.' && arr[2][0] == 'X') {
		isFirstWin = true;
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '.' && arr[0][0] == '0') {
		isSecondWin = true;
	}
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] != '.' && arr[2][0] == '0') {
		isSecondWin = true;
	}
	if (isFirstWin == isSecondWin && isFirstWin == true) {
		cout << "illegal" << endl;
		return 0;
	}
	if (isFirstWin) {
		if (xnum == onum) {
			cout << "illegal" << endl;
			return 0;
		}
		cout << "the first player won" << endl;
		return 0;
	}
	if (isSecondWin) {
		if (xnum != onum) {
			cout << "illegal" << endl;
			return 0;
		}
		cout << "the second player won" << endl;
		return 0;
	}
	//平局
	if (xnum + onum == 9) {
		cout << "draw" << endl;
		return 0;
	}
	//判断谁先下
	if (xnum - onum == 1) {
		cout << "second" << endl;
		return 0;
	} else {
		cout << "first" << endl;
		return 0;
	}
	return 0;
}