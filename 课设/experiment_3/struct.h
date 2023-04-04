typedef struct PageHeaderData{//块头信息
	int start_special;
	int lower;//空闲开始位置
	int upper;//空闲结束位置
	int table_id;
}PHD;

typedef struct Item{//数据项头部信息
	int begin_data_location;//开始位置
	int length_data;//数据项长度
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