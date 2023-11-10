/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:24:53 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:25:03 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

int	ft_toupper_test(void)
{
	int	failures;
	failures = 0;
	for (int i = 0; i < 255; i++)
	{
		int exp = toupper(i);
		int out = ft_toupper(i);
		if (exp != out)
		{
			log_error("test %d: user: \"%d\", expected: \"%d\"", i, out, exp);
			failures++;
		}
	}
	return (failures);
}
