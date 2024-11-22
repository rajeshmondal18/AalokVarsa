LINKLIB=-L/usr/local/lib/ -lm -lfftw3

INCLUDE=-I/usr/local/include/

#CFLAGS=-O3
CFLAGS=-g

r_z: r_z.o funcs.o
	cc $(CFLAGS) -o r_z r_z.o  funcs.o  $(LINKLIB)
	rm -f *.o *~

r_z.o:	r_z.c
	cc -c $(CFLAGS) $(INCLUDE) r_z.c $(LINKLIB)

funcs.o:	funcs.c
	cc -c $(CFLAGS) $(INCLUDE) funcs.c $(LINKLIB)


clean: 
	rm -f *.o *~
