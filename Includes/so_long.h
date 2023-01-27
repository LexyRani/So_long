/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:27 by aceralin          #+#    #+#             */
/*   Updated: 2023/01/27 17:57:29 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/* BUFFER*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/******************************************************************************/
/*									PARSING	  								  */
/******************************************************************************/
char	*get_next_line(int fd);
int	ft_arg_is_ber(const char *s1, const char *s2, size_t n);

/******************************************************************************/
/*									GET_NEXT_LINE	  						  */
/******************************************************************************/

char	*ft_copy_and_stick(char *buffer, char *line_read);
char	*get_next_line(int fd);
int		found_new_line(char *str);
char	*buffer_after_new_line(char *buffer, int len_line_read);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

/******************************************************************************/
/*									ERRORS  								  */
/******************************************************************************/

void    ft_exit(char *str,char *msg);
/******************************************************************************/
/*									UTILS	  								  */
/******************************************************************************/

size_t	ft_strlen(const char *s);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
#endif