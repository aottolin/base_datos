#include "lib.h"

void	*fc_malloc(size_t bytes)
{
	void	*ret;
	ret = malloc(bytes);
	if (!ret)
		printf("malloc error");
	return (ret);
}

/*int	check_errors_str(char *str)
{


}
*/
int check_errors_nbr(int nbr)
{

	if (nbr >= 1 && nbr <= 100)
		return 0;
	else
		return -1;
}
