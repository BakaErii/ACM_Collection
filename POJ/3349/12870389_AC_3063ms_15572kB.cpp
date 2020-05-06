/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-07 14:35:07
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

struct hashtable
{
	int arrptr;
	struct hashtable * nextptr;
} ht[1200007];

int arr[100001][6];

void init(void) {
	int i;
	for (i = 0; i < 1200007; i++)
		ht[i].nextptr = NULL;
	return;
}

bool checkHashtable(int sum, int val) {
	bool isFind = false;
	struct hashtable * ptr;
	int i, j;
	ptr = &ht[sum];
	while (ptr->nextptr != NULL) {
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++)
				if (arr[val][(i + j) % 6] != arr[ptr->arrptr][j])
					break;
			if (j == 6)
				isFind = true;
		}
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++)
				if (arr[val][(i + j) % 6] != arr[ptr->arrptr][5 - j])
					break;
			if (j == 6)
				isFind = true;
		}
		ptr = ptr->nextptr;
	}
	return isFind;
}

bool calHash(int val) {
	int i, sum;
	bool isEqual = false;
	struct hashtable * ptr;
	sum = 0;
	for (i = 0; i < 6; i++)
		sum += arr[val][i];
	isEqual = checkHashtable(sum % 1200007, val);
	ptr = &ht[sum % 1200007];
	while (ptr->nextptr != NULL)
		ptr = ptr->nextptr;
	ptr->arrptr = val;
	ptr->nextptr = (struct hashtable *)malloc(sizeof(struct hashtable));
	ptr = ptr->nextptr;
	ptr->nextptr = NULL;
	return isEqual;
}

int main(void) {
	int i, j, n;
	init();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 6; j++)
			scanf("%d", &arr[i][j]);
		if (calHash(i))
			break;
	}
	if (i != n)
		cout << "Twin snowflakes found." << endl;
	else
		cout << "No two snowflakes are alike." << endl;
	return 0;
}