#include <stdio.h>
int map[100][100];
int n, m, r, c, s, k;
int  result = 99999999;
void search(int x, int y, int count)
{
       if ((x < 0) || (y < 0) || (x > n-1) || (y > m-1))
       return;
       if ((x == s-1) && (y == k-1))
       {       if (result > count)
              {map[x][y] = count;
                      result = count;
              }
       }
       if ((map[x][y] == 0) || (map[x][y] > count))
       {       map[x][y] = count;
              search(x - 2, y - 1, count + 1);
              search(x - 2, y + 1, count + 1);
              search(x - 1, y - 2, count + 1);
              search(x + 1, y - 2, count + 1);
              search(x + 2, y - 1, count + 1);
              search(x + 2, y + 1, count + 1);
              search(x - 1, y + 2, count + 1);
              search(x + 1, y + 2, count + 1);
       }
}

int main(void)
{
       int TC,i;

       scanf("%d", &TC);
       for(i = 1;i<= TC;i++
       {
       result = 99999999;
              scanf("%d %d", &n, &m);
              scanf("%d %d %d %d", &r, &c, &s, &k);

              map[r-1][c-1] = 1;
           search(r-1, c-1, 0);

              printf("%d\n", result);
       }
       return 0;//Your program should return 0 on normal termination.
}
