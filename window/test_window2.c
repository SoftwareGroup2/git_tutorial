#include <curses.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

typedef struct trout_t{
  char content[200];
  int enhance_p;
  int task_p;
  int money_p;
  int move_day;
}TROUT_T;

typedef struct player_t{
  char name[100]; // 
  int grade;              // ��ǯ
  int club;               // ����(������/��ư��/ʸ����)
  int girlfriend;         // ���(����/���ʤ�)
  int enhance_p;          // ���¥ݥ����
  int task_p;             // ����ݥ����
  int money_p;            // ��
  int day;                // ���߲����ܤ�
  TROUT_T calender[44];
}PLAYER_T;

void set(PLAYER_T p[])
{
  int i;

  for(i=0;i<4;i++){
    sprintf(p[i].name,"aaaaa");
    p[i].grade = 1;
    p[i].club  = 1;
    p[i].girlfriend = 0;
    p[i].enhance_p = 99999;
    p[i].task_p = 99999;
    p[i].money_p = 999999;
    p[i].day = 1;
  }
}

void create_cal(WINDOW *win, int y, int x,PLAYER_T p[])
{
  int i;
  int cx,cy;

  mvwaddstr(win, y+ 0, x, "  ��  |  ��  |  ��  |  ��  |  ��  |  ��  |  ��  ");
  mvwaddstr(win, y+ 1, x, "------+------+------+------+------+------+------");
  mvwaddstr(win, y+ 2, x, "      |      |      |      |      |  7/19|  7/20");
  mvwaddstr(win, y+ 3, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+ 4, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+ 5, x, "  7/21|  7/22|  7/23|  7/24|  7/25|  7/26|  7/27");
  mvwaddstr(win, y+ 6, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+ 7, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+ 8, x, "  7/28|  7/29|  7/30|  7/31|  8/ 1|  8/ 2|  8/ 3");
  mvwaddstr(win, y+ 9, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+10, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+11, x, "  8/ 4|  8/ 5|  8/ 6|  8/ 7|  8/ 8|  8/ 9|  8/10");
  mvwaddstr(win, y+12, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+13, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+14, x, "  8/11|  8/12|  8/13|  8/14|  8/15|  8/16|  8/17");
  mvwaddstr(win, y+15, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+16, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+17, x, "  8/18|  8/19|  8/20|  8/21|  8/22|  8/23|  8/24");
  mvwaddstr(win, y+18, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+19, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+20, x, "  8/25|  8/26|  8/27|  8/28|  8/29|  8/30|  8/31");
  mvwaddstr(win, y+21, x, "      |      |      |      |      |      |      ");
  mvwaddstr(win, y+22, x, "      |      |      |      |      |      |      ");

  for(i=0;i<4;i++){
    cx = (p[i].day+4)%7 * 7 + 1;
    cy = (p[i].day+4)/7 * 3 + 4;
    switch(i+1){
      case 1 :
      break;
      case 2 :
        cx += 3;
      break;
      case 3 :
        cy += 1;
      break;
      case 4 :
        cy += 1;
        cx += 3;
      break;
    }
    mvwprintw(win, cy, cx, "(%d)",i+1);
  }
}

void create_info(WINDOW *win,int y,int x,PLAYER_T p[])
{
  int i;
  int month,day;
  char club[10],girl[10];

  mvwaddstr(win,1,1,"No | ̾��             | ���� | ����� ����p ����p | ��ǯ ���� | ��� |");
  mvwaddstr(win,2,1,"---+------------------+------+--------------------+-----------+------+");

  for(i=0;i<4;i++){
    //�����
    if(p[i].day-13 <= 0){
      month = 7;
      day = 19+(p[i].day-1);
    }else{
      month = 8;
      day = p[i].day-13;
    }

    //����
    if(p[i].club == 0){
      sprintf(club,"��ư");
    }else if(p[i].club == 1){
      sprintf(club,"ʸ��");
    }else{
      sprintf(club,"����");
    }

    //���
    if(p[i].girlfriend == 1){
      sprintf(girl,"����");
    }else{
      sprintf(girl,"�ʤ�");
    }

    mvwprintw(win,3+i,1,"(%d)| %s",i+1,p[i].name);
    mvwprintw(win,3+i,23,"| %d/%2d | %6d %5d %5d | %4d %4s | %4s |",month,day,p[i].money_p,p[i].enhance_p,p[i].task_p,p[i].grade,club,girl);
  }
}

void create_ive(WINDOW *win,int y,int x,PLAYER_T p)
{
  WINDOW *msg;
  int i,month,day;

  //�����
  if(p.day-13 <= 0){
    month = 7;
    day = 19+(p.day-1);
  }else{
    month = 8;
    day = p.day-13;
  }

  mvwprintw(win,1,18,"[%2d/%2d��ͽ��]",month,day);

  msg = subwin(win,17,48,4,51);
  wclear(msg);
  mvwprintw(msg,1,1,"%s",p.calender[p.day].content);
  wrefresh(msg);

  mvwprintw(win,19,1,"================================================");
  mvwprintw(win,20,1,"    ����p : %6d",p.calender[p.day].enhance_p);
  mvwprintw(win,21,1,"    ����p : %6d",p.calender[p.day].task_p);
  mvwprintw(win,22,1,"   ����� : %6d",p.calender[p.day].money_p);
  mvwprintw(win,23,1," ��ư���� : %6d",p.calender[p.day].move_day);
}

int main(){
  WINDOW *win;
  PLAYER_T players[4];
  int player_id = 0;
  char c;

  set(players);

  /* ����� */
  initscr();

  /* ���������Хåե���󥰶ػ� */
  noecho();
  cbreak();

  setlocale(LC_ALL,"");

  /* ���Υ�����ɥ����� */
  win = newwin(35,100,0,0);
  box(win,'|','-');

  /* ���֥�����ɥ����� */
  main_2(win,players,player_id);
  
  /* ��å��������� */
  while((c = wgetch(win)) != 0x1b){
  }

  /* ����� */
  wclear(win);
  wrefresh(win);
  endwin();

  return 0;
}

int main_2(WINDOW *win, PLAYER_T players[4], int player_id){
  WINDOW *cal,*ive,*info;
  char str[2000];

  /* ���Υ�����ɥ������ȥ� */
  sprintf(str,"[ %s�βƵ٤� ]",players[player_id].name);
  mvwaddstr(win,1,45-strlen(players[0].name)/2,str);

  /* ��������������ɥ����� */
  cal = subwin(win,25,50,2,0);
  box(cal,'|','-');
  create_cal(cal,1,1,players);
  wrefresh(cal);

  /* ���٥�ȥ�����ɥ����� */
  ive = subwin(win,25,50,2,50);
  box(ive,'|','-');
  create_ive(ive,1,1,players[player_id]);
  wrefresh(ive);

  /* �ץ쥤�䡼���󥦥���ɥ����� */
  info = subwin(win,8,100,27,0);
  box(info,'|','-');
  create_info(info,1,1,players);
  wrefresh(info);

  /* �Ǹ�����Υ�����ɥ���refresh */
  wrefresh(win);
  
}
