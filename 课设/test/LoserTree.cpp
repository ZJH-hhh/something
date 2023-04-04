#include "LoserTree.hpp"

void RandData(ofstream &fout){
    Data t;
    srand((unsigned) time(NULL));
    for (int i = 0; i < 20; i ++ ){
        t.sno = rand() % 500;
        t.cno = rand() % 10;
        fout << t.sno << t.cno << '\n';
    }

    fout.close();
}