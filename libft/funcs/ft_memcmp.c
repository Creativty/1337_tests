/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:13:22 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/06 17:21:35 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./libft.h"

typedef struct {
	char const *s1;
	char const *s2;
	size_t n;
} MancmpTest;

int	ft_memcmp_test(void)
{
	int	failures = 0;
	MancmpTest inps[] = {
		{ "", NULL, 0 },
		{ NULL, "", 0 },
		{ NULL, NULL, 0 },
		{ "", "", 1 },
		{ "H", "a", 2 },
		{ "H", "H", 2 },
		{ "Hello, world", "Hello, world", 12 },
		{ "Hello, world", "Hellorroszld", 12 },
		{ "Hello, world", "Herrr, world", 12 },
	};
	for (size_t i = 0; i < (sizeof(inps)/sizeof(inps[0])); i++)
	{
		int exp =	memcmp(inps[i].s1, inps[i].s2, inps[i].n);
		int out =	ft_memcmp(inps[i].s1, inps[i].s2, inps[i].n);
		//	log_info("exp: %s, %s gets %d", inps[i].s1, inps[i].s2, exp);
		//	log_info("out: %s, %s gets %d", inps[i].s1, inps[i].s2, out);
		if (exp != out)
		{
			log_error("test %zu: user: \"%d\", expected: \"%d\"", i, out, exp);
			failures++;
		}
	}
	return (failures);
}
