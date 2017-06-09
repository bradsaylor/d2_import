all:
	gcc d2.c -o d2

clean:
	@ rm *.exe 2> /dev/null || echo > /dev/null
	@ rm *~ 2> /dev/null || echo > /dev/null
	@ rm *#* 2> /dev/null || echo > /dev/null
	@ rm *.o 2> /dev/null || echo > /dev/null
