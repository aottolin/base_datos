#include "lib.h"

int	main(void)
{
	int modulo;
	bool	check;
	
	//presentacion_programa();
//	if (contrasena() == -1)
//		return -1;
	t_empresa *e;

	e = fc_malloc(sizeof(t_empresa));
	
	check = false;
	while (!check)
	{
		printf("	[1]INIT NEW WORKER\n");
		printf("	[2]ADD SCHEDULES\n");
		printf("	[3]ANSWER MODE\n");
		printf("	[4]ADD CONTRACT HOURS\n");
		scanf("%d", &modulo);
		if (modulo == 1)
		{
			modules(e, 1);
			check = true;
		}	
		else if (modulo == 2)
		{
			modules(e, 2);
			check = true;
		}
		else if (modulo == 3)
		{
			modules(e, 3);
			check = true;
		}
		else if (modulo == 4)
		{
			modules(e, 4);
			check = true;
		}
		else
			printf(RED">_Write 1, 2 or 3\n"RST);
	}
	return (0);
}
