/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print_and_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:02:02 by fmanetti          #+#    #+#             */
/*   Updated: 2021/02/25 19:13:42 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*frankenstr(char *s, char *buf, char *s1)
{
	char *s2;

	s2 = ft_substr(s, 0, ft_strlen(s) - ft_strlen(s1));
	s2 = ft_strjoin_nl(s2, buf);
	s2 = ft_strjoin_nl(s2, s1);
	free(s);
	return (s2);
}

char		*inword_erase(char *s, unsigned int len)
{
	int		i;
	char	*tmp;

	i = ft_strlen(s) - len;
	// printf("len = %d str = %lu\n", len, ft_strlen(s));
	// if (i < 1)
	// 	return (NULL);
	tmp = ft_substr(s, i, len);
	s[i - 1] = '\0';
	s = ft_strjoin_nl(s, tmp);
	ft_putstr(CURSOR_LEFT);
	ft_putstr(tmp);
	ft_putchar(' ');
	while (len--)
		ft_putstr(CURSOR_LEFT);
	ft_putstr(CURSOR_LEFT);
	free(tmp);
	// printf("\ns = %s\n", s);
	return (s);
}

static char		*inword_write(char *s, char *buf, unsigned int len)
{
	char	*tmp;

	tmp = ft_substr(s, ft_strlen(s) - len, len);
	ft_putchar(buf[0]);
	ft_putstr(tmp);
	while (len--)
		ft_putstr(CURSOR_LEFT);
	s = frankenstr(s, buf, tmp);
	free(tmp);
	// printf("\ninwrite = |%s|\n", s);
	return (s);
}

char 	*str_print_and_handle(char *s, char *buf, t_cursor pos)
{
	if (buf[0] == '\n')
	{
		while ((pos.x)--)
			ft_putstr(CURSOR_RIGHT);
		ft_putchar(buf[0]);
		return (s);
	}
	if (pos.x == 0)
	{
		ft_putchar(buf[0]);
		s = ft_strjoin_nl(s, buf);
	}
	else
		if (buf[0] == BACKSPACE)
			s = inword_erase(s, pos.x);
		else
			s = inword_write(s, buf, pos.x);
	// printf("*s = %s\n", s);
	return (s);
}