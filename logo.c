#include "lib.h"
#include <time.h>

void	programa_logo(void)
{
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);

	char	buffer[26];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
	printf("\n");
	printf(" W  W  W   OOOOO   R R R   K   K   EEEEE   R R R   SSSSSSSS  \n");
    printf(" W  W  W   O   O   R  R    K  K    E       R  R    SS       \n");
    printf(" W  W  W   O   O   RRR     KKK     EEEEE   RRR       SS     \n");
    printf(" W  W  W   O   O   R  R    K  K    E       R  R        SSS\n");
    printf("    W      OOOOO   R   R   K   K   EEEEE   R   R   SSSSSSS  \n\n");
   

	printf(RED"Created by A.T.O\n"RST);
	printf(RED"Version: 1.0.1\n"RST);
    printf(RED"REPORT PROBLEMS >> alexistottolini@hotmail.com\n\n"RST);
	printf(RED"System time: %s\n\n"RST, buffer);
    printf("USER GUIDE: "RST);
    printf("[0] GO-BACK "RST);
    printf("[-1] EXIT PROGRAM\n"RST);
}
