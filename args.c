#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

/*#include <features.h>
#define  _BSD_SOURCE
#define _POSIX_C_SOURCE 200112L 
#define _XOPEN_SOURCE 600*/

int main (int argc , char ** argv) {
	
	extern char ** environ ;
	
	/*int somme = 0 ;
	
	for (int i = 1 ; i < argc ; i++)
		
		somme += atoi(argv[i]) ;
		
	printf("Somme = %d\n", somme) ;*/
	
	if (argc > 1) {
	
		char * ARGUMENTS = malloc(strlen(argv[1]) + 1) ;
		strcpy(ARGUMENTS, argv[1]) ;
		
		printf("%s\n", ARGUMENTS) ;
	
		for (int i = 2 ; i < argc && ARGUMENTS != NULL ; i++) {
		
			void * tmp = realloc(ARGUMENTS, strlen(ARGUMENTS) + strlen(argv[i]) + 3) ;
			
			if (tmp) {
				
				ARGUMENTS = (char *)tmp ;
				char * tmp2 = malloc(strlen(argv[i]) + 2) ;
			
				if (tmp2) {
				
					tmp2[0] = ' ';
					strcat(tmp2, argv[i]) ;
					strcat(ARGUMENTS, tmp2) ;
					
				}
				
				else { free(ARGUMENTS) ;  ARGUMENTS = NULL ; }
				
			}
				
			else { free(ARGUMENTS) ; ARGUMENTS = NULL ; }
			
			printf("%s\n", ARGUMENTS) ;
			
		}
		
		setenv("ARGUMENTS", ARGUMENTS, 1) ;
		
		for (int i = 0 ; environ[i] ; i++)
			printf("%s\n", environ[i]) ;
			
		free(ARGUMENTS) ;
		
		
	}
						
	return EXIT_SUCCESS ;
	
}
