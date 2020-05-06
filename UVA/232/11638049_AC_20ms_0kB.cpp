/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-19 20:25:42
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;
} p[100];

int main(void) {
	int r, c, i, j, num, kase, ptrx, ptry;
	char line[10][11];
	//全局初始化
	kase = 0;
	while (cin >> r && r != 0) {
		cin >> c;
		//初始化变量
		num = 0;
		//获取字符方阵
		getchar();
		for (i = 0; i < r; i++) {
			cin.getline(line[i], 11);
			// //调试输入
			// cout << line[i] << endl;
		}
		//判断所有的起始点位
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				if (line[i][j] != '*') {
					//当前非黑块 判断左和上的位置
					//当前是顶行 所有点都是起始点
					if (i == 0) {
						p[num].x = j;
						p[num].y = i;
						num++;
						continue;
					}
					//当前不是顶行 判断自己的左侧和上侧
					if (j == 0 || line[i][j - 1] == '*' || line[i - 1][j] == '*' ) {
						p[num].x = j;
						p[num].y = i;
						num++;
						continue;
					}
				}
		// //调试输出
		// for (i = 0; i < num; i++)
		// 	cout << p[i].x << "|" << p[i].y << endl;
		//输出puzzle
		if (kase != 0)
			cout << endl;
		cout << "puzzle #" << ++kase << ":" << endl;
		//输出横向
		cout << "Across" << endl;
		//初始化变量
		ptrx = 0;
		ptry = 0;
		i = 0;
		while (i < num) {
			//判断起始点是否在当前行
			if (p[i].y == ptry) {
				//在 判断之后 输出
				if (p[i].x >= ptrx) {
					ptrx = p[i].x;
					//输出起始位置
					printf("%3d.", i + 1 );
					//输出剩下的字符
					while (line[ptry][ptrx] != '*' && ptrx != c) {
						cout << line[ptry][ptrx];
						ptrx++;
					}
					cout << endl;
				} else {
					//不符合条件
					i++;
					continue;
				}
			} else {
				//不在 下一个点 x指针归零
				ptrx = 0;
				ptry++;
				continue;
			}
		}
		//输出纵向
		cout << "Down" << endl;
		//初始化变量
		i = 0;
		//初始化数组 代表了各个列的指针所在位置
		int ptr[10] = {0};
		while (i < num) {
			//判断起始点是哪一列 之后向下输出
			if (p[i].y >= ptr[p[i].x]) {
				ptr[p[i].x] = p[i].y;
				//输出起始位置
				printf("%3d.", i + 1 );
				while (line[ptr[p[i].x]][p[i].x] != '*' && ptr[p[i].x] != r) {
					cout << line[ptr[p[i].x]][p[i].x];
					ptr[p[i].x]++;
				}
				cout << endl;
				i++;
			} else {
				i++;
			}
		}
	}
	return 0;
}