/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-09 15:48:31
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

int arr[4000][4];
int rab[16000000], rcd[16000000];


/*
	二分搜索
		int arr[]:欲搜索的数组 须升序排列
		int start:开始搜索的范围
		int end:结束搜索的范围
		int key:欲搜索的值
	返回int 查找到的个数 若无则返回0
*/
int bisearch(int arr[], int start, int end, int key) {
	int mid, num, i;
	int left = start, right = end;
	num = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else if (arr[mid] > key)
			right = mid - 1;
		else {
			num++;
			//已经找到key值 向两侧判断是否存在紧挨
			i = 1;
			while (mid + i < end && arr[mid + i] == key) {
				num++;
				i++;
			}
			i = 1;
			while (mid - i >= start && arr[mid - i] == key) {
				num++;
				i++;
			}
			return num;
		}
	}
	return 0;
}

int main(void) {
	int i, j, n, ans, ptr, tmp;
	//初始化变量
	ans = 0;
	cin >> n;
	//获取输入
	for (i = 0; i < n; i++)
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	//计算ab的和
	ptr = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			rab[ptr++] = arr[i][0] + arr[j][1];
	//计算cd的和
	ptr = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			rcd[ptr++] = arr[i][2] + arr[j][3];
	//对ab和bc排序
	sort(rab, rab + ptr);
	sort(rcd, rcd + ptr);
	//二分查找对应的数
	for (i = 0; i < ptr; i++) {
		tmp = 0 - rab[i];
		ans += bisearch(rcd, 0, ptr, tmp);
	}
	cout << ans << endl;
	return 0;
}