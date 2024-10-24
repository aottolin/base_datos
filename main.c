#include "lib.h"

int	main(void)
{
	
	//presentacion_programa();
	//if (contrasena() == -1)
	//	return -1;
	programa_logo();
	t_empresa *e;

	e = fc_malloc(sizeof(t_empresa));
	principal(e, 0);
	return (0);
}

void	principal(t_empresa *e, int value)
{
	int	modulo;
	bool	check;
	check = false;
	if (value == -1)
	{
		printf(RED"EXITING...\n"RST);
		write_file(e, 2);
		exit(0);
	}
	while (!check)
	{
		printf("  [SELECT AN OPTION TO START]\n");
		printf("	[1]INIT NEW WORKER\n");
		printf("	[2]ADD SCHEDULES\n");
		printf("	[3]ANSWER MODE\n");
		printf("	[4]ADD WORKER DATA[CONTRACT HS-INIT DATE]\n");
		printf("	[5]DELETE WORKER\n");
		scanf("%d", &modulo);
		if (modulo == 1 && value == 0)
		{
			modules(e, 1);
			check = true;	
		}
		else if (modulo == 2 && value == 0)
		{
			get_bool(e);
			if (e->first_time == false)
			{
				printf(RED"[ERROR] >_First time INIT first _ You can't add SCHEDULES if the system has 0 workers added\n"RST);
				principal(e, 0);
			}
			else
				modules(e, 2);
			check = true;
		}
		else if (modulo == 3 && value == 0)
		{
			get_bool(e);
			if (e->first_time == false)
			{
				printf(RED"[ERROR] >_First time INIT first _ You can't consult if the system has 0 workers added\n"RST);
				principal(e, 0);
			}
			else
				modules(e, 3);
			check = true;	
		}
		else if (modulo == 4 && value == 0)
		{
			get_bool(e);
			if (e->first_time == false)
			{
				printf(RED"[ERROR] >_First time INIT first _ You can't consult if the system has 0 workers added\n"RST);
				principal(e, 0);
			}
			else
				modules(e, 4);
			check = true;	
		}
		else if (modulo == 5 && value == 0)
		{
			get_bool(e);
			if (e->first_time == false)
			{
				printf(RED"[ERROR] >_First time INIT first _ You can't consult if the system has 0 workers added\n"RST);
				principal(e, 0);
			}
			else
				modules(e, 5);
			check = true;
		}
		else if (modulo == -1)
		{
			check = true;
			printf(RED"EXITING...\n"RST);
			exit(0);
		}
		else
		{
			printf(RED">_Write 1-2-3-4-5 or -1\n"RST);
			clear_input_buffer();
		}
	}
}
