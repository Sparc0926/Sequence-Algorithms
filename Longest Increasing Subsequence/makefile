ALG = LongestIncreasingSubsequence

LIS = -D NAIVE# replace with an algorithm name or COMPARE
IsIn = -D NAIVE# replace with an algorithm name or COMPARE

#--------------------------------#
# Do not modify below this line! #
#--------------------------------#
CC = gcc
CFLAGS = -I .. -Wall -Werror -O2

all: a.exe cleanO
	
a.exe: main.o $(ALG).o
	@ $(CC) $(CFLAGS) $^ -o a.exe

main.o:
	@ $(CC) $(CFLAGS) -c main.c -o $@

$(ALG).o: $(ALG).s
	@ $(CC) $($(ALG)) $(CFLAGS) -c $^ -o $@

$(ALG).s:
	@ $(CC) $($(ALG)) $(CFLAGS) -S $(ALG).c -o $@

cleanO:
	@ del *.o

cleanS:
	@ del *.s

clean: cleanS cleanO
	@ del a.exe