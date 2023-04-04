#include<iostream>
using namespace std;

struct HEAP{
    int* data;
    int reserved_size;
    int cur_size;
   HEAP(int size);
    void push( int value );
    int top() const;
    void pop();
    void show_content() const;
};

HEAP::HEAP(int size){
    data = new int[size + 1];
    reserved_size = size;
    cur_size = 0;
    data[0] = -1;
}

void HEAP::push( int value ) {
    //插入时排序
    if(cur_size == reserved_size)  return ;
    int i = ++cur_size;
    for(; i > 1 && value < data[i / 2]; i /= 2) {
        data[i] = data[i / 2];
    }
    data[i] = value;
}

int HEAP::top() const {
    //最顶端为最小值
    return data[1];
}

void HEAP::pop() {
    //删除即删除第一个元素，先将最后一个元素放在第一位，然后排序
    if(cur_size == 0) return ;
    data[1] = data[cur_size--];
    int parent, child;
    for( parent = 1; parent * 2 <= cur_size; parent = child) {
        child = parent * 2;
        if(child + 1 <= cur_size) {
            child = data[child] < data[child + 1] ? child : child + 1;
        }
        if(data[parent] < data[child])  break;
        swap(data[child], data[parent]);
    }
}

void HEAP::show_content() const {
    for(int i = 0; i <= cur_size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    HEAP h(n * 2);
    for( int i=0; i<n; ++i ) {
        int a;
        cin >> a;
        h.push(a);
    }
    h.show_content( );
    cin >> n;
    for( int i=0; i<n; ++i ) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
    h.show_content( );
    cout << endl;
    return 0;
} 