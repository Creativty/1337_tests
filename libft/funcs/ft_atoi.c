/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:50:44 by aindjare          #+#    #+#             */
/*   Updated: 2023/11/09 14:59:14 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include <signal.h>
#	include <setjmp.h>
#	include "./libft.h"

static int _segfault = 0;
#ifndef MODE_SANITIZE
static jmp_buf jbuf;

static void	handler(int a, siginfo_t *b, void *c)
{
	(void)a;
	(void)b;
	(void)c;
	_segfault = 1;
	longjmp(jbuf, 1);
}
#endif


static void signal_prepare(void)
{
#ifndef MODE_SANITIZE
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	
	sigemptyset(&sa.sa_mask);

	sa.sa_flags = SA_NODEFER;
	sa.sa_sigaction = handler;

	sigaction(SIGSEGV, &sa, NULL);
	setjmp(jbuf);
#else
	do { } while (0);
#endif
}

int	ft_atoi_test(void)
{
	int	failures = 0;
	char	*inps[] = {
#ifndef MODE_SANITIZE
		NULL,
#endif
		"",
		"0",
		"1",
		"-1",
		"100",
		"-100",
		"42069",
		"100100",
		"-100100",
		"2147483647",
		"-2147483648",
	};
	size_t count = sizeof(inps)/sizeof(inps[0]);

	signal_prepare();
	for (size_t i = 0; i < count; i++)
	{
		int exp = atoi(inps[i]);
		int has_segfault = _segfault;
		_segfault = 0;
		int out = ft_atoi(inps[i]);
		if (has_segfault || _segfault)
		{
			if (_segfault != has_segfault)
			{
				if (_segfault)
					log_error("test %zu: user: (segfault), expected: %d", i, exp);
				else
					log_error("test %zu: user: %d, expected: (segfault)", i, out);
				failures++;
			}
			exp = 0;
			out = 0;
			_segfault = 0;
			continue;
		} 
		if (exp != out)
		{
			log_error("test %zu: user: %d, expected: %d", i, out, exp);
			failures++;
		}
	}
#ifndef MODE_SANITIZE
	signal(SIGSEGV, SIG_DFL);
#endif
	return (failures);
}
