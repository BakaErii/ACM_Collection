/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-27 15:24:27
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

string str;

int main(void) {
	int i, len, lqnum, rqnum, sum;
	cin >> str;
	//初始化变量
	lqnum = 0;
	rqnum = 0;
	sum = 0;
	len = (int)str.length();
	//求共有多少Q
	for (i = 0; i < len; i++) {
		if (str[i] == 'Q')
			rqnum++;
	}
	//求A的位置 lqnum*rqnum为以当前A作为基准的解 加入sum中 如果为Q 则lqnum++ rqnum--
	for (i = 0; i < len; i++) {
		if (str[i] == 'Q') {
			lqnum++;
			rqnum--;
		}
		if (str[i] == 'A')
			sum += lqnum * rqnum;
	}
	//输出
	cout << sum << endl;
	return 0;
}