#include <iostream>
#include <cmath>

using namespace std;

bool canPlace(int mat[][9],int i,int j, int n, int number){
    for(int x=0;x<n;x++){
        if(mat[x][j]==number||mat[i][x]==number){
            return false;
        }
    }
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;

    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;

}


bool solveSudoku(int mat[][9],int n,int i,int j){
    ///base case
    if(i==n){
        ///print matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }


        return true;
    }
    ///what if we reach the end of a row
    if(j==n){
        return solveSudoku(mat,n,i+1,0);
    }
    ///skip the already filled cells
   if(mat[i][j]!=0){
        return solveSudoku(mat,n,i,j+1);

   }
    ///recursive case
    for(int number=1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            mat[i][j]=number;
            bool couldWeSolve=solveSudoku(mat,n,i,j+1);
            if(couldWeSolve==true){
                return true;
            }
        }
    }

    ///backtrack
    mat[i][j]=0;
    return false;



}

int main()
{
    int mat[9][9]=
    {
                    {5,8,0,0,6,9,4,0,0},
                    {0,0,0,0,2,0,0,0,7},
                    {0,0,0,5,1,0,0,0,8},
                    {0,4,0,0,0,0,0,0,6},
                    {1,3,0,0,0,0,0,2,5},
                    {7,0,0,0,0,0,0,9,0},
                    {2,0,0,0,5,1,0,0,0},
                    {3,0,0,0,7,0,0,0,0},
                    {0,0,1,4,9,0,0,7,2}



    };
        solveSudoku(mat,9,0,0);
    return 0;
}
