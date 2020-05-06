/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-02 19:02:12
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

int t, n;
char keyWord[51];
char mainWord[1000001];

//定义结构体
struct TrieNode {
	//匹配失败指针
	TrieNode * failPtr;
	//子节点指针
	TrieNode * nextPtr[26];
	//判断是否是单词的结尾 是为1 不是为0
	int cnt;
} root;

//初始化Trie树节点
void initTrieNode(TrieNode * nowPtr) {
	nowPtr->failPtr = NULL;
	memset(nowPtr->nextPtr, 0, sizeof(nowPtr->nextPtr));
	nowPtr->cnt = 0;
	return;
}

//插入关键词
void insertWord(char * str) {
	int i, len;
	TrieNode * nowPtr = &root;
	len = strlen(str);
	for (i = 0; i < len; i++) {
		if (nowPtr->nextPtr[str[i] - 'a'] == NULL) {
			nowPtr->nextPtr[str[i] - 'a'] = (TrieNode *)malloc(sizeof(struct TrieNode));
			initTrieNode(nowPtr->nextPtr[str[i] - 'a']);
		}
		nowPtr = nowPtr->nextPtr[str[i] - 'a'];
	}
	nowPtr->cnt++;
	return;
}

//构建失败指针
void buildFailPtr(void) {
	//初始化队列 用于存放节点的指针 方便BFS
	queue<TrieNode *> que;
	TrieNode * nowPtr = &root;
	int i;
	//初始化根节点的失败指针
	root.failPtr = &root;
	//构建根节点的子节点的失败指针(匹配跳转指针)
	for (i = 0; i < 26; i++)
		if (root.nextPtr[i] == NULL)
			root.nextPtr[i] = &root;
		else {
			//先将子节点的失败指针指向根节点 加入队列 在BFS的时候更新
			root.nextPtr[i]->failPtr = &root;
			que.push(root.nextPtr[i]);
		}
	while (!que.empty()) {
		//取出队列前端元素
		nowPtr = que.front();
		que.pop();
		//遍历26个子节点 重复类似根节点的操作
		for (i = 0; i < 26; i++)
			if (nowPtr->nextPtr[i] == NULL) {
				nowPtr->nextPtr[i] = nowPtr->failPtr->nextPtr[i];
			} else {
				nowPtr->nextPtr[i]->failPtr = nowPtr->failPtr->nextPtr[i];
				que.push(nowPtr->nextPtr[i]);
			}
	}
	return;
}

//在主字符串中搜索关键词总共出现的次数
int searchKeyWord(void) {
	int len = strlen(mainWord);
	int i, ans = 0;
	TrieNode * nowPtr = &root;
	TrieNode * matchPtr;
	for (i = 0; i < len; i++) {
		nowPtr = nowPtr->nextPtr[mainWord[i] - 'a'];
		matchPtr = nowPtr;
		while (matchPtr != &root) {
			ans = ans + matchPtr->cnt;
			matchPtr->cnt = 0;
			matchPtr = matchPtr->failPtr;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	scanf("%d", &t);
	while (t--) {
		initTrieNode(&root);
		scanf("%d", &n);
		getchar();
		for (i = 0; i < n; i++) {
			gets(keyWord);
			insertWord(keyWord);
		}
		gets(mainWord);
		buildFailPtr();
		printf("%d\n", searchKeyWord());
	}
	return 0;
}