#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int     main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int ret = 1;

    printf("BUFF_SIZE = %d\n", BUFF_SIZE);
    line = ft_strnew(BUFF_SIZE);
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
		{
            perror("open");
			exit(1);
		}
        while ((ret = get_next_line(fd, NULL)) >= 0)
        {
            if (ret == -1)
                perror("");
//			printf("ret = %d", ret);
            printf("[%zu] %s (ret = %d)\n", ft_strlen(line), line, ret);
//			sleep(2);
        }
    }
    else
    {
        fd = 0;
        while ((ret = get_next_line(fd, &line)) != 0)
		{
            if (ret == -1)
                perror("");
            printf("[%zu] %s (ret = %d)\n", ft_strlen(line), line, ret);
//			sleep(2);
        }
    }
    printf("[%zu] %s (ret = %d)\n", ft_strlen(line), line, ret);
    return (0);
}
