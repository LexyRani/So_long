/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:21:43 by aceralin          #+#    #+#             */
/*   Updated: 2023/02/16 21:26:10 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

int		ft_len(char *s)
{
	int i;
	
	i = 0; 
	while(s[i])
	{		
		i++;
	}
	return(i);
}

int		ft_len_tab(char **s)
{
	int i;
	
	i = 0; 
	while(s[i])
	{		
		i++;
	}
	return(i);
}