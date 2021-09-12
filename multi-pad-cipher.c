#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*

multi touch pad

A	2	B	22
C	222	D	3
E	33	F	333
G	4	H	44
I	444	J	5
K	55	L	555
M	6	N	66
O	666	P	7
Q	77	R	777
S	7777	T	8
U	88	V	888
W	9	X	99
Y	999	Z	9999

*/
#define SIZE 6

char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char cipher[][SIZE] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};

// index find
int get_index(char Char){

	for(int index=0; index<strlen(alpha); index++){
		if(alpha[index] == Char){
			return index;
			break;
		}
	}
}

// get cipher text index
int get_cipher_index(char *cipher_string){
	for(int index=0; index<(sizeof(cipher)/SIZE); index++){
		if(strcmp(cipher_string, cipher[index]) == 0){
			return index;
			break;
		}
	}
}


// encrypt
void encrypt(char *plain_text){

	// printf("%d\n", isupper('A'));

	for(int index=0; index<strlen(plain_text); index++){
		
		// get matching cipher text 
		if(isupper(plain_text[index]) == 256 && isupper(plain_text[index]) != 0){
			printf("%s ", cipher[ get_index(plain_text[index]) ]);
		}
		else printf("%c ", plain_text[index]);
	}
	printf("\n");

}

// decrypt
void decrypt(char *cipher_text){
	char *split_string = {0};

	split_string = strtok(cipher_text, " ");
	
	while(split_string != NULL){
		printf("%c", alpha[get_cipher_index(split_string)]);
		split_string = strtok(NULL, " ");
	}
	printf("\n");

}

int main(){

	char plain_text[] = "KIDMANSPASSWORDISSOSTRANGE";
	encrypt(plain_text);

	char cipher_text[] = "55 444 3 6 2 66 7777 7 2 7777 7777 9 666 777 3 444 7777 7777 666 7777 8 777 2 66 4 33";
	decrypt(cipher_text);

	return 0;
}