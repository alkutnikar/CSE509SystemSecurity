#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	char *x = (char *) malloc(40);
	strncpy(x, argv[1], 40);
	printf("%s",x);
	printf("\n");
	return (0);

}
