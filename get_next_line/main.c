/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:56:59 by imugica-          #+#    #+#             */
/*   Updated: 2024/12/20 13:25:47 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(){
    
    char* fileName = "readme.txt";
    char* str;
    int i = 0;

    int fd = open(fileName, O_RDONLY);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }
    while ((str = get_next_line(fd)))
    {
        printf("-------EN MAIN[%d]-------\n%s", i++, str);
        free(str);
    }
    return 0;
}
