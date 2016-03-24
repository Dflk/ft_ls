/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:19:36 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/24 16:26:57 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		*ft_countspace(t_entry *entries)
{
	struct stat	stats;
	size_t		*spaces;

	if ((spaces = (size_t*)ft_memalloc(sizeof(size_t) * 2)))
		while (entries)
		{
			stat(entries->path, stats);

			entries = entries->next;
		}
}
