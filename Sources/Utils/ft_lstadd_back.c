/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:51:30 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/11 20:30:24 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	if (*lst)
	{
		new->index = ft_lstlast(*lst)->index + 1;
		new->prev = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
	else
	{
		new->index = 0;
		*lst = new;
	}	
}

int	ft_lstsize(t_map*lst)
{
	int		i;
	t_map	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}