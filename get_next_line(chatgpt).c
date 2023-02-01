#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 32

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return ((char*)s);
        s++;
    }
    if (c == '\0')
        return ((char*)s);
    return (NULL);
}

char    *get_next_line(int fd)
{
    static char buffer[BUFF_SIZE + 1];
    static char *ptr;
    static int ret;
    char *line;
    char *temp;

    if (!ptr)
    {
        ret = read(fd, buffer, BUFF_SIZE);
        buffer[ret] = '\0';
        ptr = buffer;
    }
    if ((temp = ft_strchr(ptr, '\n')))
    {
        *temp = '\0';
        line = strdup(ptr);
        ptr = temp + 1;
        return (line);
    }
    if (!ret)
        return (NULL);
    line = strdup(ptr);
    ptr = NULL;
    return (line);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
