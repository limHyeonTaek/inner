/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:47:39 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 17:16:06 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*free_return_null(t_list **new,
				void *new_content, void (*del)(void *))
{
	if (new_content)
		del(new_content);
	ft_lstclear(new, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (free_return_null(&new, new_content, del));
		new_lst = ft_lstnew(new_content);
		if (!new_lst)
			return (free_return_null(&new, new_content, del));
		ft_lstadd_back(&new, new_lst);
		lst = lst->next;
	}
	return (new);
}
