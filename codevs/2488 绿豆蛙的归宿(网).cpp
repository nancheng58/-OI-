#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
double f[100000 + 2];
vector < int > linker[100000 + 2];
vector < int > dist[100000 + 2];
int n , m;
int i;
int a , b , c;

double dp( int pos )
{
    if( pos == n )
        return 0;
    if( f[ pos ] )
        return f[ pos ];
    int i;
    for( i = 0 ; i < linker[ pos ].size() ; i++ )
         f[ pos ] += ( dp( linker[ pos ][i] ) + dist[ pos ][i] ) / linker[ pos ].size();//
    return f[ pos ];
}

int main()
{
    scanf("%d%d",&n,&m);
    for( i = 1 ; i <= m;i++)
    {
         scanf( "%d %d %d",&a,&b,&c);
         linker[a].push_back( b );//建立关系 
         dist[a].push_back( c );//读入权值 
    }
    printf( "%.2lf\n" , dp( 1 ) );
    return 0;
}
