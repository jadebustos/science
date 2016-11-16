CC=gcc

datapol: polsupport.o
	$(CC) datapol-biaRealPol.c polsupport.o -o datapol-biaRealPol -lbiagra

datamatrix:
	$(CC) datamatrix-biaMatrix.c -o datamatrix-biaMatrix

resmem:
	$(CC) resmem-dblPtMemAllocVec.c -o resmem-dblPtMemAllocVec -lbiagra
	$(CC) resmem-dblPtMemAllocMat.c -o resmem-dblPtMemAllocMat -lbiagra
	$(CC) resmem-dblPtMemAllocUpperTrMat.c -o resmem-dblPtMemAllocUpperTrMat -lbiagra
	$(CC) resmem-dblPtMemAllocLowerTrMat.c -o resmem-dblPtMemAllocLowerTrMat -lbiagra

polynomial: polsupport.o
	$(CC) polynomial-dblEvaluatePol.c polsupport.o -o polynomial-dblEvaluatePol -lbiagra

polsupport.o:
	$(CC) -c polsupport.c -o polsupport.o

all:
	make datapol
	make datamatrix
	make resmem

clean:
	rm -f *.o *~
