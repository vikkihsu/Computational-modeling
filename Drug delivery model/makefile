CC = g++
CFLAGS = -Wall -std=c++11

OBJ = main.o degradation1.o degradation2.o weight.o drugrelease.o

%.o: %.cpp matrix.h final.h
	$(CC) $(CFLAGS) -c -o $@ $< 

final: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o