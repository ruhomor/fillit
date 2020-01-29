#include "libft.h"

char	*ft_strtrimchr(char const *s, int c)
{
    size_t	start;
    size_t	finish;
    char	*str;

    if (!s)
        return (NULL);
    start = 0;
    while ((*(s + start) == c) || (*(s + start) == '\n') ||
           (*(s + start) == '\t'))
        start++;
    finish = ft_strlen(s) - 1;
    while ((finish > start) && ((*(s + finish) == c) ||
                                (*(s + finish) == '\n') || (*(s + finish) == '\t')))
        finish--;
    if (!(str = ft_strnew(finish - start + 1)))
        return (NULL);
    str = ft_strncpy(str, s + start, finish - start + 1);
    return (str);
}