#include <string>
bool block(char a)
{
    int i, j;
    if (Map[0][0] == a && Map[1][1] == a && Map[2][2] == '-')
    {
        Map[2][2] = 'O';
        return 1;
    }
    else if (Map[2][2] == a && Map[1][1] == a && Map[0][0] == '-')
    {
        Map[0][0] = 'O';
        return 1;
    }
    else if (Map[0][2] == a && Map[1][1] == a && Map[2][0] == '-')
    {
        Map[2][0] = 'O';
        return 1; 
    }
    else if (Map[2][0] == a && Map[1][1] == a && Map[0][2] == '-')
    {
        Map[0][2] = 'O';
        return 1;
    }

    if (Map[0][0] == a && Map[2][2] == a && Map[1][1] == '-')
    {
        Map[1][1] = 'O';
        return 1;
    }


    if (Map[0][2] == a && Map[2][0] == a && Map[1][1] == '-')
    {
        Map[1][1] = 'O';
        return 1;
    }



    if (Map[0][1] == a)
    {
        if (Map[1][0] == a && Map[0][0] == '-' && Map[0][2] == '-' && Map[2][0] == '-')
        {
            Map[0][0] = 'O';
            return 1;
        }
        if (Map[1][2] == a && Map[0][2] == '-' && Map[0][0] == '-' && Map[2][2] == '-')
        {
            Map[0][2] = 'O';
            return 1;
        }
    }

    if (Map[2][1] == a)
    {
        if (Map[1][0] == a && Map[2][0] == '-' && Map[0][0] == '-' && Map[2][2] == '-')
        {
            Map[2][0] = 'O';
            return 1;
        }
        if (Map[1][2] == a && Map[2][2] == '-' && Map[0][2] == '-' && Map[2][0] == '-')
        {
            Map[2][2] = 'O';
            return 1;
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (!j && Map[i][j] == a && Map[i][j + 2] == a && Map[i][j + 1] == '-')
            {
                Map[i][j + 1] = 'O';
                return 1;
            }
            if (j != 2 && Map[i][j] == a && Map[i][j + 1] == a)
            {
                if (!j && Map[i][j + 2] == '-')
                {
                    Map[i][j + 2] = 'O';
                    return 1;
                }
                else if (j == 1 && Map[i][j - 1] == '-')
                {
                    Map[i][j - 1] = 'O';
                    return 1;
                }
            }



            if (!i && Map[i][j] == a && Map[i + 2][j] == a && Map[i + 1][j] == '-')
            {
                Map[i+ 1][j] = 'O';
                return 1;
            }

            if (i != height - 1 && Map[i][j] == a && Map[i + 1][j] == a)
            {
                if (!i && Map[i + 2][j] == '-')
                {
                    Map[i + 2][j] = 'O';
                    return 1;
                }
                else if (i == 1 && Map[i - 1][j] == '-')
                {
                    Map[i - 1][j] = 'O';
                    return 1;
                }
            }
        }
    }
    return 0;
}


bool isover(std::string& winner)
{
    int i, j;
    int space = 0;
   short  int o = 0;
   short int x = 0;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (Map[i][j] == '-') space++;
            else if (Map[i][j] == 'X') x++;
            else o++;
        }
    }
    if ( o<3 || x < 3) return 0;

    if (space == 9) return 0;


    for (i = 0; i < height; i++)
    {
            if (Map[i] == "XXX")
            {
                winner = "Player";
                return 1;
            }
            else if (Map[i] == "OOO")
            {
                winner = "Computer";
                return 1;
            }
            else if(Map[0][i] == 'X' && Map[1][i] == 'X' && Map[2][i] == 'X' )
            {
                winner = "Player";
                return 1;
            }
            else if (Map[0][i] == 'O' && Map[1][i] == 'O' && Map[2][i] == 'O')
            {
                winner = "Computer";
                return 1;
            }
    }

    if ((Map[0][0] == Map[1][1]  && Map[2][2] == Map[0][0]) || (Map[0][2] == Map[1][1]  && Map[2][0] == Map[0][2]))
    {
        if (Map[1][1] == 'X')
            winner = "Player";
        else
            winner = "Computer";
        return 1;
    }
    if (!space)
    {
        winner = "Friendship";
        return 1;
    }
    return 0;
}

void attack()
{
    if (Map[1][1] == '-')
    {
        Map[1][1] = 'O';
        return;
    }
    else
    {
        for (int i = 0; i < height; i += 2)
        {
            for(int j = 0; j < width; j +=2)
                if (Map[i][j] == '-')
                {
                    Map[i][j] = 'O';
                    return;
                }
        }
        for (int i = 0; i < height; i ++)
        {
            if (Map[i][1] == '-')
            {
                Map[i][1] = 'O';
                return;
            }
            if (i == 1 && Map[i][0] == '-')
            {
                Map[i][0] = 'O';
                return;
            }
            if (i == 1 && Map[i][2] == '-')
            {
                Map[i][2] = 'O';
                return;
            }
        }
    }
}
void logic()
{
   if(!block('O'))
       if(!block('X'))
           attack(); 
}














