/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:13:27 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/08 15:20:24 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_entry	*ft_free(t_entry *entry)
{
	t_entry	*entry_buf;


	entry_buf = entry->next;
	return (entry_buf);
}
