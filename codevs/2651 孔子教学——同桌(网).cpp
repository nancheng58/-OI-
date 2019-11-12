#include <iostream>
#include <stdio.h>

using namespace std;

int f[10 + 2][200 + 2][200 + 2];
int at[10 + 2];
char s[10];
int bt[10 + 2];
int i , j , k;
int x , y , z;

int max( int a , int b )
{
    if( a > b )
        return a;
    return b;
}

int dp( int a , int b , int c )
{
    if( c == z && b >= 0 )
        return 0;
    if( b <= 0 )
        return -10000;
    if( a > x )
        return -10000;
    if( f[a][b][c] != -10000 )
        return f[a][b][c];
    return f[a][b][c] = max( dp( a + 1 , b , c ) , dp( a + 1 , b - bt[a] , c + 1 ) + at[a] );
}

int ans;

int main()
{
    scanf( "%d %d %d" , &x , &z , &y );
    for( i = 1 ; i <= x ; i++ )
    {
         scanf( "%s %d" , s , &bt[i] );
         if( s[0] == 'G' )
             at[i] = 3;
         else if( s[0] == 'M' )
             at[i] = 2;
         else
             at[i] = -2;
    }
    for( i = 0 ; i <= x ; i++ )
         for( j = 0 ; j <= y ; j++ )
              for( k = 0 ; k <= z ; k++ )
                   f[i][j][k] = -10000;
    ans = dp( 1 , y , 0 );
    if( ans < -20 )
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}

