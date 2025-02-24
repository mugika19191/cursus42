int	st_atoi(const char *str, int *corr)
{
	int	res;
	int	i;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		*corr = 0;
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	if (str[i])
		*corr = 0;
	return (res * neg);
}
