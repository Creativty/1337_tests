/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:46:19 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 16:57:05 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_calloc_test(void)
{
	int	failures = 0;

	{
		for (size_t	i = 0; i < 16; i++)
		{
			int	*exp = (int *)ft_calloc(i, sizeof(int));
			for (size_t j = 0; j < i; j++)
				if (exp[j] != 0)
				{
					failures++;
					break;
				}
			free(exp);
		}
	}
	{
		for (size_t	i = 0; i < 16; i++)
		{
			char	*exp = (char *)ft_calloc(i, sizeof(char));
			for (size_t j = 0; j < i; j++)
				if (exp[j] != 0)
				{
					failures++;
					break;
				}
			free(exp);
		}
	}
	return (failures);
}
