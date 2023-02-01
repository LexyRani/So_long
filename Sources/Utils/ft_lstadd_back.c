/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:51:30 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/01 01:16:05 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_lstadd_back(t_solong **lst, t_solong *new)
{	
	if (*lst)
	{
		ft_lstlast(*lst)->next = new;
		new->prev = ft_lstlast(*lst);
	}
	else
		*lst = new;
}

int	ft_lstsize(t_solong *lst)
{
	int		i;
	t_solong	*tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}