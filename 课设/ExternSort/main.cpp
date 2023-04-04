#include "LoserTree.hpp"

int main() {
    FILE *fp;
    LoserTree ls;
    External b;
    fp = fopen("test.txt", "w+");
    RandomNum(fp);
    fp = fopen("test.txt", "r");
    Cut_Sort(fp);
    fp = fopen("Order.txt", "w+");
    K_Merge(fp, ls, b);
    printf("END\n");

    return 0;
}
