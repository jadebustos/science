# $UWHPSC/codes/fortran/newton/Makefile

OBJECTS = functions.o newton.o test1.o
MODULES = functions.mod newton.mod

OBJECTS5 = functions.o newton.o intersections.o

FFLAGS = -g

.PHONY: test1 clean 

intersections: intersections.exe
	./intersections.exe

intersections.exe: $(MODULES) $(OBJECTS5)
	gfortran $(FFLAGS) $(OBJECTS5) -o intersections.exe

test1: test1.exe
	./test1.exe

test1.exe: $(MODULES) $(OBJECTS)
	gfortran $(FFLAGS) $(OBJECTS) -o test1.exe

%.o : %.f90
	gfortran $(FFLAGS) -c  $< 

%.mod: %.f90
	gfortran $(FFLAGS) -c $<

clean:
	rm -f *.o *.exe *.mod

