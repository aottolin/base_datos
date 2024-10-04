#include "lib.h"

void	*fc_malloc(size_t bytes)
{
	void	*ret;
	ret = malloc(bytes);
	if (!ret)
		printf("malloc error");
	return (ret);
}

int	check_idem(t_empresa *e, int value)
{
	int	i;

	i = -1;

	while (++i < e->cantidad_empleados) 
		if (e->empleados[i].id == value)
		{
			printf(RED"Employee number[%d] already exist\n"RST, value);
			return (-1);
		}
	return 0;
}

int	check_str(char *str)
{
	int	x;
	int	size;

	x = 0;
	size = strlen(str);

	while (str[x] >= 'a' && str[x] <= 'z')
		x++;
	if (size == x)
		return 0;
	else
		return -1;
}

int check_errors_nbr(int nbr)
{
	if (nbr >= 1 && nbr <= 20)
		return 0;
	printf(RED"Write a number from 1 to 20\n"RST);
	return -1;
}
