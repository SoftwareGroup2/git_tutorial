#include<curses.h>

int main(void){
    WINDOW *win;
    char c;
    /* 初期化 */
    initscr();
    /* エコー／バッファリング禁止 */
    noecho();
    cbreak();

    /* ウィンドウ作成 */
    win = newwin(LINES,COLS-1,0,0);
    box(win,'|','-');

    /* メッセージ描画 */
    mvwaddstr(win,1,3,"SAMPLE PROGRAM");
    mvwaddstr(win,3,3,"    CODE :");
    mvwaddstr(win,5,3,"   HITKEY:");
    mvwaddstr(win,7,3,"   END:ESC");
    wrefresh(win);
    while((c = wgetch(win)) != 0x1b){
        char buff[36];

        sprintf(buff,"%02X",c);

        mvwaddstr(win,3,14,buff);
        mvwaddch(win,5,14,c);
        wrefresh(win);
    }
    /* 後処理 */
    wclear(win);
    wrefresh(win);
    endwin();

}
