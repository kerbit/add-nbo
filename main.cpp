#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

void usage() {
	printf("syntax : add-nbo <file1> <file2>\n");
	printf("sample : add-nbo a.bin c.bin\n");
	return;
}

int main(int argc, char* argv[]){
	if (argc != 3){
		usage();
		return 0;
	}
	
	FILE *fp;
	uint32_t _x, _y;
	uint32_t x, y;

	fp = fopen(argv[1], "rb");
	if (fp == NULL){
		printf("error: %s open failed\n", argv[1]);
		return 0;
	}
	fread(&_x, 1, 4, fp);
	fclose(fp);

	fp = fopen(argv[2], "rb");
	if (fp == NULL){
		printf("error: %s open failed\n", argv[2]);
		return 0;
	}
	fread(&_y, 1, 4, fp);	
	fclose(fp);

	x = ntohl(_x);
	y = ntohl(_y);

	printf("%d(%#x) + %d(%#x) = %d(%#x)\n", x, x, y, y, x + y, x + y);
	return 0;
}
	

