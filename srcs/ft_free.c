/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:13:27 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/08 16:01:04 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_entry	*ft_free(t_entry **entry, int flag)
{
	t_entry	*entry_buf;

	if (flag == 0)
	{
		free((*entry)->path);
		free((*entry)->name);
	}
	else
		while ((*entry)->files)
			(*entry)->files = ft_free(&(*entry)->files, 0);
	entry_buf = (*entry)->next;
	free(*entry);
	return (entry_buf);
}
