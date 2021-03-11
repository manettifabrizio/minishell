/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print_and_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:02:02 by fmanetti          #+#    #+#             */
/*   Updated: 2021/03/11 20:28:00 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*inword_erase(char *s, t_uint px)
{
	int		i;
	char	*tmp;

	if (ft_strlen(s) == px)
		return (s);
	i = ft_strlen(s) - px;
	tmp = ft_substr(s, i, px);
	s[i - 1] = '\0';
	s = ft_strjoin_nl(s, tmp);
	ft_putstr(CURSOR_LEFT);
	ft_putstr(tmp);
	ft_putchar(' ');
	while (px--)
		ft_putstr(CURSOR_LEFT);
	ft_putstr(CURSOR_LEFT);
	free(tmp);
	return (s);
}

static char		*frankenstr(char *s, char *buf, char *s1)
{
	char *s2;

	s2 = ft_substr(s, 0, ft_strlen(s) - ft_strlen(s1));
	s2 = ft_strjoin_nl(s2, buf);
	s2 = ft_strjoin_nl(s2, s1);
	free(s);
	return (s2);
}

static char		*inword_write(char *s, char *buf, t_uint px)
{
	char	*tmp;

	tmp = ft_substr(s, ft_strlen(s) - px, px);
	ft_putchar(buf[0]);
	ft_putstr(tmp);
	while (px--)
		ft_putstr(CURSOR_LEFT);
	s = frankenstr(s, buf, tmp);
	free(tmp);
	return (s);
}

char 	*str_print_and_handle(t_main *m, char *s, char *buf, t_cursor p)
{
	if (buf[0] == '\n')
	{
		while ((p.lpos)--)
			ft_putstr(CURSOR_RIGHT);
		ft_putchar(buf[0]);
		return (s);
	}
	if (p.spos == 0 && (ft_isprint(buf[0])))
	{
		ft_putchar(buf[0]);
		s = ft_strjoin_nl(s, buf);
	}
	else if (p.spos > 0)
	{
		if (buf[0] == BACKSPACE)
			s = inword_erase(s, p.spos);
		else
			s = inword_write(s, buf, p.spos);
	}
	m->exit_status = 0;
	return (s);
}