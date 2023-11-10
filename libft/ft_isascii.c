/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:26:13 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/10 09:26:31 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_isascii_test(void)
{
	int	failures;

	failures = 0;
	for (int i = 0; i < 256; i++)
	{
		int exp = isascii(i);
		int out = ft_isascii(i);
		if (exp != out)
		{
			failures++;
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
		}
	}
	return (failures);
}
