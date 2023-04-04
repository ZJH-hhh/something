#ifndef LoserTree_hpp
#define LoserTree_hpp
#endif /* LoserTree_hpp */

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <ctime>
#include <algorithm>
using namespace std;

/* 宏定义 */
#ifndef MAXSIZE
#define MAXSIZE 2000
#endif

#define MAX 2500
#define K 5 // k路归并
#define MAXKEY INT_MAX
#define MINKEY INT_MIN

/* k-路归并败者树类型定义 */
typedef int KeyType;
typedef int LoserTree[K];
struct ExNode
{
    KeyType key;
}; // 外结点，只存放待归并记录的关键字
typedef ExNode External[K+1];

/* 败者树函数列表 */
// 利用败者树ls将ke个输入归并段中的记录归并到输出归并段
void K_Merge(FILE *fp, LoserTree ls, External b);

// 从b[s]出发调整败者树
void Adjust(LoserTree ls, External b, int s);

// 依次从b[k-1...0]出发，调整ls为败者树
void CreateLoserTree(LoserTree ls, External b);

int freadNum(FILE *fp, int *i);

// 从文件fp[i]中读取关键字到x
void input(FILE *fp[K], int *x, int i);

// 将x输出到有序表fp
void output(FILE *fp, int x);

// 生成MAX个随机数到fp用作测试
void RandomNum(FILE *fp);

// 将随机数表fp分段排序后分别写入文件[0...k-1].txt中
void Cut_Sort(FILE *fp);