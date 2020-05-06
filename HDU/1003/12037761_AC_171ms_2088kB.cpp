/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-30 22:41:03
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int array[100000];

int main(void) {
	int t, i, j, n, add, ptr, maxadd, isSpecial, max;
	int thisSum, maxSum;
	cin >> t;
	for (i = 0; i < t; i++)
	{
		isSpecial = 1;
		cin >> n;
		//循环读入
		for (j = 0; j < n; j++)
		{
			cin >> array[j];
		}
		//循环判断是否全为负数
		for (j = 0; j < n; j++)
		{
			if (array[j] > 0)
			{
				isSpecial = 0;
				break;
			}
		}
		if (isSpecial == 1)
		{
			//循环寻找最大的数
			max = -9999;
			maxadd = 1;
			maxSum = 0;
			for (j = 0; j < n; j++)
			{
				if (array[j] > max)
				{
					ptr = j;
					maxSum = array[j];
					max=array[j];
				}
			}
		} else {
			//循环相加
			thisSum = 0;
			maxSum = 0;
			add = 0;
			maxadd = 0;
			ptr = 0;
			for (j = 0; j < n; j++)
			{
				add++;
				thisSum += array[j];
				if (thisSum > maxSum) {
					ptr = j;
					maxadd = add;
					maxSum = thisSum;
				}
				else if (thisSum < 0) {
					thisSum = 0;
					add = 0;
				}
			}
		}
		//输出
		cout << "Case " << i + 1 << ":" << endl;
		cout << maxSum << " " << ptr + 2 - maxadd << " " << ptr + 1 << endl ;
		if (i != t - 1)
		{
			cout << endl;
		}
	}
	return 0;
}