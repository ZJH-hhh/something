typedef struct PageHeaderData{//��ͷ��Ϣ
	int start_special;
	int lower;//���п�ʼλ��
	int upper;//���н���λ��
	int table_id;
}PHD;

typedef struct Item{//������ͷ����Ϣ
	int begin_data_location;//��ʼλ��
	int length_data;//�������
}ITEM;

typedef struct TupleData{
	int num_Tuple;
	int empty[3];
}TD;

typedef struct Student{
	int sno;
	char sname[20];
	int cno;
}STU;

typedef struct Special{
	int other;
}SPE;

typedef struct pg_class{
	char table_name[20];
	int table_id;
	int num_att;
}PC;

typedef struct pg_attribute{
	int table_id;
	char att_name[20];
	char att_type[20];
	int length;
	int location;
	int empty;
}PA;

typedef struct Page{
	PHD phd;
	ITEM item;
	TD td;
	STU stu;
	SPE spe;
	PC pgclass;
	PA pgatt;
}PAGE;

typedef struct Filter{
	char att_name[20];
	char cmp;
	int value;
}FT;

struct Data{
    int sno;
    int cno;
    char sname[20];

    bool operator< (const Data &t) const{
        if (cno != t.cno) return cno < t.cno;
        return sno < t.sno;
    }
};