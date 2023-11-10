/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:47 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 16:59:33 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_isalnum_test(void)
{
	int	failures;

	failures = 0;
	for (int i = 0; i < 256; i++)
	{
		int exp = isalnum(i);
		int out = ft_isalnum(i);
		if (exp != out)
		{
			failures++;
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
		}
	}
	return (failures);
}
