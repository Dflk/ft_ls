/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 13:44:42 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/06 10:42:10 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

t_entry		*sorted_merge(t_entry *a, t_entry *b, int (*f)(t_entry*, t_entry*))
{
	t_entry	*result;

	result = NULL;
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);
	if (f(a, b))
	{
		result = a;
		result->next = sorted_merge(a->next, b, f);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next, f);
	}
	return(result);
}

void 		front_back_split(t_entry *source, t_entry **front_ref,
		t_entry **back_ref)
{
	t_entry		*fast;
	t_entry		*slow;

	if (source == NULL || source->next == NULL)
	{
		*front_ref = source;
		*back_ref = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front_ref = source;
		*back_ref = slow->next;
		slow->next = NULL;
	}
}

void 		merge_sort(t_entry **head_ref, int (*f)(t_entry*, t_entry*))
{
	t_entry	*head;
	t_entry	*a;
	t_entry	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return;
	front_back_split(head, &a, &b); 
	merge_sort(&a, f);
	merge_sort(&b, f);
	*head_ref = sorted_merge(a, b, f);
}
