#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

#ifndef BLOCK_SIZE 
#define BLOCK_SIZE 8192
#endif

const int MAX_NUM = 2000;

struct Data{
    int sno;
    int cno;
    char sname[20];

    bool operator< (const Data &t) const{
        if (cno != t.cno) return cno < t.cno;
        return sno < t.sno;
    }
}data[BLOCK_SIZE * 3];


ExternSort(char filename[]){
    ifstream fin(filename, ios::in|ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        exit(1);
    }

    Data* p = new Data;
    int cnt = 0;
    // 每次读取两个块的内容
    while (fin.tellg() < BLOCK_SIZE * 2 && fin.read((char*)p, sizeof(Data))){
        data[cnt].sno = p -> sno;
        data[cnt].cno = p -> cno;
        strcpy(data[cnt].sname, p -> sname);
        cnt ++ ;
    }

    sort(data, data + cnt);
    for (int i = 0; i < cnt ;i ++ ){
        cout << data[i].sno << ' ';
        cout << data[i].cno << ' ';
        cout << data[i].sname << endl;
    }

    fin.close();
    delete p;
}