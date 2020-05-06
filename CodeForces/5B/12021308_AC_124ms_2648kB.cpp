/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-19 19:40:23
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

struct text
{
	string str;
	int len;
} s[1050];

int main(void) {
	int i, j, line = 0, column = 0, offset;
	bool al = false;
	while (getline(cin, s[line].str)) {
		s[line].len = (int)s[line].str.length();
		column = max(s[line].len, column);
		line++;
	}
	//输出
	for (i = 0; i < column + 2; i++)
		putchar('*');
	putchar('\n');
	for (i = 0; i < line; i++) {
		putchar('*');
		if ((column - s[i].len) % 2 == 0)
			offset = (column - s[i].len) / 2;
		else {
			offset = (column - s[i].len) / 2;
			if (al) {
				offset++;
				al = false;
			} else {
				al = true;
			}
		}
		for (j = 0; j < column; j++)
			if (j == offset) {
				cout << s[i].str;
				j += s[i].len;
				if(j!=column)
					putchar(' ');
			}
			else
				putchar(' ');
		// if (al == true)
		// 	putchar(' ');
		putchar('*');
		putchar('\n');
	}
	for (i = 0; i < column + 2; i++)
		putchar('*');
	putchar('\n');
	return 0;
}