CC=gcc
flag=-o

compile : 
	$(CC) $(flag) multi-pad-cipher multi-pad-cipher.c 

rm :
	rm -rf multi-pad-cipher