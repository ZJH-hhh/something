#include"stdio.h"
#include"string.h"
#include"iostream"
using namespace std;

#define BlockSize 8192  //���С
#define Special 32      //����32�ֽ����ڱ���޸�
#define MaxSize 10      //ѧ������
int TableId = 0;//��id��Ϊȫ�ֱ���



/*-----------------��ͷ��Ϣ�ṹ��---------------*/
typedef struct PageHeaderData {
	string TableName;//����
	int overage;    //��ʣ��ռ�
	int Start;      //��ʼ�����λ��
}PHD;


/*------------ѧ����Ϣ�ṹ��-------------------*/
typedef struct TupleData {
	int StuNum;
	string StuName;
	int StuClassNUm;
}TD;

PHD* InitBlock() {
	//��Ĵ����Լ���ʼ��
	PHD* head = (PHD*)malloc(BlockSize);//������ͷָ��
	memset(head, 0, BlockSize);         //��ʼ��Ϊ0
	head->overage = BlockSize - Special;//ʣ����ÿռ�
	head->Start = 0;       //���ݲ�����ʼλ��Ϊ��ͷ
	TableId++;        //��id��һ
	return head;      //���ؿ�ͷָ��
}

TD* InPut() {
	//ѧ����Ϣ����
	TD* s = (TD*)malloc(sizeof(TD));
	cin >> s->StuClassNUm;
	cin >> s->StuName;
	cin >> s->StuNum;
	return s;
}

void Insert(TD* S, FILE* fp) {
	//���뵽��
	fwrite(S, sizeof(TD), 1, fp);//д���ļ�
}

int main()
{
	PHD* head1 = InitBlock();//�����¿�
	TD* S[MaxSize];
	for (int i = 0; i < MaxSize; i++) {
		S[i] = InPut();
	}
	FILE* fp = fopen("stu.txt", "a+");//�Լӷ�ʽ����һ���ı��ļ�
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
