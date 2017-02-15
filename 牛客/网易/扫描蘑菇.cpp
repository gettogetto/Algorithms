/*在N*M的草地上,提莫种了K个蘑菇,蘑菇爆炸的威力极大,兰博不想贸然去闯,而且蘑菇是隐形的.只 有一种叫做扫描透镜的物品可以扫描出隐形的蘑菇,于是他回了一趟战争学院,买了2个扫描透镜,一个 扫描透镜可以扫描出(3*3)方格中所有的蘑菇,然后兰博就可以清理掉一些隐形的蘑菇. 问:兰博最多可以清理多少个蘑菇?
注意：每个方格被扫描一次只能清除掉一个蘑菇。 
输入描述:
第一行三个整数:N,M,K,(1≤N,M≤20,K≤100),N,M代表了草地的大小;
接下来K行,每行两个整数x,y(1≤x≤N,1≤y≤M).代表(x,y)处提莫种了一个蘑菇.
一个方格可以种无穷个蘑菇.


输出描述:
输出一行,在这一行输出一个整数,代表兰博最多可以清理多少个蘑菇.*/

#include <iostream>  
#include <vector>  
  
using namespace::std ;  
  
void scan( vector<vector<int>>& vec, vector<int>& first ) {  
    for ( int i = 1; i < vec.size(); ++ i ) {  
        for ( int j = 1; j < vec[0].size(); ++ j ) {  
            int tmp = 0 ;  
            for ( int n = i; ( n < i + 3 ) && ( n < vec.size() ); ++ n ) {  
                for ( int m = j; ( m < j + 3 ) && ( m < vec[0].size() ); ++ m ) {  
                    if ( vec[n][m] > 0 ) ++ tmp ;  //统计9格宫内的蘑菇数量，一个格子最多清除一个蘑菇 
                }  
            }  
            if ( tmp > first[2] ) {  
                first[0] = i ;  
                first[1] = j ;  
                first[2] = tmp ;  
            }  
        }  
    }  
}  
  
int main() {  
    int n, m, k ;  
      
    while ( cin >> n >> m >> k ) {  
        vector<vector<int>> vec( n + 1, vector<int>( m + 1, 0 ) ) ;  
        for ( int i = 0; i < k; ++ i ) {  
            int x, y ;  
            cin >> x >> y ;  
            ++ vec[x][y] ;  
        }  
          
        vector<int> first( 3, 0 ) ;  
        vector<int> next( 3, 0 ) ;  
          
        scan( vec, first ) ;  //第一次扫描 
          
        int result = first[2] ;  
        for ( int i = first[0]; ( i < first[0] + 3 ) && ( i < vec.size() ); ++ i ) {  
            for ( int j = first[1]; ( j < first[1] + 3 ) && ( j < vec[0].size() ); ++ j ) {  
                if ( vec[i][j] > 0 ) -- vec[i][j] ;  
            }  
        }  
          
        scan( vec, next ) ;  //第二次扫描 
        result += next[2] ;  
          
        cout << result << endl ;  
    }  
      
    return 0 ;  
}  
