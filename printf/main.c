#include "header.h"
#include <stdio.h>

int	main()
{
	printf("---Char---\n");
	int a = printf("hola %c\n",'c');
	int b = ft_printf("hola %c\n",'c');
	printf("el original [%d], el mio [%d]\n",a,b);
	printf("---char especial---\n");
	a = ft_printf("%c %c %c \n",  0, '0','1');
	b = printf("%c %c %c \n",  0, '0','1');
	printf("el original [%d], el mio [%d]\n",a,b);
	printf("---Strig---\n");
	a = ft_printf("re%s%%\n","tard");
	b = printf("re%s%%\n","tard");
	printf("el original [%d], el mio [%d]\n",a,b);
	char * necora = NULL;
	printf("---Strig (null)---\n");
	a = ft_printf("re%s%%\n",necora);
	b = printf("re%s%%\n",necora);
	printf("el original [%d], el mio [%d]\n",a,b);
	printf("---Strig (vacio)---\n");
	a = ft_printf("re%s%%\n","");
	b = printf("re%s%%\n","");
	printf("el original [%d], el mio [%d]\n",a,b);
	printf("---pointer---\n");
	a = printf("%p\n",&a);
	b = ft_printf("%p\n",&a);
    printf("el original [%d], el mio [%d]\n",a,b);
	printf("---pointer (null)---\n");
	a = printf("%p\n",NULL);
	b = ft_printf("%p\n",NULL);
    printf("el original [%d], el mio [%d]\n",a,b);
	printf("---decimal---\n");
	a = printf("%d\n",(int)-2147483648);
	b = ft_printf("%d\n",(int)-2147483648);
    printf("el original [%d], el mio [%d]\n",a,b);
	a = printf("%d\n",(int)2147483647);
	b = ft_printf("%d\n",(int)2147483647);
    printf("el original [%d], el mio [%d]\n",a,b);
	printf("---decimal (i)---\n");
	a = printf("%i\n",(int)-2147483648);
	b = ft_printf("%i\n",(int)-2147483648);
    printf("el original [%d], el mio [%d]\n",a,b);
	printf("---hex---\n");
	a = printf("%X\n",-90);
	b  = ft_printf("%X\n",-90);
    printf("el original [%d], el mio [%d]\n",a,b);
	printf("---hex minus---\n");
	a = printf("%x\n",(int)2147483647);
	b  = ft_printf("%x\n",(int)2147483647);
    printf("el original [%d], el mio [%d]\n",a,b);
	printf("---unsigned int---\n");
	a = printf("%u\n",-90);
	b  = ft_printf("%u\n",-90);
    printf("el original [%d], el mio [%d]",a,b);
	printf("---Cadena larga---\n");
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	a = printf("%s\n", s2);
	b = ft_printf("%s\n", s2);
	printf("el original [%d], el mio [%d]\n", a, b);
	printf("---Cadena MIX---\n");
	char largo2[] = "Este es un texto";
	a = printf("%s %% %c %d %i %u %x %X\n", largo2, 'a', (int)-2147483648, (int)-2147483648, -2147483, -18989, -18989);
	b = ft_printf("%s %% %c %d %i %u %x %X\n", largo2, 'a', (int)-2147483648, (int)-2147483648, -2147483, -18989, -18989);
	printf("el original [%d], el mio [%d]\n", a, b);


	return (0);
}