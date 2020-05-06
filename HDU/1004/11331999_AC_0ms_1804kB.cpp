/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-30 22:54:04
 *
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Ball
{
	string color;
	int  num;
} r[1000];

int main(void) {
	int m, bnum, i, j, isBreak, max;
	string tmp;
	while (cin >> m) {
		if (m == 0)
		{
			return 0;
		}
		bnum = 0;
		for (i = 0; i < m; i++)
		{
			isBreak = 0;
			cin >> tmp;
			//循环判断是否存在重名
			for (j = 0; j < bnum; j++)
			{
				if (tmp == r[j].color)
				{
					r[j].num++;
					isBreak = 1;
				}
			}
			//不重名新增
			if (isBreak == 0)
			{
				r[bnum].color = tmp;
				r[bnum].num = 1;
				bnum++;
			}
		}
		//循环判断输出哪一个
		max = 0;
		for (i = 0; i < bnum; i++)
		{
			if (r[i].num > max)
			{
				j = i;
				max = r[i].num;
			}
		}
		cout << r[j].color << endl;
	}
	return 0;
}