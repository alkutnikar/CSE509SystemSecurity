#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

        char str[10];
        strncpy(str, argv[1], 10);
        printf("Finished %s\n", str);

        return (0);

}

