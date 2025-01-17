#include <iostream>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    // Write your code here!
    int result = 0; 
    for(int row = 0; row < N; row ++) { 
        for(int col = 0 ; col < N; col ++) { 
            if(row + 2 >= N || col + 2 >= N)
                continue;
            int sum = 0 ;  
            for(int y = 0 ;y < 3; y ++ ){ 
                for(int x =0 ; x < 3; x ++) { 
                    sum += grid[row + y][row + x]; 
                }
            }
            result = max(result, sum); 
        }
    }
    
    cout << result;  

    return 0;
}
