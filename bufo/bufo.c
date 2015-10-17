#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

	char str[10];
	strcpy(str, argv[1]);
	printf("Finished %s\n", str);

	return (0);

}
