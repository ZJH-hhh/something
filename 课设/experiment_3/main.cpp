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
    // �Զ����ƶ���ʽ���ļ�
    ifstream fin("1259.dat", ios::in | ios::binary); 
    if (!fin){
        // ���ļ�����
        cout << "pg_class open failed!\n";
        // cout << "table_id\n";
        exit(1);
    }

    // �����ļ�
    while (fin.read((char*)p, BLOCK_SIZE)){
        // ������ͬ��ֱ�ӷ��ر�id
        if (strcmp(p -> pgclass.table_name, name) == 0){
            int res = p -> pgclass.table_id;
            att_num = p -> pgclass.num_att;
            fin.close();
            free(p);
            return res;
        }
    }

    // �������ļ�֮��ûreturn˵������Ϊname�ı�����
    cout << "The query table does not exist!\n";
    fin.close();
    free(p);
    return -1;
}

// ���������Ǳ��еĵڼ��У������ڷ���-1
int find_att_loc(char att_name[]){
	PAGE* p = (PAGE*)malloc(BLOCK_SIZE);
    // �����ƶ���ʽ���ļ�
    ifstream fin("1249.dat", ios::in | ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        // cout << "att\n";
        exit(1);
    }

    // ÿ�ζ�ȡһҳ����
    while (fin.read((char*)p, BLOCK_SIZE)){
        // ������ȵĻ�����λ�ã��ر��ļ����ͷ��ڴ�
        if (strcmp(p -> pgatt.att_name, att_name) == 0){
            int res = p -> pgatt.location;
            fin.close();
            free(p);
            return res;
        }
    }

    // �ļ����껹ûreturn˵����������һ��
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
    // ����id�滻���ļ��������ļ�
    sprintf(filename, "%s.dat", table_name);
    // �Զ����ƶ���ʽ��
    ifstream fin(filename, ios::in | ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        // cout << "filter\n";
        exit(1);
    }

    // �жϹ��˵ı��ʽ
    // switch (fi.cmp){
    //     case '>':
    //         while (fin.read((char*)p, BLOCK_SIZE))
    //             // �������������Ԫ��
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

    // ���жϴ򿪵����ĸ���Ȼ���ж�ȡ�ļ�
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

    // �ж�ĳ���Ƿ���Ҫ�����tagλtrue��ʾ������Ҫ���
    bool tag[att_num] = {false}; 
    for (int i = 0; i < cnt; i ++ ){
        int pos = find_att_loc(att_name[i]);
        if (pos != -1) {
            tag[pos - 1] = true;
            // cout << att_name[i] << '\t';
        }
    }

    // ����Ԫ��
    filter(table_name, tag, att_type, fi, att_num);
}


void SaveToFile(Data* p, int num){
    char file[50];
    sprintf(file, "tmp_file_%d.txt", num);
    ofstream fout(file, ios::app); // ��׷��ģʽ���ļ�
    if (!fout){
        cout << "The SavaFie open failed!\n";
        exit(1);
    }

    fout << p -> sno << p -> cno << p -> sname << endl;

    fout.close();
}

void merge(int num1, int num2, int res){
    // �򿪱��Ϊnum1��num2���ļ�
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
    // ��ȡ�н��бȽ�Ȼ�����ṹ��
    while (fin1.read((char*)p1, sizeof(Data)) && fin2.read((char*)p2, sizeof(Data))){
        if (*p1 < *p2){
            tmp[cnt] = *p1;
            fin2.seekg(-sizeof(Data), ios::cur); // ��ǰ�ƶ�sizeof��data�����ֽ�
        }
        else {
            tmp[cnt] = *p2;
            fin1.seekg(-sizeof(Data), ios::cur);
        }
        cnt ++ ;

        // ����ȡ���ݴﵽһ���飬��������ļ�
        if (cnt >= BLOCK_SIZE / sizeof(Data)){
            SaveToFile(tmp, res);
            cnt = 0;
        }
    }

    // ��ʣ�µ����ݴ���res�ļ�
    while (fin1.read((char*)p1, BLOCK_SIZE)) SaveToFile(p1, res);
    while (fin2.read((char*)p2, BLOCK_SIZE)) SaveToFile(p2, res);

    // �ͷ�ָ�룬�ر��ļ�
    delete p1;
    delete p2;
    fin1.close();
    fin2.close();
}


void mergeruns(char table_name[], char att_name[]){
    // ���ݱ�����ļ�
    ifstream fin(table_name, ios::in | ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        // cout << "mergerous\n";
        exit(1);
    }

    Student* p = new Student;

    // ���ļ����ݶ�����data�ṹ������
    Data data[BLOCK_SIZE / sizeof(Data)];
    queue<int> wait_merge; // �洢���鲢����ʱ�ļ��ı��
    int num = 0; // ��ʱ�ļ��ı��

    int i = 0;
    while (fin.read((char*)p, sizeof(Data))){
        data[i].sno = p -> sno;
        data[i].cno = p -> cno;
        strcpy(data[i].sname, p -> sname);
        i ++ ;

        if (i >= BLOCK_SIZE / sizeof(Data)){
            // ���ṹ�尴����
            sort(data, data + i);

            // ��дģʽ���ļ�
            char tmp_file[50];
            sprintf(tmp_file, "tmp_file_%d.txt", num);
            ofstream fout(tmp_file, ios::out);
            if (!fout){
                cout << "The tmp_file open failed\n";
                exit(1);
            }
            
            // ���ź����һ��д���ڴ�
            for (int j = 0; j < i; j ++ )
                fout << data[j].sno << '\t' << data[j].cno << '\t' << data[j].sname << '\n';
            
            fout.close();

            wait_merge.push(num), num ++ ; // ��ʱ�ļ���ŷŽ���β

            i = 0;
        }
    }

    fin.close();
    delete p;
    
    // �鲢��ֱ������ֻʣһ��Ԫ�أ���Ϊ�����ź�����ļ�
    while (wait_merge.size() > 1) {
        // ȡ��ͷ�����ļ���ţ����ж�·�鲢��Ȼ���䵯��
        int t1 = wait_merge.front(); wait_merge.pop();
        int t2 = wait_merge.front(); wait_merge.pop();
        merge(t1, t2, num); // ��t1,t2�鲢�����Ϊnum���ļ�
        wait_merge.push(num); // ��num�����β
        num ++ ; // ��ż�һ
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