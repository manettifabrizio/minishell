/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:15:14 by viroques          #+#    #+#             */
/*   Updated: 2021/03/15 21:32:48 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*create_env_elem(char **a)
{
	t_env	*l;
	t_list	*tmp;

	if (!(l = malloc(sizeof(t_env))))
		return (0);
	l->name = a[0];
	if (a[1])
		l->value = a[1];
	else
		l->value = NULL;
	if (!(tmp = ft_lstnew(l)))
		return (0);
	return (tmp);
}

t_uint		count_lines(char *s)
{
	int		x;
	int 	wrd;

	x = 0;
	wrd = 0;
	// if (!s)
	// 	return (0);
	while (s[x])
		if (s[x] == '\n')
		{
			wrd++;
			x++;
			while (s[x] && s[x] != '\n')
				x++;
		}
		else
		{
			wrd++;
			while (s[x] && s[x] != '\n')
				x++;
		}
	if (wrd == 0)
		return (1);
	return (wrd);
}