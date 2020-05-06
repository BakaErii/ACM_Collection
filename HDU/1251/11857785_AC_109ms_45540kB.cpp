/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-05 15:55:42
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

struct Trie
{
	//记录当前节点下共有多少字符串
	int num ;
	//26个叉
	Trie * next[26];
} root;

/**
	对Trie树进行插入操作
		char * str:插入的字符串
**/
void  createTrieNode(char * str) {
	int i, j, id;
	int len = strlen(str);
	//使当前指针指向根
	Trie * ptr = &root;
	Trie * nextptr;
	//执行插入操作
	for (i = 0; i < len; i++) {
		//计算插入时的节点id(a~z==0~25)
		id = str[i] - 'a';
		if (ptr->next[id] == NULL) {
			//当前节点指向的下一个节点为空 新建节点 并将值付给next
			nextptr = (Trie *)malloc(sizeof(struct Trie));
			//初始化节点
			nextptr->num = 0;
			for (j = 0; j < 26; j++)
				nextptr->next[j] = NULL;
			ptr->next[id] = nextptr;
			//将当前节点指针移向下一个节点
			ptr = nextptr;
			//增加计数器
			ptr->num++;
		} else {
			//下个节点有值
			ptr = ptr->next[id];
			ptr->num++;
		}
	}
	return;
}

/**
	对Trie树进行查找操作
		char * str:要查找的字符串
	返回int 查找到的个数
**/
int searchTrieNode(char * str) {
	int i, id;
	int len = strlen(str);
	Trie * ptr = &root;
	//执行搜寻操作 直接访问并返回最后一个节点的num 如果存在NULL则返回0
	for (i = 0; i < len; i++) {
		id = str[i] - 'a';
		if (ptr->next[id] == NULL)
			return 0;
		else {
			ptr = ptr->next[id];
		}
	}
	return ptr->num;
}

int main(void) {
	int i;
	char str[12];
	//初始化根节点
	root.num = 0;
	for (i = 0; i < 26; i++)
		root.next[i] = NULL;
	//读入字符串作为字典
	while (gets(str) && strlen(str) != 0)
		createTrieNode(str);
	//开始查找
	while (gets(str))
		printf("%d\n", searchTrieNode(str));
	return 0;
}
