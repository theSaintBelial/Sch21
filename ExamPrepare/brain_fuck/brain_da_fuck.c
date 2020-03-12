 
 #include <unistd.h>
 #include <stdlib.h>

int matching(char *oper, int i)
{
    int balance;

    balance = 0;
    if (oper[i] == '[')
    {
        i++;
        while (!(oper[i] == ']' && balance == 0))
        {
            if (oper[i] == '[')
                balance++;
            else if (oper[i] == ']')
                balance--;
            i++;
        }
    }
    else if (oper[i] == ']')
    {
        i--;
        while (!(oper[i] == '[' && balance == 0))
        {
            if (oper[i] == ']')
                balance++;
            else if (oper[i] == '[')
                balance--;
            i--;
        }
    }
    return (--i);
}

void    ft_brain_fuck(char *oper)
{
    int i;
    int pointer;
    char cache[2048];

    i = 0;
    while (i < 2048)
        cache[i++] = 0;
    pointer = 0;
    i = 0;
    while (oper[i])
    {
        if (oper[i] == '>')
            pointer++;
        else if (oper[i] == '<')
            pointer--;
        else if (oper[i] == '+')
            cache[pointer]++;
        else if (oper[i] == '-')
            cache[pointer]--;
        else if (oper[i] == '.')
            write(1, cache + pointer, 1);
        else if (oper[i] == '[')
        {
			if (cache[pointer] == 0)
				i = matching(oper, i);
		}
        else if (oper[i] == ']')
        {
			if (cache[pointer] != 0)
    	       i = matching(oper, i);
		}
    	i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        ft_brain_fuck(av[1]);
    else
        write(1, "\n", 1);
    return (0);
}