#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <queue>
#include "struct.h"

using namespace std;

const int BLOCK_SIZE = 8192;
const int NAME_SIZE = 10;
const int att_num_MAX = 10;

int find_table_id(char* name, int &att_num){
    PAGE* p = (PAGE*)malloc(BLOCK_SIZE);
    // 以二进制读方式打开文件
    ifstream fin("1259.dat", ios::in | ios::binary); 
    if (!fin){
        // 打开文件错误
        cout << "pg_class open failed!\n";
        // cout << "table_id\n";
        exit(1);
    }

    // 遍历文件
    while (fin.read((char*)p, BLOCK_SIZE)){
        // 表名相同，直接返回表id
        if (strcmp(p -> pgclass.table_name, name) == 0){
            int res = p -> pgclass.table_id;
            att_num = p -> pgclass.num_att;
            fin.close();
            free(p);
            return res;
        }
    }

    // 遍历完文件之后还没return说明表名为name的表不存在
    cout << "The query table does not exist!\n";
    fin.close();
    free(p);
    return -1;
}

// 查找属性是表中的第几列，不存在返回-1
int find_att_loc(char att_name[]){
	PAGE* p = (PAGE*)malloc(BLOCK_SIZE);
    // 二进制读方式打开文件
    ifstream fin("1249.dat", ios::in | ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        // cout << "att\n";
        exit(1);
    }

    // 每次读取一页内容
    while (fin.read((char*)p, BLOCK_SIZE)){
        // 属性相等的话返回位置，关闭文件，释放内存
        if (strcmp(p -> pgatt.att_name, att_name) == 0){
            int res = p -> pgatt.location;
            fin.close();
            free(p);
            return res;
        }
    }

    // 文件读完还没return说明不存在这一列
	cout << "The attribute does not exist!\n";
    fin.close();
    free(p);
    return -1;
}

void show(Student* p, bool tag[], int att_num){
    if (att_num == 0) return ;
    if (tag[0]) cout << p -> sno;
    if (tag[1]) cout << p -> cno;
    if (tag[2]) cout << p -> sname;
}

bool check(Student* p, char cmp, int value){
    if (cmp == '<') return p -> sno < value;
    if (cmp == '=') return p -> sno == value;
    if (cmp == '>') return p -> sno > value;
}

void filter(char table_name[], bool tag[], char att_type[][5], FT fi, int att_num){
    char filename[50];
    // 将表id替换成文件名，打开文件
    sprintf(filename, "%s.dat", table_name);
    // 以二进制读方式打开
    ifstream fin(filename, ios::in | ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        // cout << "filter\n";
        exit(1);
    }

    // 判断过滤的表达式
    // switch (fi.cmp){
    //     case '>':
    //         while (fin.read((char*)p, BLOCK_SIZE))
    //             // 输出符合条件的元组
    //             if (p -> stu.sno > fi.value) show(p, tag);
    //         break;

    //     case '<':
    //         while (fin.read((char*)p, BLOCK_SIZE))
    //             if (p -> stu.sno < fi.value) show(p, tag);
    //         break;
        
    //     case '=':
    //         while (fin.read((char*)p, BLOCK_SIZE))
    //             if (p -> stu.sno == fi.value) show(p, tag);
    //         break;

    //     default:
    //         cout << "ERROR!\n";
    //         break;
    // }

    // 先判断打开的是哪个表，然后按行读取文件
    // int data_size = 0;
    // if (strcpy(table_name, "student") == 0){
    //     Student* p = new Student;
    //     data_size = sizeof(Student);
    // } 
    // else if (strcpy(table_name, "course") == 0) {
    //     Course* p = new Course;
    //     data_size = sizeof(Course);
    // }
    // else{
    //     SC* p = new SC;
    //     data_size = sizeof(SC);
    // }

    Student* p = new Student;
    int data_size = sizeof(Student);

    while (fin.read((char*)p, data_size)){
        switch (fi.cmp){
            case '<':
                if (check(p, '<', fi.value)) show(p, tag, att_num);
                break;

            case '=':
                if (check(p, '=', fi.value)) show(p, tag, att_num);
                break;

            case '>':
                if (check(p, '>', fi.value)) show(p, tag, att_num);
        }
    }

    fin.close();
    delete p;
}

void exec_simple_query(char* table_name, char att_name[][NAME_SIZE], char att_type[][5], FT fi, int cnt){
    int att_num;
    int table_id = find_table_id(table_name, att_num);
    if (table_id == -1){
        cout << "The table does not exist!\n";
        return ;
    }

    // 判断某列是否需要输出，tag位true表示这列需要输出
    bool tag[att_num] = {false}; 
    for (int i = 0; i < cnt; i ++ ){
        int pos = find_att_loc(att_name[i]);
        if (pos != -1) {
            tag[pos - 1] = true;
            // cout << att_name[i] << '\t';
        }
    }

    // 过滤元组
    filter(table_name, tag, att_type, fi, att_num);
}


void SaveToFile(Data* p, int num){
    char file[50];
    sprintf(file, "tmp_file_%d.txt", num);
    ofstream fout(file, ios::app); // 以追加模式打开文件
    if (!fout){
        cout << "The SavaFie open failed!\n";
        exit(1);
    }

    fout << p -> sno << p -> cno << p -> sname << endl;

    fout.close();
}

void merge(int num1, int num2, int res){
    // 打开编号为num1和num2的文件
    char file1[50], file2[50];
    sprintf(file1, "tmp_file_%d.txt", num1);
    sprintf(file2, "tmp_file_%d.txt", num2);

    ifstream fin1(file1, ios::in);
    if (!fin1){
        cout << "The file1 open failed!\n";
        exit(1);
    }
    ifstream fin2(file2, ios::in);
    if (!fin2){
        cout << "The file2 open failed!\n";
        exit(1);
    }

    Data* p1 = new Data;
    Data* p2 = new Data;
    Data tmp[BLOCK_SIZE / sizeof(Data)];
    int cnt = 0;
    // 读取行进行比较然后放入结构体
    while (fin1.read((char*)p1, sizeof(Data)) && fin2.read((char*)p2, sizeof(Data))){
        if (*p1 < *p2){
            tmp[cnt] = *p1;
            fin2.seekg(-sizeof(Data), ios::cur); // 向前移动sizeof（data）个字节
        }
        else {
            tmp[cnt] = *p2;
            fin1.seekg(-sizeof(Data), ios::cur);
        }
        cnt ++ ;

        // 当读取内容达到一个块，将其存入文件
        if (cnt >= BLOCK_SIZE / sizeof(Data)){
            SaveToFile(tmp, res);
            cnt = 0;
        }
    }

    // 将剩下的数据存入res文件
    while (fin1.read((char*)p1, BLOCK_SIZE)) SaveToFile(p1, res);
    while (fin2.read((char*)p2, BLOCK_SIZE)) SaveToFile(p2, res);

    // 释放指针，关闭文件
    delete p1;
    delete p2;
    fin1.close();
    fin2.close();
}


void mergeruns(char table_name[], char att_name[]){
    // 根据表面打开文件
    ifstream fin(table_name, ios::in | ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        // cout << "mergerous\n";
        exit(1);
    }

    Student* p = new Student;

    // 将文件内容读出到data结构体数组
    Data data[BLOCK_SIZE / sizeof(Data)];
    queue<int> wait_merge; // 存储待归并的临时文件的编号
    int num = 0; // 临时文件的编号

    int i = 0;
    while (fin.read((char*)p, sizeof(Data))){
        data[i].sno = p -> sno;
        data[i].cno = p -> cno;
        strcpy(data[i].sname, p -> sname);
        i ++ ;

        if (i >= BLOCK_SIZE / sizeof(Data)){
            // 将结构体按排序
            sort(data, data + i);

            // 以写模式打开文件
            char tmp_file[50];
            sprintf(tmp_file, "tmp_file_%d.txt", num);
            ofstream fout(tmp_file, ios::out);
            if (!fout){
                cout << "The tmp_file open failed\n";
                exit(1);
            }
            
            // 将排好序的一块写入内存
            for (int j = 0; j < i; j ++ )
                fout << data[j].sno << '\t' << data[j].cno << '\t' << data[j].sname << '\n';
            
            fout.close();

            wait_merge.push(num), num ++ ; // 临时文件编号放进队尾

            i = 0;
        }
    }

    fin.close();
    delete p;
    
    // 归并，直至队列只剩一个元素，则为最终排好序的文件
    while (wait_merge.size() > 1) {
        // 取队头两个文件编号，进行二路归并，然后将其弹出
        int t1 = wait_merge.front(); wait_merge.pop();
        int t2 = wait_merge.front(); wait_merge.pop();
        merge(t1, t2, num); // 将t1,t2归并到编号为num的文件
        wait_merge.push(num); // 将num加入队尾
        num ++ ; // 编号加一
    }
}

int main()
{
    FT filter = {"sno", '<', 78};

    // char condition[][10] = {"sno\t", "sname\t"};
    
    int cnt;
    cin >> cnt;
    char att_name[att_num_MAX][NAME_SIZE];
    for (int i = 0; i < cnt; i ++ )  cin >> att_name[i];
    
    char att_type[att_num_MAX][5];
    for (int i = 0; i < cnt; i ++ ) cin >> att_type[i];

    char table_name[NAME_SIZE];
    cin >> table_name;
    exec_simple_query(table_name, att_name, att_type, filter, cnt);
    
    mergeruns("4433.dat", "sno");

	return 0;
}