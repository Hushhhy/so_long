/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:14:40 by acarpent          #+#    #+#             */
/*   Updated: 2024/06/12 13:58:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_readbuffer(char *buffer);
int		ft_strslen(char *str);
char	*ft_strsjoin(char *buffer, char *result);
char	*ft_cleanup(char *stash);
void	ft_sbzero(void *s, size_t n);
char	*ft_strsdup(char *s1);
char	*ft_line(char *str);

#endif 