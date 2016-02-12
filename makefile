OBJS = EC.o test.o rtl_point.o
CC = clang++
DEBUG = -g
BST = -I ~/boost_1_60_0
CFLAGS = -Wall -std=c++11 -stdlib=libc++ -c $(DEBUG) $(BST)
LFLAGS = -Wall $(DEBUG) $(BST)

out : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o out

EC.o : EC.cpp EC.h
	$(CC) $(CFLAGS) EC.cpp

test.o : test.cpp
	$(CC) $(CFLAGS) test.cpp

rtl_point.o : rtl_point.cpp rtl_point.h
	$(CC) $(CFLAGS) rtl_point.cpp

clean : 
	\rm *.o out
