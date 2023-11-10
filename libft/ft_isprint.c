/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:26:39 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/10 09:27:00 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_isprint_test(void)
{
	int	failures;

	failures = 0;
	for (int i = 0; i < 256; i++)
	{
		int exp = isprint(i);
		int out = ft_isprint(i);
		if (exp != out)
		{
			failures++;
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
		}
	}
	return (failures);
}
