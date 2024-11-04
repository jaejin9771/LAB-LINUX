libcalculator.so.1.0.1 : add.o subtract.o multiply.o divide.o
		gcc -shared -Wl,-soname,libcalculator.so.1 -o libcalculator.so.1.0.1 add.o subtract.o multiply.o divide.o
		ln -s libcalculator.so.1.0.1 libcalculator.so.1
		ln -s libcalculator.so.1.0.1 libcalculator.so
shared_exam : main.o
		gcc -I. -L. main.c -Wl,--rpath=/home/jaejin/lab2/exam1/lib -lcalculator -o shared_exam
add.o : add.c
		gcc -fPIC -c add.c
subtract.o : subtract.c
		gcc -fPIC -c subtract.c
multiply.o : multiply.c
		gcc -fPIC -c multiply.c
divide.o : divide.c
		gcc -fPIC -c divide.c
main.o : main.c
		gcc -fPIC -c main.c
clean :
		rm -f shared_exam libcalculator.so.1.0.1 libcalculator.so.1 libcalculator.so add.o subtract.o multiply.o divide.o main.o
		