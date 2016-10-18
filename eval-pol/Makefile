CC=gcc

eval-pol:
	$(CC) eval-pol.c -o eval-pol.bin -lm

eval-pol-opt:
	$(CC) eval-pol-opt.c -o eval-pol-opt.bin

eval-pol-opt-rec:
	$(CC) eval-pol-opt-rec.c -o eval-pol-opt-rec.bin

all:
	make eval-pol
	make eval-pol-opt
	make eval-pol-opt-rec

clean:
	rm -f *.bin *.dat
