#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Error. Usage: %s <message>\n", argv[0]);
	return -1;
	}

	uid_t euid, uid, original_euid;
	uid = 	getuid();
	euid = 	geteuid();

	original_euid = euid;

	printf("UID: %d\tEUID: %d\n", uid, euid);

	//Dropping privileges
	seteuid(uid);

	uid = getuid();
	euid= geteuid();

	printf("Dropped\n");
	printf("UID: %d\tEUID: %d\n", uid, euid);

	/* Do operations that do not require the setuid
	   functionality */

	//Raise privileges
	seteuid(original_euid);

	uid = getuid();
	euid= geteuid();

	printf("Raised\n");
	printf("UID: %d\tEUID: %d\n", uid, euid);

	FILE *fp = fopen("./log.txt","a");
	if (fp == NULL){
		printf("Error opening file.\n");
		exit(-1);
	}
	//seteuid(uid);

	getchar();
	fprintf(fp,"%s\n",argv[1]);
	fclose(fp);

	return 0;

}
