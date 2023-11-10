/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:59:49 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:00:00 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_isalpha_test(void)
{
	int	failures;

	failures = 0;
	for (int i = 0; i < 256; i++)
	{
		int exp = isalpha(i);
		int out = ft_isalpha(i);
		if (exp != out)
		{
			failures++;
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
		}
	}
	return (failures);
}
