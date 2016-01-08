#include <curses.h>
#include <locale.h>

int main(void){
    WINDOW *win1, *win2;
    char c;
    /* 初期化 */
    setlocale(LC_ALL,"");
    initscr();
    /* エコー／バッファリング禁止 */
    noecho();
    cbreak();

    /* ウィンドウ作成 */
    win1 = newwin(LINES/2,COLS-1,0,0);
    win2 = newwin(LINES/2+1,COLS-1,LINES/2,0);

    box(win1,'|','-');
    box(win2,'|','-');


    /* メッセージ描画 */
    mvwaddstr(win1,1,3,"サンプルプログラム");
    mvwaddstr(win1,3,3,"    CODE :");
    mvwaddstr(win1,5,3,"   HITKEY:");
    mvwaddstr(win1,7,3,"   END:ESC");
    wrefresh(win1);

    mvwaddstr(win2,1,3,"サンプルプログラム");
    mvwaddstr(win2,3,3,"    CODE :");
    mvwaddstr(win2,5,3,"   HITKEY:");
    mvwaddstr(win2,7,3,"   END:ESC");
    wrefresh(win2);

    int cnt=0;
    while((c = wgetch(win1)) != 0x1b){
        char buff[36];

        sprintf(buff,"%02X",c);

        if (cnt%2==0){
            mvwaddstr(win1,3,14,buff);
            mvwaddch(win1,5,14,c);
            wrefresh(win1);
        }else{
            mvwaddstr(win2,3,14,buff);
            mvwaddch(win2,5,14,c);
            wrefresh(win2);
        }
        cnt++;
    }
    /* 後処理 */
    wclear(win1);
    wrefresh(win1);
    wclear(win2);
    wrefresh(win2);
    endwin();

}
