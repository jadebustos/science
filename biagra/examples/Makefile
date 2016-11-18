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
	$(CC) polynomial-derivativePol.c polsupport.o -o polynomial-derivativePol -lbiagra
	$(CC) polynomial-addPol.c polsupport.o -o polynomial-addPol -lbiagra
	$(CC) polynomial-subtractPol.c polsupport.o -o polynomial-subtractPol -lbiagra
	$(CC) polynomial-newtonPol.c polsupport.o -o polynomial-newtonPol -lbiagra

complex:
	$(CC) complex-addComplex.c -o complex-addComplex -lbiagra -lm
	$(CC) complex-subtractComplex.c -o complex-subtractComplex -lbiagra -lm
	$(CC) complex-multiplyComplex.c -o complex-multiplyComplex -lbiagra -lm
	$(CC) complex-divideComplex.c -o complex-divideComplex -lbiagra -lm
	$(CC) complex-dblComplexModulus.c -o complex-dblComplexModulus -lbiagra -lm
	$(CC) complex-dblComplexArg.c -o complex-dblComplexArg -lbiagra -lm
	$(CC) complex-conjugateComplex.c -o complex-conjugateComplex -lbiagra -lm
	$(CC) complex-complex2Polar.c -o complex-complex2Polar -lbiagra -lm
	$(CC) complex-polar2Complex.c -o complex-polar2Complex -lbiagra -lm

polsupport.o:
	$(CC) -c polsupport.c -o polsupport.o

all:
	make datapol
	make datamatrix
	make resmem
	make polynomial
	make complex

clean:
	rm -f *.o *~
