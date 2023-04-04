#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_ID = 100;

int tableid;
bool st[MAX_ID]; // 用来判断id重复

struct pg_class{
	string table_name;
	int table_id;
	int cnt_col;
};

struct pg_attribute{
	int table_id;
	string col_name;
	string col_type;
	int len;
	int pos;
	bool empty;
};

void InsertPg_class(string TableName){
	FILE *fp;
	fp = fopen("TableName", "a+");
	fclose(fp);
	char *page = (char*)malloc(8192);
	
	fp = fopen("TableName", "rb+");
	int num = 0;
	while(fread(page, 8192, 1, fp) == 1) num ++ ;
	fwrite((char*)page, 8192, 1, fp);
}

void InsertPg_att(pg_attribute t, string s[], int flag[], string TableName){
	FILE *fp;
	fp = fopen("TableName", "a+");
	fclose(fp);
	char *page = (char*)malloc(8192);
	
	fp = fopen("TableName", "rb+");
	int num = 0;
	while(fread(page, 8192, 1, fp) == 1) num ++ ;
	fwrite((char*)page, 8192, 1, fp);
}

void create(string table_name, pg_attribute pg[]){
	pg_class values = {"pg_class", 1259, 3};
	pg_attribute value = {1249, "table_id", "int", 4, 1, false};
	int flag[6] = {1, 1, 1, 1 ,1 ,1};

	if (st[tableid]){
		// 表名重复
		cout << "table_name is exist\n";
		return ;
	}

	values.table_name = table_name;
	values.table_id = tableid;
	st[tableid] = true;
	values.cnt_col = 4;
	string name = "1259";
	InsertPg_class(values, "table_name, table_id, cnt_col", flag, name);

	for (int i = 0; i < 4; i ++ ){
		pg[i].table_id = tableid;
		value.table_id = tableid;
		value.col_name = pg[i].col_name;
		value.col_type = pg[i].col_type;
		value.len = pg[i].len;
		value.pos = pg[i].pos;
		value.empty = pg[i].empty;
		InsertPg_att(value, "table_id, col_name, col_type, len, pos, empty", flag, "1249");
	}
	tableid ++ ;
}

void ShowPg_class(){
	FILE *fp;
	printf("                pg_class information                \n");
	printf("     table_name         table_id         sum_type\n");
	char *p = (char*)malloc(8192);
	string table_id = "1259";
	fp = fopen(table_id, "rb");
	while (fread(p, 8192, 1, fp) == 1){
		int num = 0;
		while (num < 8192 - 20){
			for (auto t: pg_class)
				cout << t << ' ';
		}
		num += sizeof(pg_class);
	}
}

void ShowPg_att(){
	FILE *fp;
	printf("                pg_attribute information                \n");
	printf("  table_id  col_name   col_type   len  pos  empty\n");
	char *p = (char*)malloc(8192);
	string table_id = "1259";
	fp = fopen(table_id, "rb");
	while (fread(p, 8192, 1, fp) == 1){
		int num = 0;
		while (num < 8192 - 20){
			for (auto t: pg_attribute)
				cout << t << ' ';
		}
		num += sizeof(pg_attribute);
	}
}

int main()
{
	pg_class values = {"pg_class", 1259, 3};
	pg_attribute value = {1249, "table_id", "int", 4, 1, false};
	pg_attribute pg[4];
	int flag[6] = {1, 1, 1, 1, 1, 1}, tag[4] = {1, 1, 1, 1};
	string TableName = "1259";
	InsertPg_class(values, "table_name, table_id, cnt_col", tag, TableName);

	return 0;
}