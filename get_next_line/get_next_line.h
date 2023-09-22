/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:28:51 by feden-pe          #+#    #+#             */
/*   Updated: 2023/06/30 17:50:30 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*new_content(char *content);
char	*get_one_line(char *content);
char	*update_content(char *content, int fd);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(char *s, int c);
size_t	ft_strlen2(char *s);

#endif
