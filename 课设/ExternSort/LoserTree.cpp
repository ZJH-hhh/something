#include "LoserTree.hpp"
#include <stdlib.h>
#include <vector>

// 利用败者树ls将k个输入归并段中的记录归并到输出归并段
void K_Merge(FILE *fp_out, LoserTree ls, External b)
{
    int i, q;
    FILE *fp_in[K] = {};
    for (i = 0; i < K; i++)
    {
        input(fp_in, &(b[i].key), i);
    }
    CreateLoserTree(ls, b);
    while (b[ls[0]].key != MAXKEY)
    {
        q = ls[0];
        output(fp_out, b[q].key);
        input(fp_in, &(b[q].key), q);
        Adjust(ls, b, q);
    }
    //output(fp_out, b[ls[0]].key);
    fclose(fp_out);
}

// 从b[s]出发调整败者树
void Adjust(LoserTree ls, External b, int s)
{
    int t, tmp;
    t = (s + K) / 2;
    while (t > 0)
    {
        if (b[s].key > b[ls[t]].key)
        {
            tmp = s;
            s = ls[t];
            ls[t] = tmp;
        }
        t /= 2;
    }
    ls[0] = s;
}

// 依次从b[k-1...0]出发，调整ls为败者树
void CreateLoserTree(LoserTree ls, External b)
{
    int i;
    b[K].key = MINKEY;
    for (i = 0; i < K; i++)
    {
        ls[i] = K;
    }
    for (i = K - 1; i >= 0; i--)
    {
        Adjust(ls, b, i);
    }
}

int freadNum(FILE *fp, int *i)
{
    int tmp;
    int count = 0;
    while ((tmp = getc(fp)) != EOF)
    {
        if ((tmp >= '0'&& tmp <= '9') || (tmp == '+') || (tmp == '-'))
        {
            ungetc(tmp, fp);
            break;
        }
    }
    if (tmp != EOF)
    {
        count = fscanf(fp, "%d", i);
    }
    return count;
}

// 从文件fp[i]中读取关键字到x
void input(FILE *fp[K], int *x, int i)
{
    int tmp;
    char str1[100], str2[100], str3[100] = ".txt";
    if (!fp[i])
    {
        strcpy(str1, "tmpfile/");
        sprintf(str2, "%d", i);
        strcat(str1, strcat(str2, str3));
        fp[i] = fopen(str1, "r");
    }
    if(freadNum(fp[i], &tmp))
    {
        *x = tmp;
        if (tmp == MAXKEY)
            fclose(fp[i]);
    }
}

// 将x输出到有序表fp
void output(FILE *fp, int x)
{
    fprintf(fp, "%d, ", x);
}

// 生成MAX个随机数到fp用作测试
void RandomNum(FILE *fp)
{
    int i, j, number, tag;
    int x[MAX + 1] = {0};
    srand((unsigned) time(NULL));
    for (i = 1; i<= MAX; i++)
    {
        do
        {
            number = rand() % (4*MAX - 1) + 1;
            tag = 0;
            for (j = 1; j <= x[0]; j++)
            {
                if (number == x[j])
                {
                    tag = 1;
                    break;
                }
            }
            if (tag == 0)
            {
                x[0]++;
                x[x[0]] = number;
            }
        }while(tag == 1);
    }
    fprintf(fp, "(%d), ", MAX);
    for (i = 1; i <= x[0]; i++)
    {
        fprintf(fp, "%d, ", x[i]);
    }
    fclose(fp);
}

// 将随机数表fp分段排序后分别写入文件[0...k-1].txt中
void Cut_Sort(FILE *fp)
{
    FILE *fptr;
    int i, j;
    KeyType tmp;
    int len, m, n;
    char str1[100], str2[100], str3[100] = ".txt";
    freadNum(fp, &len);
    m = len / K; // m为一次可以处理的最大数字的个数
    n = K + (len % m != 0); // n为归并段个数
    for (i = 0; i < n; i++)
    {
        vector<KeyType> v;
        strcpy(str1, "./tmpfile/");
        sprintf(str2, "%d", i);
        strcat(str1, strcat(str2, str3));
        fptr = fopen(str1, "w+");
        for (j = 1; j <= m; j++)
        {
            if (freadNum(fp, &tmp) == 1)
            {
                v.push_back(tmp);
            }
            else
                break;
        }
        sort(v.begin(), v.end());
        for (j = 0; j < v.size(); j++)
        {
            fprintf(fptr, "%d, ", v[j]);
        }
        fprintf(fptr, "%d", MAXKEY);
        fclose(fptr);
    }
    fclose(fp);
}