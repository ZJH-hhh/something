#include "LoserTree.hpp"

void RandData(char filename[]){
    ofstream fout(filename, ios::out|ios::binary);
    if (!fout){
        cout << "The file open failed!\n";
        exit(1);
    }

    Data *p = new Data;
    srand((unsigned) time(NULL));
    for (int i = 0; i < MAX_NUM; i ++ ){
        p -> sno = i;
        p -> cno = rand() % 10;
        int j = 0;
        for (; j < 5; j ++ )
            p -> sname[j] = rand() % 26 + 65;
        p -> sname[j] = '\0';
        fout.write((char*)p, sizeof(Data));
    }

    fout.close();
    delete p;
}

void show(char filename[]){
    ifstream fin(filename, ios::in|ios::binary);
    if (!fin){
        cout << "The file open failed!\n";
        exit(1);
    }

    Data *p = new Data;
    while (fin.read((char*)p, sizeof(Data))){
        cout << p -> sno << ' ';
        cout << p -> cno << ' ';
        cout << p -> sname << endl;
    }

    fin.close();
    delete p;
}

int main()
{
    RandData("test.dat");
    // show("test.dat");

    ExternSort("test.dat");

    return 0;
}