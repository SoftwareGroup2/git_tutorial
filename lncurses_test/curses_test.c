#include <ncurses.h>
#include <locale.h>

int main(void){
    // この宣言をinitscrより上で実行する。
    setlocale(LC_ALL,"");

    // 初期化
    initscr();
    // 入力に関する設定
    noecho();               // 入力した文字を画面に出力させない
    keypad(stdscr, true);   // キーボード入力を有効
    wtimeout(stdscr, 100);  // 100ミリ秒でgetchをタイムアウ
    cbreak();

    // qが入力されるまで待機
    while (getch() != 'q'){
        mvprintw(10,10,"あああ");
        refresh();
    }

    // 終了
    endwin();

    return 0;
}
