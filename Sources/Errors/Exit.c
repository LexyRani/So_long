/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:11:39 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/03 05:51:29 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

void	ft_exit(t_solong *map,char *msg)
{
	t_solong	*tmp;
	
	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->extract);
		free(tmp);
	}
	//(void) map;
	if(msg)
		ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}