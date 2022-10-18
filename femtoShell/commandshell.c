/*
 * commandShell.c
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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "utils.h"
#include <stdlib.h>
#include "commandshell.h"


bool commandShell(char *lin, size_t len)
{

    char **argv = NULL;
    int argc = 0;
	int status;

    argv = strToArgv(lin, &argc);


	int ret_pid = fork();

	if (ret_pid < 0)
	{
		printf("fork failed \n");
	}else if (ret_pid > 0 )
	{
		wait(&status);
		printf("Child terminated \n");
	} else
	{
		char * argvTmp[] = {NULL};
		char * envTmp[] = {NULL};
		int status;

		execvpe(argv[0],argvTmp,envTmp);

		printf("Excute command failed \n");
		exit(status);
	}

    if (argv != NULL) {
	freeArgv(argv);
    }

    return false;
}
