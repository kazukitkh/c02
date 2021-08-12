#include <unistd.h>

void	ten_to_sixteen(char *str)
{
	int		d;
	int		e;

	e = *str / 16;
	d = *str % 16;
	write(1, e + 48, 1);
	if (d >= 0 && d <= 9)
		write(1, &(e + 30), 1);
	else
		write(1, &(d + 61), 1);
}

void	ft_putstr_non_printable(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 127 || str[i] >= 0 && str[i] <= 32)
            {
                write(1, &'\\', 1);
                ten_to_sixteen(&str[i]);
            }
		else
			write(1, &str[i], 1);
    }
}

int	main(void)
{
	char	str[] = "hjief\niio...";

	printf("%s", ft_putstr_non_printable(str));
	return (0);
}
