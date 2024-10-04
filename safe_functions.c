#include "lib.h"

void	*fc_malloc(size_t bytes)
{
	void	*ret;
	ret = malloc(bytes);
	if (!ret)
		printf("malloc error");
	return (ret);
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
	else
		return -1;
}
