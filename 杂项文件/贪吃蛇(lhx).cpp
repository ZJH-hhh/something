/*
* 作者：李洪鑫
* 日期：2018.11.30
* 版本：1.0
*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
typedef struct Record Record;
struct Record
{
    int L;
    char name[20];
};
int X = 20, Y = 8;
int Mode = 0;
int Speed = 0;
void gotoxy(int x, int y);
void hide(void);
void menu(void);
void fun_ui(int);
void game(void);
void over(int L);
void clear(void);
void look(void);
int main(void)
{
    system("mode con cols=54 lines=25");
    system("color f0");
    hide();
    while (1)
    {
        gotoxy(0, 0);
        menu();
        fun_ui(0);
        switch (Y)
        {
        case 8:
            game();
            break;
        case 10:
            fun_ui(2);
            break;
        case 12:
            fun_ui(3);
            break;
        case 14:
            fun_ui(4);
            break;
        case 16:
            look();
            break;
        case 18:
            return 0;
            break;
        }
    }
}
void menu(void)
{
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
           "■                                                  ■\n"
           "■                                                  ■\n"
           "■                贪      吃      蛇                ■\n"
           "■                                                  ■\n"
           "■                                                  ■\n"
           "■                                                  ■\n"
           "■                                                  ■\n"
           "■                     开始游戏                     ■\n"
           "■                                                  ■\n"
           "■                     游戏模式                     ■\n"
           "■                                                  ■\n"
           "■                     修改速度                     ■\n"
           "■                                                  ■\n"
           "■                     查看帮助                     ■\n"
           "■                                                  ■\n"
           "■                     查看记录                     ■\n"
           "■                                                  ■\n"
           "■                     结束游戏                     ■\n"
           "■                                                  ■\n"
           "■                                                  ■\n"
           "■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
        "\n             上下选择 空格确定 ESC返回");
}
void fun_ui(int f)
{
    static int j;
    int i;
    int count = 0;
    int a = Mode;
    int b = Speed;
    int xy[24][2];
    char ch = 0;
    for (i = 0; i < 11; i++)
    {
        xy[i][0] = i * 2 + 16;
        xy[i][1] = 2;
    }
    xy[11][0] = 36;
    xy[11][1] = 3;
    for (i = 12; i < 23; i++)
    {
        xy[i][0] = 60 - i * 2;
        xy[i][1] = 4;
    }
    xy[23][0] = 16;
    xy[23][1] = 3;
    for (;; j = (j + 1) % 24)
    {
        gotoxy(xy[j][0], xy[j][1]);
        printf("■");
        gotoxy(xy[(j + 18) % 24][0], xy[(j + 18) % 24][1]);
        printf("  ");
        Sleep(15);
        if (f == 0)
        {
            if (kbhit())
            {
                ch = getch();
                if (ch == -32)
                {
                    ch = getch();
                    if (ch == 72 || ch == 80)
                    {
                        gotoxy(X, Y);
                        printf("  ");
                        gotoxy(X + 12, Y);
                        printf("  ");
                    }
                    if (ch == 72)
                    {
                        if (Y == 8)
                        {
                            Y = 18;
                        }
                        else
                        {
                            Y -= 2;
                        }
                    }
                    else if (ch == 80)
                    {
                        if (Y == 18)
                        {
                            Y = 8;
                        }
                        else
                        {
                            Y += 2;
                        }
                    }
                }
            }
            gotoxy(X, Y);
            printf(">>");
            gotoxy(X + 12, Y);
            printf("<<");
            if (ch == ' ')
            {
                return;
            }
        }
        else if (f == 2)
        {
            gotoxy(23, 11);
            printf(">>%s<<", Mode % 2 ? "无边" : "经典");
            if (ch == 27)
            {
                Mode = a;
                return;
            }
            if (kbhit())
            {
                ch = getch();
                if (ch == -32)
                {
                    ch = getch();
                    if (ch == 72 || ch == 80)
                    {
                        Mode++;
                    }
                }
                else if (ch == ' ')
                {
                    a = Mode;
                }
            }
        }
        else if (f == 3)
        {
            gotoxy(24, 13);
            printf(">>%s<<", Speed == 0 ? "慢" : Speed == 1 ? "中" : "快");
            if (ch == 27)
            {
                Speed = b;
                return;
            }
            if (kbhit())
            {
                ch = getch();
                if (ch == -32)
                {
                    ch = getch();
                    if (ch == 72)
                    {
                        Speed = (Speed + 2) % 3;
                    }
                    else if (ch == 80)
                    {
                        Speed = (Speed + 1) % 3;
                    }
                }
                else if (ch == ' ')
                {
                    b = Speed;
                }
            }
        }
        else if (f == 4)
        {
            if (count++ == 0)
            {
                int i;
                for (i = 0; i < 14; i++)
                {
                    gotoxy(20, i + 5);
                    printf("              ");
                }
                gotoxy(23, 10);
                printf("有空再写");
            }
            if (kbhit())
            {
                ch = getch();
                if (ch == 27)
                {
                    return;
                }
            }
        }
    }
}
void look(void)
{
    Record *record = NULL;
    int count, i, j, mid;
    FILE *pfile = NULL;
    char pname[20] = "test.bin",
        Name[20];
    clear();
    pfile = fopen(pname, "rb");
    for (count = 1; pfile != NULL && count < 19; count++)
    {
        if (count == 1)
        {
            record = (Record *)malloc(sizeof(Record));
        }
        else
        {
            record = (Record *)realloc(record, count * sizeof(Record));
        }

        if (fread(record[count - 1].name, sizeof(char), 20, pfile))
        {
            fread(&(record[count - 1].L), sizeof(int), 1, pfile);
        }
        else
        {
            break;
        }
    }
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count - 1; j++)
        {
            if (record[j].L > record[i].L)
            {
                mid = record[j].L;
                record[j].L = record[i].L;
                record[i].L = mid;
                strcpy(Name, record[j].name);
                strcpy(record[j].name, record[i].name);
                strcpy(record[i].name, Name);
            }
        }
    }
    for (i = 0; i < count - 1; i++)
    {
        gotoxy(17, i + 1);
        printf("第%d名：%s--%d分", i + 1, record[i].name, record[i].L);
    }
    fclose(pfile);
    while (27 != getch());
}
void clear(void)
{
    int i;
    for (i = 1; i <= 20; i++)
    {
        gotoxy(2, i);
        printf("                                                  ");
    }
}
void gotoxy(int x, int y)
{
    COORD coord; HANDLE hscr;
    coord.X = x;
    coord.Y = y;
    hscr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hscr, coord);
}
void hide(void)
{
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void game(void)
{
    int i;
    char ch = 75, mid;
    int x, y, k, bool_ = 1;
    int L = 0, head = 0, t = 90;
    int a[500][2] = { 0 };
    srand(time(NULL));
    clear();
    gotoxy(5, 16);
    printf("载入中......");
    Sleep(700);
    gotoxy(5, 17);
    for (i = 0; i < 22; i++)
    {
        printf("■");
        Sleep(50);
    }
    Sleep(500);
    clear();

    gotoxy(a[0][0] = 20, a[0][1] = 10);
    printf("■");
    while (1)
    {
        while (bool_++)
        {
            x = rand() % 49 + 2;
            y = rand() % 20 + 1;
            for (bool_ = 0, k = 0; k < 500; k++)
            {
                if (x % 2 || (x == a[k][0] && y == a[k][1]))
                    bool_ = 1;
            }
        }
        L++;
        gotoxy(x, y);
        printf("□");
        while (a[head][0] != x || a[head][1] != y)
        {
            Sleep(t + (2 - Speed) * 30);
            t = 90;
            if (kbhit())
            {
                mid = getch();
                if (mid == -32)
                {
                    mid = getch();
                    if ((mid == 72 && ch != 80) || (mid == 80 && ch != 72)
                        || (mid == 75 && ch != 77) || (mid == 77 && ch != 75))
                    {
                        if (mid == ch)
                            t -= 50;
                        ch = mid;
                    }
                }
            }
            switch (ch)
            {
            case 72:
                if (Mode % 2)
                {
                    if (a[head][1] == 1)
                    {
                        a[(head + 1) % 500][1] = 20;
                    }
                    else
                    {
                        a[(head + 1) % 500][1] = a[head][1] - 1;
                    }
                }
                else
                {
                    if (a[head][1] == 1)
                    {
                        over(L);
                        return;
                    }
                    a[(head + 1) % 500][1] = a[head][1] - 1;
                }
                a[(head + 1) % 500][0] = a[head][0];
                break;
            case 80:
                if (Mode % 2)
                {
                    if (a[head][1] == 20)
                    {
                        a[(head + 1) % 500][1] = 1;
                    }
                    else
                    {
                        a[(head + 1) % 500][1] = a[head][1] + 1;
                    }
                }
                else
                {
                    if (a[head][1] == 20)
                    {
                        over(L);
                        return;
                    }
                    a[(head + 1) % 500][1] = a[head][1] + 1;
                }
                a[(head + 1) % 500][0] = a[head][0];
                break;
            case 75:
                if (Mode % 2)
                {
                    if (a[head][0] == 2)
                    {
                        a[(head + 1) % 500][0] = 50;
                    }
                    else
                    {
                        a[(head + 1) % 500][0] = a[head][0] - 2;
                    }
                }
                else
                {
                    if (a[head][0] == 2)
                    {
                        over(L);
                        return;
                    }
                    a[(head + 1) % 500][0] = a[head][0] - 2;
                }
                a[(head + 1) % 500][1] = a[head][1];
                break;
            case 77:
                if (Mode % 2)
                {
                    if (a[head][0] == 50)
                    {
                        a[(head + 1) % 500][0] = 2;
                    }
                    else
                    {
                        a[(head + 1) % 500][0] = a[head][0] + 2;
                    }
                }
                else
                {
                    if (a[head][0] == 50)
                    {
                        over(L);
                        return;
                    }
                    a[(head + 1) % 500][0] = a[head][0] + 2;
                }
                a[(head + 1) % 500][1] = a[head][1];
                break;
            }
            head = (head + 1) % 500;
            if (a[(head + 500 - L) % 500][0])
            {
                gotoxy(a[(head + 500 - L) % 500][0], a[(head + 500 - L) % 500][1]);
                printf("  ");
            }
            gotoxy(a[head][0], a[head][1]);
            printf("■");
            for (i = 1; i < L; i++)
            {
                if (a[(head - i + 500) % 500][0] == a[head][0] && 
a[(head - i + 500) % 500][1] == a[head][1])
                {
                    over(L);
                    return;
                }
            }
        }
    }
}
void over(int L)
{
    FILE *pfile = NULL;
    char pname[20] = "test.bin", name[20];
    Sleep(1000);
    clear();
    gotoxy(23, 10);
    printf("游戏结束！");
    gotoxy(22, 11);
    printf("共吃了%d块！", --L);
    gotoxy(18, 15);
    printf("请输入姓名以记录：");
    gotoxy(23, 16);
    fflush(stdin);
    scanf("%s", name);

    pfile = fopen(pname, "ab+");
    fwrite(name, sizeof(char), 20, pfile);
    fwrite(&L, sizeof(int), 1, pfile);
    fclose(pfile);
    Sleep(1000);
}


