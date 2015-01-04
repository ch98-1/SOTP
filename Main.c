//Copyright (C) 2015  Corwin Hansen
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc == 4){//correct number of arguments
		FILE *source = fopen(argv[1], "rb");//open first argument to read as source
		FILE *dest = fopen(argv[2], "wb");//open second argument to write as destination
		FILE *key = fopen(argv[3], "rb");//open thard argument to read as key
		fpos_t current = 0;//current position in file
		unsigned char buffk[1], buffs[2];//bufffers for key and source
		if (source == NULL || key == NULL){//if file could not be opend
			printf("Could not open one of the files\n Usage: %s <source> <destinatio> <key>", argv[0]);//print error and usage
			return 0;//exit
		}
		while (fread(buffk, 1, 1, key) != 0){//if not end of file of key
			buffs[0] = 0;//reset to 0
			fread(buffs, 1, 1, source);//read source
			buffs[0] ^= buffk[0];//get xor of both value
			fwrite(buffs, 1, 1, dest);//write to source
			buffk[0] = 0;//reset to 0
		}
		return 0;//exit
	}
	printf("Usage: %s <source> <destinatio> <key>", argv[0]);//print usage
	return 0;//exit
}

