/*
 * mypwd.c
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
#include <unistd.h>
#include <stdlib.h>
#include "mypwd.h"

int pwd(char *lin, size_t len)
{
    char *buf = NULL;

    buf = getcwd(NULL, 0);

    if (buf == NULL) {
	printf("error pwd return NULL \n");
    } else {
	printf("%s \n", buf);
    }

    free(buf);
    return 0;
}
