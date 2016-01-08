CC=gcc

# 環境によってMakefileを書き換える部分
# ifeq(\$(SO),Windows_NT)
# LFLAGS=-lncurses
# else
# UNAME=(\$(UNAME),Linux)
LFLAGS=-lncursesw
CFLAGS=

PROGRAM=test_win
OBJS=test_win.o

all: $(PROGRAM) sample_win

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $^ $(LFLAGS)

sample_win: sample_win.o
	$(CC) -o $@ $^ $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM) sample_win
