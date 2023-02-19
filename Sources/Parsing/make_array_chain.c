/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 23:12:50 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/20 00:14:52 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

char	**copy_array(char **array, t_map **map)
{
	char	**new_array;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!array)
		return (NULL);
	len = ft_lstsize(*map);
	new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_array)
		return (NULL);
	while (i < len)
	{
		new_array[i] = ft_strdup_without_nl(array[i]);
		if (!new_array[i])
		{
			ft_free_double_tab(new_array);
			return (NULL);
		}
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}

char	**make_array_chain(t_map **map)
{
	char	**new_array;
	int		len;
	t_map	*tmp;
	int		i;

	tmp = *map;
	len = 0;
	i = 0;
	len = ft_lstsize(tmp);
	new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_array)
		return (NULL);
	while (i < len)
	{
		new_array[i] = ft_strdup_without_nl(tmp->line);
		i++;
		tmp = tmp->next;
	}
	new_array[i] = NULL;
	return (new_array);
}

void	ft_free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free (tab);
}

int	is_what_kind(char tmp, t_count *count)
{
	if (tmp == 'P')
	{
		count->p++;
		if (count->p > 1)
			return (0);
	}
	if (tmp == 'C')
		count->c++;
	if (tmp == 'E')
	{
		count->e++;
		if (count->e > 1)
			return (0);
	}
	return (1);
}