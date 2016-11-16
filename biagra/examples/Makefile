CC=gcc

datapol:
	$(CC) datapol-biaRealPol.c -o datapol-biaRealPol

datamatrix:
	$(CC) datamatrix-biaMatrix.c -o datamatrix-biaMatrix

resmem:
	$(CC) resmem-dblPtMemAllocVec.c -o resmem-dblPtMemAllocVec -lbiagra
	$(CC) resmem-dblPtMemAllocMat.c -o resmem-dblPtMemAllocMat -lbiagra
	$(CC) resmem-dblPtMemAllocUpperTrMat.c -o resmem-dblPtMemAllocUpperTrMat -lbiagra
	$(CC) resmem-dblPtMemAllocLowerTrMat.c -o resmem-dblPtMemAllocLowerTrMat -lbiagra

all:
	make datapol
	make datamatrix
	make resmem

clean:
	rm -f *.o *~
