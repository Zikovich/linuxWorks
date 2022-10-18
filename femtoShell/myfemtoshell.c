/*
 * myfemtoshell.c
 * 
 * Copyright 2022 zikovich <https://github.com/Zikovich>
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
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "myfemtoshell.h"

void usage()
{
    printf("*** Welcome to Ziko Femto Shell \n");
    printf("use command  (exit) close the program \n");
    printf("any other command will be echoed \n");
}

void writeFD()
{
    int fd = open("./open_txt.txt", O_WRONLY | O_CREAT, 777);

    write(fd, "test fd /n", 5);

    close(fd);
}

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *tmpBuf = NULL;
	bool retError = false;

    usage();

    writeFD();

    while (1) {
	printf("Please enter you command : ");

	nread = getline(&line, &len, stdin);

	if ((nread == EOF) || (line[0] == '\n')) {
	    // nothing
	} else if ((strcmp("exit\n", line) == 0)
		   || (strcmp("q\n", line) == 0)) {
	    break;
	} else if (strncmp("mypwd", line, 3) == 0) {
	    pwd(line, len);
	} else if (strncmp("myecho", line, 4) == 0) {
	    echo(line, len);
	} else if (strncmp("mycp", line, 2) == 0) {
	    cp(line, len);
	} else if (strncmp("mymv", line, 2) == 0) {
	    mv(line, len);
	} else {
	   retError = commandShell(line, len);
	} 
	
	if (retError)
	{
		printf("Sorry, Your command: < %s > is not supported yet \n",
		   line);
	}
	free(line);
    line = NULL;
    len = 0;
    }

    printf("Exit Ziko Femto Shell! See you again :) \n");

    return 0;
}
