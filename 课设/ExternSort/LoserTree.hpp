#ifndef LoserTree_hpp
#define LoserTree_hpp
#endif /* LoserTree_hpp */

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <ctime>
#include <algorithm>
using namespace std;

/* �궨�� */
#ifndef MAXSIZE
#define MAXSIZE 2000
#endif

#define MAX 2500
#define K 5 // k·�鲢
#define MAXKEY INT_MAX
#define MINKEY INT_MIN

/* k-·�鲢���������Ͷ��� */
typedef int KeyType;
typedef int LoserTree[K];
struct ExNode
{
    KeyType key;
}; // ���㣬ֻ��Ŵ��鲢��¼�Ĺؼ���
typedef ExNode External[K+1];

/* �����������б� */
// ���ð�����ls��ke������鲢���еļ�¼�鲢������鲢��
void K_Merge(FILE *fp, LoserTree ls, External b);

// ��b[s]��������������
void Adjust(LoserTree ls, External b, int s);

// ���δ�b[k-1...0]����������lsΪ������
void CreateLoserTree(LoserTree ls, External b);

int freadNum(FILE *fp, int *i);

// ���ļ�fp[i]�ж�ȡ�ؼ��ֵ�x
void input(FILE *fp[K], int *x, int i);

// ��x����������fp
void output(FILE *fp, int x);

// ����MAX���������fp��������
void RandomNum(FILE *fp);

// ���������fp�ֶ������ֱ�д���ļ�[0...k-1].txt��
void Cut_Sort(FILE *fp);