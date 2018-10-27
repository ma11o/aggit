#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#define BUF 256

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: aggit <path/to/repo>\n");
        return 1;
    }

    FILE *fp;
    char buf[BUF];
    char cmdline[256];
    int add = 0;
    int remove = 0;

    char *cmd1 = "cd ";
    char *cmd2 = " && git diff HEAD^";

    strcpy(cmdline, cmd1);
    strcat(cmdline, argv[1]);
    strcat(cmdline, cmd2);

    if ((fp = popen(cmdline, "r")) == NULL)
    {
        err(EXIT_FAILURE, "%s", cmdline);
    }
    while (fgets(buf, BUF, fp) != NULL)
    {
        if (buf[0] == '+')
        {
            add++;
        }
        else if (buf[0] == '-')
        {
            remove++;
        }
    }
    (void)pclose(fp);

    printf("add: %d\n", add);
    printf("remove: %d\n", remove);

    exit(EXIT_SUCCESS);
}