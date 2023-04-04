#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

struct Data{
    int sno;
    int cno;
    char sname[20];

    bool operator< (const Data &t) const{
        if (cno != t.cno) return cno < t.cno;
        return sno < t.sno;
    }
};

int main()
{
    ifstream fin("test.dat", ios::in|ios::binary);
    if (!fin){
        exit(1);
    }

    Data *p = new Data;
    while (fin.read((char*)p, sizeof(Data))){
        cout << fin.tellg() << endl;
    }

    fin.close();
    delete p;

    return 0;
}