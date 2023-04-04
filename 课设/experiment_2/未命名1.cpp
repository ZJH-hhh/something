#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct PageHeaderData{//块头信息
	int start_special;
	int lower;//空闲开始位置
	int upper;//空闲结束位置
	int tableid;
}PHD;

typedef struct Item{//数据项头部信息
	int begin_data_location;//开始位置
	int length_data;//数据项长度
}ITEM;

typedef struct TupleData{//元组信息结构体
	int num_Tuple;//属性数量
	int is_empty[3];//元组属性是否非空
}TD;

typedef struct Student{
	int sno;
	char sname[5];
	int cno;
}STU;

typedef struct Special{
	int other;
}SPE;

typedef struct pg_class{
	char tablename[20];
	int tableid;
	int num_att;
}PGCLASS;

typedef struct pg_attribute{
	int tableid;
	char name_att[20];
	char type_att[20];
	int length;
	int location;
	int is_empty;
}PGATT;

typedef struct Page{
	PHD phd;
	ITEM item;
	TD td;
	STU stu;
	SPE spe;
	PGCLASS pgclass;
	PGATT pgatt;
}PAGE;

void extend(PAGE *page)
{
	page->phd.lower = sizeof(struct PageHeaderData);
	page->phd.start_special = sizeof(struct PageHeaderData)-sizeof(struct Special);
	page->phd.upper = page->phd.start_special;
	
};

void show(int tableid)
{
	FILE *fp;
	PAGE *page = (PAGE*)malloc(8192);
	char filename[50];
	sprintf(filename, "C:\\test\\%d.dat", tableid);
	fp = fopen(filename, "rb");
	if(fp==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		while (fread(page, 8192, 1, fp))
		{
			printf("%5d\t%5d\t%5s\n",page->stu.sno,page->stu.cno,page->stu.sname);
		}
	}
	fclose(fp);
	free(page);
};
void show_pg_class()
{
	FILE *fp;
	PAGE *page = (PAGE*)malloc(8192);
	char filename[50];
	sprintf(filename, "C:\\test\\%d.dat", 1259);
	fp = fopen(filename, "rb");
	printf("pg_class shows\ntablename\ttableid\tnum_att\t\n");
	if(fp==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		while (fread(page, 8192, 1, fp))
		{
			printf("%5s\t%5d\t%5d\n",page->pgclass.tablename,page->pgclass.tableid,page->pgclass.num_att);
		}
	}
	fclose(fp);
	free(page);
}

void show_pg_att()
{
	FILE *fp;
	PAGE *page = (PAGE*)malloc(8192);
	char filename[50];
	sprintf(filename, "C:\\test\\%d.dat", 1249);
	fp = fopen(filename, "rb");
	printf("pg_attribute shows\ntableid\tname_att\ttype_att\tlength\tlocation\tis_empty\t\n");
	if(fp==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		while (fread(page, 8192, 1, fp))
		{
			printf("%5d\t%5s\t%5s\t%5d\t%5d\t%5d\n",page->pgatt.tableid,page->pgatt.name_att,page->pgatt.type_att,page->pgatt.length,page->pgatt.location,page->pgatt.is_empty);
		}
	}
	fclose(fp);
	free(page);
}

void insert(STU insert_Data,char type_insert[][5],int is_empty[3],int tableid)
{
	int i,j;	
	FILE *fp;
	PAGE *page = (PAGE*)malloc(8192);
	char filename[50];
	sprintf(filename, "C:\\test\\%d.dat", tableid);
	fp = fopen(filename, "ab+");
	if(fp==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		fseek(fp, -8192, SEEK_END);
		if (!fread(page, 8192, 1, fp))
			extend(page);
		if((page->phd.upper - page->phd.lower) < (sizeof(struct Student) + sizeof(struct Item)))
		{
			extend(page);
			fread(page, 8192, 1, fp);
		}
		for(i=0;i<3;i++)
		{
			page->td.is_empty[i]=is_empty[i];
		}
		if(page->td.is_empty[0]==1)
		{
			page->stu.sno = insert_Data.sno;
		}
		if(page->td.is_empty[1]==1)
		{
			for(j=0;j<5;j++)
			{
				page->stu.sname[j]=insert_Data.sname[j];
			}
		}
		if(page->td.is_empty[2]==1)
		{
			page->stu.cno=insert_Data.cno;
		}
		page->spe.other = 0;
		page->phd.tableid= tableid;
		page->item.length_data = sizeof(struct Student);
		page->td.num_Tuple = 3;
		page->phd.upper -= sizeof(struct Student);
		page->phd.lower += sizeof(struct Item);
		page->item.begin_data_location = page->phd.upper;
		fseek(fp, -8192, SEEK_END);
		fwrite(page, 8192, 1, fp);
	}
	free(page);
	fclose(fp);

	//printf("%5d%5d%5s\n",insert_Data.cno,insert_Data.sno,insert_Data.sname);
};

void insert_pg_class(PGCLASS insert_data,char type_insert[][5],int is_empty[3],char tablename[20])
{
	int i,j;
	FILE *fp;
	PAGE *page = (PAGE*)malloc(8192);
	char filename[50];
	sprintf(filename, "C:\\test\\%d.dat", 1259);
	fp=fopen(filename,"ab+");
	if(fp==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		fseek(fp, -8192, SEEK_END);
		if (!fread(page, 8192, 1, fp))
			extend(page);
		if(page->phd.upper - page->phd.lower < sizeof(struct pg_class) + sizeof(struct Item))
		{
			extend(page);
			fread(page, 8192, 1, fp);
		}
		for(i=0;i<3;i++)
		{
			page->td.is_empty[i]=is_empty[i];
		}
		if(page->td.is_empty[0]==1)
		{
			for(j=0;j<20;j++)
			{
				page->pgclass.tablename[j]=insert_data.tablename[j];
			}
		}
		if(page->td.is_empty[1]==1)
		{
			page->pgclass.tableid=insert_data.tableid;
		}
		if(page->td.is_empty[2]==1)
		{
			page->pgclass.num_att=insert_data.num_att;
		}
		page->spe.other = 0;
		page->phd.tableid= 1259;
		page->item.length_data = sizeof(struct pg_class);
		page->td.num_Tuple = 3;
		page->phd.upper -= sizeof(struct pg_class);
		page->phd.lower += sizeof(struct Item);
		page->item.begin_data_location = page->phd.upper;
		fseek(fp, -8192, SEEK_END);
		fwrite(page, 8192, 1, fp);
	}
	free(page);
	fclose(fp);
};

void insert_pg_att(PGATT insert_data,int is_empty[6])
{
	int i,j;
	FILE *fp;
	PAGE *page = (PAGE*)malloc(8192);
	char filename[50];
	sprintf(filename, "C:\\test\\%d.dat", 1249);
	fp=fopen(filename,"ab+");
	if(fp==NULL)
	{
		printf("error\n");
		exit(0);
	}
	else
	{
		fseek(fp, -8192, SEEK_END);
		if (!fread(page, 8192, 1, fp))
			extend(page);
		if(page->phd.upper - page->phd.lower < sizeof(struct pg_attribute) + sizeof(struct Item))
		{
			extend(page);
			fread(page, 8192, 1, fp);
		}
		for(i=0;i<6;i++)
		{
			page->td.is_empty[i]=is_empty[i];
		}
		if(page->td.is_empty[0]==1)
		{
			page->pgatt.tableid=insert_data.tableid;
		}
		if(page->td.is_empty[1]==1)
		{
			for(j=0;j<20;j++)
			{
				page->pgatt.name_att[j]=insert_data.name_att[j];
			}
		}
		if(page->td.is_empty[2]==1)
		{
			for(j=0;j<5;j++)
			{
				page->pgatt.type_att[j]=insert_data.type_att[j];
			}
		}
		if(page->td.is_empty[3]==1)
		{
			page->pgatt.length=insert_data.length;
		}
		if(page->td.is_empty[4]==1)
		{
			page->pgatt.location=insert_data.location;
		}
		if(page->td.is_empty[5]==1)
		{
			page->pgatt.is_empty=1;
		}
		page->spe.other = 0;
		page->phd.tableid= 1249;
		page->item.length_data = sizeof(struct pg_attribute);
		page->td.num_Tuple = 3;
		page->phd.upper -= sizeof(struct pg_attribute);
		page->phd.lower += sizeof(struct Item);
		page->item.begin_data_location = page->phd.upper;
		fseek(fp, -8192, SEEK_END);
		fwrite(page, 8192, 1, fp);
	}
	free(page);
	fclose(fp);
};

void data()
{
	PGCLASS pgclass_pgc={"pg_class",1259,3};
	PGCLASS pgclass_pga={"pg_attribute",1249,6};
    PGATT class_tablename={1259,"tablename","char",sizeof(pgclass_pgc.tablename),1,1};
	PGATT class_tableid={1259,"tableid","int",sizeof(pgclass_pgc.tableid),2,1};
	PGATT class_num_att={1259,"num_att","int",sizeof(pgclass_pgc.num_att),3,1};
	int class_is_empty[3] = { 1,1,1 };
	char classtype[3][5] = {"char","int","int"};
	int attribute_is_empty[6] = { 1,1,1,1,1,1 };
	char attributetype[6][5] = {"int","char","char","int","int","int"};
	insert_pg_class(pgclass_pgc,classtype,class_is_empty,"1259");
	insert_pg_class(pgclass_pga,attributetype,attribute_is_empty,"1249");
	insert_pg_att(class_tablename,attribute_is_empty);
	insert_pg_att(class_tableid,attribute_is_empty);
	insert_pg_att(class_num_att,attribute_is_empty);

};

void show_type(char type_insert[][5])
{
	int i;
	for(i=0;i<3;i++)
		puts(type_insert[i]);
};

void createdata(int tableid)
{
	int i,j,k,t;
	STU stu;

	int flag;
	int is_empty[3] = { 1,1,1 };
	char type[3][5] = {"int","char","int"};
	srand((unsigned)time(NULL));
	for(i=1;i<=50;i++)
	{
		stu.sno=i;
		for (k=0;k<5;k++)
		{
			flag=rand()%(5-1)+2;//随机长度2到sname_len，防止长度为1时只有\0--((sname_len+1)-2)+2//[2,sname_len+1)
			for(j=0;j<flag;j++)
			{
				stu.sname[j]=65+rand()%26;
				if (j== flag-1)stu.sname[j]='\0';//防止出现乱码
			}
			break;
		}
		stu.cno=rand()%500+1;
		insert(stu,type,is_empty,tableid);
	}
	
};
int main(){
	/*int tableid;		
	printf("请输入表的id:");
	scanf("%d", &tableid);
	createdata(tableid);
	show(tableid);*/
	data();
	show_pg_class();
	show_pg_att();
	
	return 0;
}
