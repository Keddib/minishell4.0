/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmanip.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:14:28 by keddib            #+#    #+#             */
/*   Updated: 2021/01/12 16:15:20 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRMANIP_H
# define STRMANIP_H

/*
** strings manipulation prototypes
*/

char				*ft_strcpy(char *dst, char *src);
int					ft_strlen(char *str);
void				ft_strlcpy(char *dst, char *src, int len);
int					ft_strcmp(char *str1, char *str2);
void				*ft_memset(void	*b, int c, size_t len);
bool				is_white_character(char c);
char				*ft_strdup(char *str);
bool				is_alpha(char c);
bool				is_num(char c);
bool				is_underscore(char c);
bool				is_identifier(char *str);
bool				is_meta(char c);
int					ft_printf(const char *s, ...);
char				*ft_itoa(int i);


#endif