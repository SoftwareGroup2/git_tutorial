CC=gcc

LFLAGS=-lncursesw
CFLAGS=

PROGRAM=test_window2
OBJS=test_window2.o

all: $(PROGRAM) sample_win

$(PROGRAM): $(OBJS)
	LANG=ja-JP.utf-8
	$(CC) -o $(PROGRAM) $^ $(LFLAGS)

sample_win: sample_win.o
	$(CC) -o $@ $^ $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAM) sample_win
