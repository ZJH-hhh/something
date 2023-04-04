#include"stdio.h"
#include"string.h"
#include"iostream"
using namespace std;

#define BlockSize 8192  //块大小
#define Special 32      //分配32字节用于表的修改
#define MaxSize 10      //学生人数
int TableId = 0;//表id设为全局变量



/*-----------------块头信息结构体---------------*/
typedef struct PageHeaderData {
	string TableName;//表名
	int overage;    //表剩余空间
	int Start;      //开始插入的位置
}PHD;


/*------------学生信息结构体-------------------*/
typedef struct TupleData {
	int StuNum;
	string StuName;
	int StuClassNUm;
}TD;

PHD* InitBlock() {
	//块的创建以及初始化
	PHD* head = (PHD*)malloc(BlockSize);//创建块头指针
	memset(head, 0, BlockSize);         //初始化为0
	head->overage = BlockSize - Special;//剩余可用空间
	head->Start = 0;       //数据插入起始位置为块头
	TableId++;        //表id加一
	return head;      //返回块头指针
}

TD* InPut() {
	//学生信息输入
	TD* s = (TD*)malloc(sizeof(TD));
	cin >> s->StuClassNUm;
	cin >> s->StuName;
	cin >> s->StuNum;
	return s;
}

void Insert(TD* S, FILE* fp) {
	//插入到块
	fwrite(S, sizeof(TD), 1, fp);//写入文件
}

int main()
{
	PHD* head1 = InitBlock();//创建新块
	TD* S[MaxSize];
	for (int i = 0; i < MaxSize; i++) {
		S[i] = InPut();
	}
	FILE* fp = fopen("stu.txt", "a+");//以加方式创建一个文本文件
	if (!fp) {
		exit(0);
	}
	else {
		for (int i = 0; i < MaxSize; i++) {
			Insert(S[i], fp);
		}
	}
	fclose(fp);
}
