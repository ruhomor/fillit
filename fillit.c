#include "fillit.h"

char    *ft_code(char *str)
{
    int     i;
    char    *code;

    i = 0;
    code = ft_strnew(ft_strlen(str));
    while (*(str + i) != '\0')
    {
        if (*(str + i) == '.')
            *(code + i) = '0';
        else if (*(str + i) == '#')
            *(code + i) = '1';
        else
            *(code + i) = *(str + i);
        i++;
    }
    return (code);
}

t_tetramino *ft_tetraBase(t_tetramino *tetra)
{
    while (tetra->order != 1)
    	tetra = tetra->prev;
    return (tetra);
}

char    *ft_padding(const char *line, int size)
{
    char    *str;
    size_t  len;
    size_t  i;

    str = ft_strnew(size + 1);
    len = ft_strlen(line);
    i = 0;
    while (i < len)
    {
        *(str + i) = *(line + i);
        i++;
    }
    while (i < (size_t)size + 1)
    {
        *(str + i) = '0';
        i++;
    }
    return (str);
}

char    *ft_makeline(t_tetramino *tetra, int size)
{
    char    *line;

    line = ft_strnew(4 * (size + 1));
    line = ft_strcat(line, ft_padding(tetra->base[0], size));
    line = ft_strcat(line, ft_padding(tetra->base[1], size));
    line = ft_strcat(line, ft_padding(tetra->base[2], size));
    line = ft_strcat(line, ft_padding(tetra->base[3], size));
    line = ft_strtrimchrCond(line, '0', 0, 1);
    //line = ft_strcat(line, ft_strdup("0"));
    return (line);
}

int     ft_check(char *map, char *line, int pos)
{
    size_t  i;

    i = 0;
    while (i < ft_strlen(line))
    {
        if (*(line + i) == '1')
        {
            if (*(map + pos + i) != '0')
                return (0);
        }
        i++;
    }
    return (1);
}

void    ft_fillOutputMap(t_tetramino *tetra, char **map, int size)
{
    char    *line;
    size_t  i;
    char    c;

    while (tetra)
    {
        line = ft_makeline(tetra, size);
        i = 0;
        c = tetra->order + 'A' - 1;
        while (i < ft_strlen(line))
        {
            if (*(line + i) == '1')
                *(*map + tetra->pos + i) = c;
            i++;
        }
        tetra = tetra->next;
    }
    i = 0;
    while (i < ft_strlen(*map))
    {
        if (*(*map + i) == '0')
            *(*map + i) = '.';
        else if (*(*map + i) == '1')
            *(*map + i) = '\n';
        i++;
    }
}

void    ft_fillmap(char *line, char **map, int pos)
{
    size_t  i;

    i = 0;
    while (i < ft_strlen(line))
    {
        if (*(line + i) == '1')
            *(*map + pos + i) = '1';
        i++;
    }
}
void    ft_unfillmap(char *line, char **map, int pos)
{
    size_t  i;

    i = 0;
    while (i < ft_strlen(line))
    {
        if (*(line + i) == '1')
            *(*map + pos + i) = '0';
        i++;
    }
}

int     ft_size(t_tetramino *tetra)
{
    int i;

    i = 0;
    while (tetra)
    {
        i++;
        tetra = tetra->next;
    }
    return (i);
}

int     ft_mainsearch(t_tetramino *tetra, char **map, int size)
{
    char    *line;

    if (!tetra)
        return (1);
    line = ft_makeline(tetra, size);
    //printf("line %s\n", line);
    while (1)
    {
        tetra->pos++;
        //printf("jj %d order= %d\n", tetra->pos, tetra->order);
        if (tetra->pos + ft_strlen(line) > ft_strlen(*map))
            return (0);
        //printf("check %d\n", ft_check(*map, line, tetra->pos));
        if (ft_check(*map, line, tetra->pos))
        {
            ft_fillmap(line, map, tetra->pos);
            //printf("fill %s\n", *map);
            if (!ft_mainsearch(tetra->next, map, size))
            {
                ft_unfillmap(line, map, tetra->pos);
                tetra->next->pos = -1;
                continue ;
            }
            else
                return (1);
        }
    }
}

char    *ft_makemap(int size)
{
    char    *map;
    int     i;
    int     j;

    i = 0;
    map = ft_strnew((size + 1) * size + 1);
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            *(map + i*(size+1) + j) = '0';
            j++;
        }
        *(map + i*(size+1) + j) = '1';
        i++;
    }
    return (map);
}


void    fillit(int fd) {
    char        *line;
    char        *code;
    t_tetramino *tetra;
    t_tetramino *tmp;
    int         n;
    int         j;
    int         size;

    code = ft_strnew(20);
    n = 0;
    j = 0;
    while (get_next_line(fd, &line) || j == 4)
    {
        //printf("line %s\n", line);
        if (ft_strlen(line) == 0 || j == 4)
        {
            j = 0;
            n++;
            code = ft_code(code);
            code = ft_strtrimchr(code, '0');
            if (!tetra) {
                tetra = ft_tetramino(ft_fromBiStringToInteger(code));
                tetra->order = 1;
            }
            else {
                tetra->next = ft_tetramino(ft_fromBiStringToInteger(code));
                tmp = tetra;
                tetra = tetra->next;
                tetra->prev = tmp;
                tetra->order = tetra->prev->order + 1;
            }
            free(code);
            code = ft_strnew(20);
        }
        else
        {
            j++;
            code = ft_strcat(code, line);
            code = ft_strcat(code, ft_strdup("0"));
        }
    }

    //search minimum map size
    tetra = ft_tetraBase(tetra);
	//printf("Size %d\n", ft_size(tetra));
	size = 1;
    size = ft_max(size, tetra->min_size);
    while (tetra->next)
    {
        tetra = tetra->next;
        size = ft_max(size, tetra->min_size);
    }
    size = ft_max(size, ft_sqrt(n * 4));

    //to main search
    char *map;
    tetra = ft_tetraBase(tetra);
    while (1)
    {
        map = ft_makemap(size);
        //printf("Suka %s\n", map);
        if (ft_mainsearch(tetra, &map, size))
            break ;
        tetra->pos = -1;
        size++;
    }

    //output
    map = ft_makemap(size);
    ft_fillOutputMap(tetra, &map, size);
    ft_putstr(map);
}