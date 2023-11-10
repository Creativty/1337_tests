/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:41:47 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/09 15:11:48 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

static t_list	*ft_lstarr(int *input, size_t count)
{
	t_list	*temp;
	t_list	*iter;
	t_list	*begin;

	iter = NULL;
	begin = NULL;
	for (size_t i = 0; i < count; i++)
	{
		int	*n = malloc(sizeof(int));
		*n = input[i];
		temp = ft_lstnew((void *)n);
		if (!temp)
		{
			log_error("could not allocate for test %zu", i);
			return (NULL);
		}
		if (begin == NULL)
			begin = temp;
		if (iter != NULL)
			iter->next = temp;
		iter = temp;
	}
	return (begin);
}

static void nothing(void *a)
{
	free(a);
}

static void *power_2(void	*_a)
{
	int *a = malloc(sizeof(int));
	if (a == NULL)
		return (NULL);
	int b = *((int *)(_a));
	*a = b * b;
	return (a);
}

int	ft_lstmap_bonus_test(void)
{
	int	failures	= 0;
	size_t	idx		= 0;

	int	inps_int[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	size_t	inps_size = (sizeof(inps_int)/sizeof(inps_int[0]));

	t_list	*inp = ft_lstarr((void *)inps_int, inps_size);
	t_list	*out = ft_lstmap(inp, power_2, nothing);

	while (out && inp)
	{
		int inp_n = *((int *)inp->content) ;
		int out_n = *((int *)out->content) ;
		int inp_n2 = inp_n * inp_n;
		if (inp_n2 != out_n)
		{
			log_error("node %zu: user: %d, expected: %d", idx, inp_n2, out_n);
			failures++;	
		}
		idx++;
		inp = inp->next;
		out = out->next;
	}
	if (idx != inps_size)
	{
		log_error("visited only %zu out of %zu expected nodes", idx, inps_size);
		failures++;
	}

	ft_lstclear(&inp, free);
	ft_lstclear(&out, free);

	return (failures);
}
