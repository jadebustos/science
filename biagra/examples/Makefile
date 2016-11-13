CC=gcc

datapol:
	$(CC) datapol-biaRealPol.c -o datapol-biaRealPol

datamatrix:
	$(CC) datamatrix-biaMatrix.c -o datamatrix-biaMatrix

resmem.o:
	$(CC) -c resmem.c -o resmem.o

resmem: resmem.o 
	$(CC) resmem-dblPtMemAllocVec.c resmem.o -o resmem-dblPtMemAllocVec
	$(CC) resmem-dblPtMemAllocMat.c resmem.o -o resmem-dblPtMemAllocMat
	$(CC) resmem-dblPtMemAllocUpperTrMat.c resmem.o -o resmem-dblPtMemAllocUpperTrMat

all:
	make datapol
	make datamatrix
	make resmem

clean:
	rm -f *.o
