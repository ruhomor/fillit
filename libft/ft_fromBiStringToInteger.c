int ft_fromBiStringToInteger(char *str)
{
    int total;

    total = 0;
    while (*str)
    {
        total *= 2;
        if (*str++ == '1')
        {
            total += 1;
        }
    }
    return (total);
}