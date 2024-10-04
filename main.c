#include "lib.h"

int	main(void)
{
	int modulo;
	bool	check;
	
	presentacion_programa();
	if (contrasena() == -1)
		return -1;
	t_empresa *e;

	e = fc_malloc(sizeof(t_empresa));
	
	check = false;
	while (!check)
	{
		printf("	(1) Init new worker  \n");
		printf("	(2) Add schedules \n");
		printf("	(3) Init answer module \n");
		scanf("%d", &modulo);
		fflush(stdin);
		if (modulo == 1)
		{
			modules(e, 1);
			check = true;
		}	
		else if (modulo == 2)
		{
			modules(e, 2);
		}
		else if (modulo == 3)
		{
			modules(e, 3);
			check = true;
		}
		else
			printf(RED"Write 1, 2 or 3\n"RST);
	}
	//init_calendario(e);
	return (0);
}
