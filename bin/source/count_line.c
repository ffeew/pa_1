#include "system_program.h"

/*
Count the number of lines in a file
*/
int execute(char **args)
{
    int number_of_lines = 0;
    FILE *fp;

    // open file in read mode
    fp = fopen(args[1], "r");
    if (!fp)
    {
        printf("File %s cannot be found.\n", args[1]);
        return 1;
    }

    char *buffer;
    size_t size = 0;
    ssize_t nread;
    while (nread = getline(&buffer, &size, fp) != -1){
        number_of_lines++;
    }
    free(buffer);

    fclose(fp); // close file.
    printf("%d \t %s \n", number_of_lines, args[1]);
    return 1;
}

int main(int argc, char **args)
{
    return execute(args);
}