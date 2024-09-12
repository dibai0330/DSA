#include <stdio.h>

int main()
{
    int cock, hen, chick;
    for (cock = 0; cock <= 20; cock++)
    {
        for (hen = 0; hen <= (100 - 5 * cock) / 3; hen++)
        {
            for (chick = 0; chick <= (100 - 5 * cock - 3 * hen) * 3; chick++)
            {
                if ((chick / 3 + cock * 5 + hen * 3 == 100) & (chick + cock + hen == 100))
                {
                    printf("公鸡有%2d只，母鸡有%2d只，小鸡有%3d只\n", cock, hen, chick);
                }
            }
        }
    }
    return 0;
}