#include <curses.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

typedef struct player_t{
  char name[100]; // 
  int grade;              // 学年
  int club;               // 部活(帰宅部/運動部/文化部)
  int girlfriend;         // 彼女(いる/いない)
  int enhance_p;          // 充実ポイント
  int task_p;             // 課題ポイント
  int money_p;            // 金
  int day;                // 現在何日目か
}PLAYER_T;

void set(PLAYER_T p[])
{
  int i;

  for(i=0;i<4;i++){
    sprintf(p[i].name,"aaaaaaaaaa");
    p[i].grade = 1;
    p[i].club  = 1;
    p[i].girlfriend = 0;
    p[i].enhance_p = 99999;
    p[i].task_p = 99999;
    p[i].money_p = 99999;
    p[i].day = 1;
  }
}

void create_cal(WINDOW *win, int y, int x,PLAYER_T p[])
{
  int i;
  int cx,cy;

  mvwaddstr(win, y+ 0, x, "  月  |  火  |  水  |  木  |  金  |  土  |  日  ");
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

  mvwaddstr(win,1,1,"No | 名前       | 日付 | 所持金 充実p 課題p | 学年 部活 | 彼女 |");
  mvwaddstr(win,2,1,"---+------------+------+--------------------+-----------+------+");
  
  for(i=0;i<4;i++){
    //月と日
    if(p[i].day/31 == 0){
      month = 7;
      day = 20+(p[i].day-1);
    }else{
      month = 8;
      day = p[i].day-4;
    }

    //部活
    if(p[i].club == 0){
      sprintf(club,"運動");
    }else if(p[i].club == 1){
      sprintf(club,"文化");
    }else{
      sprintf(club,"帰宅");
    }

    //彼女
    if(p[i].girlfriend == 1){
      sprintf(girl,"あり");
    }else{
      sprintf(girl,"なし");
    }
    
      mvwprintw(win,3+i,1,"(%d)| %10s | %d/%2d | %6d %5d %5d | %4d %4s | %4s |",i+1,p[i].name,month,day,p[i].money_p,p[i].enhance_p,p[i].task_p,p[i].grade,club,girl); 
  }
}

int main(void){
  WINDOW *win,*cal,*ive,*info;
  char c;
  int i;
  PLAYER_T p[4];
  char str[2000];
  
  set(p);
  setlocale(LC_ALL,"");
    
  /* 初期化 */
  initscr();
  
  /* エコー／バッファリング禁止 */
  noecho();
  cbreak();

  /* 全体ウィンドウ作成 */
  win = newwin(LINES,COLS-1,0,0);
  box(win,'|','-');
  sprintf(str,"%sの夏休み",p[i].name);
  mvwaddstr(win,1,(COLS-1)/2,str);
 
  /* カレンダーウィンドウ作成 */
  cal = subwin(win,25,50,2,0);
  box(cal,'|','-');
  create_cal(cal,1,1,p);
  wrefresh(cal);

  /* イベントウィンドウ作成 */
  ive = subwin(win,25,49,2,50);
  box(ive,'|','-');
  //create_ive(ive,y,x);

  /* プレイヤー情報ウィンドウ作成 */
  info = subwin(win,8,99,27,0);
  box(info,'|','-');
  create_info(info,1,1,p);
  wrefresh(info);
    
  /* メッセージ描画 */
   
  while((c = wgetch(win)) != 0x1b){
    wrefresh(win);
  }
    
  /* 後処理 */
  wclear(win);
  wrefresh(win);
  endwin();

}
