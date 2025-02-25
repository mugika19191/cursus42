int get_bit(int number, int i)
{
    int j;
    int rem;
    j = 0;
    rem = 0;
    while (j < i)
    {
        rem = number % 2;
        number = number / 2;
        j++;
    }
    return (rem);
}
