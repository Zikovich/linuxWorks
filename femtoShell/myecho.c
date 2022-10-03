/*
 * myecho.c
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
#include "utils.h"
#include "myecho.h"

#define ECHO_COMMAND 4
int echo(char *lin, size_t len)
{
    char **argv = NULL;
    int argc;

    argv = strToArgv(&lin[ECHO_COMMAND], &argc);

    if ((argc == 0) || (argv == NULL)) {
	printf("\n");
    } else {

	for (int i = 0; i < argc; i++) {
	    printf("%s ", argv[i]);

	}
	printf("\n");
    }

    if (argv != NULL) {
	freeArgv(argv);
    }

    return argc;
}
