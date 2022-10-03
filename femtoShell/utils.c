/*
 * utils.c
 * 
 * Copyright 2022 zikovich <https://github.com/Zikovich/linuxWorks/tree/main/femtoShell>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

/*
 * 
 * name: setargs
 * @param args for str buf, argv to be returned and if NULL to bypass it
 * @return number of argv as argc
 * @reference: https://stackoverflow.com/questions/1706551/parse-string-into-argv-argc
 * 
 */
static int setargs(char *args, char **argv)
{
    int count = 0;

    while (isspace(*args))
	++args;
    while (*args) {
	if (argv)
	    argv[count] = args;
	while (*args && !isspace(*args))
	    ++args;
	if (argv && *args)
	    *args++ = '\0';
	while (isspace(*args))
	    ++args;
	count++;
    }
    return count;
}

/*
 * 
 * name: strToArgv
 * @param buf the str line, argv to be set 
 * @return number of argv as argc
 * @reference: https://stackoverflow.com/questions/1706551/parse-string-into-argv-argc
 * 
 */
char **strToArgv(char *args, int *passArgc)
{
    int argc = 0;
    char **argv = NULL;
    char *cpArgs = NULL;

    if (args && *args) {
	cpArgs = strdup(args);
	if (cpArgs) {
	    argc = setargs(cpArgs, NULL);

	    if (argc) {
		argv = malloc((argc + 1) * sizeof(char *));
		if (argv) {
		    int tmpArgc;

		    // save args ptr to first argv[0] to be freed as well with argv
		    argv[0] = cpArgs;

		    *argv++;	// increment argv to be started from [0]
		    tmpArgc = setargs(cpArgs, argv);
		    // check if the previous argv
		    if (tmpArgc != argc) {
			printf
			    ("error in strToArgv util ... please exit no error handling \n");
		    }
		}
	    }
	}
    }

    if (cpArgs && !argv)
	free(cpArgs);

    *passArgc = argc;
    return argv;
}

void freeArgv(char **argv)
{
    if (argv) {
	free(argv[-1]);
	free(argv - 1);
    }
}
