CC=gcc
# ライブラリに対するオプション
# オブジェクトファイルから実行ファイルを作成するときに有効
# -l*** みたいな基本的にリンカオプション
LFLAGS=-lncurses
# コンパイル時に使うオプション
# -O3 など
CFLAGS=

PROGRAM=curses_test
OBJS=curses_test.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $^ $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM)
