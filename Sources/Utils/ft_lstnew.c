/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:27:25 by aceralin          #+#    #+#             */
/*   Updated: 2023/01/30 23:47:34 by aceralin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long.h"

t_solong	*ft_lstnew(void *extract)
{
	t_solong	*new_element;

	new_element = malloc(sizeof(t_solong));
	if (!new_element)
		return (NULL);
	new_element->extract = extract;
	new_element->next = NULL;
	return (new_element);
}
