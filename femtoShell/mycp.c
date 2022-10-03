/*
 * mycp.c
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
#include "mycp.h"

#define CP_COMMAND_LEN 2

/*
 * 
 * name: cp
 * @param lin: str of the command and its len
 * @return 0
 * @description: memic cp command
 */

int cp(char *lin, size_t len)
{
    char **argv = NULL;
    int argc = 0;

    argv = strToArgv(&lin[CP_COMMAND_LEN], &argc);

    if ((argc == 0) || (argc > 2)) {
	printf("cp error in argv \n");
    } else {

	// open new file
	int dstFd = open(argv[1], O_WRONLY | O_CREAT, 777);
	if (dstFd == -1) {
	    printf("cp error in open dst file \n");

	} else {
	    int srcFd = open(argv[0], O_RDONLY, 777);
	    if (srcFd == -1) {
		printf("cp error in open src file \n");
	    } else {
		int nRead = 0;
		char buf[100];

		while (nRead = read(srcFd, buf, 100)) {
		    write(dstFd, buf, nRead);

		}
		close(srcFd);
	    }

	    close(dstFd);
	}
    }

    if (argv != NULL) {
	freeArgv(argv);
    }

    return 0;
}
