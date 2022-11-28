#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include<array>

using namespace std;
bool visited[1002][1002];
char grid[1002][1002];
int n;
int area=0;
int tarea=0;
int perimeter=0;
int tperimeter=0;
void floodfill(int i, int j){
    if(grid[i][j]=='.' || i<0 || i>=n || j<0 || j>=n) {
        tperimeter++;
        return;
    }
    
    else if(visited[i][j])
        return;
    
    
    tarea++;
    visited[i][j]=true;
    floodfill(i+1,j);
    floodfill(i-1,j);
    floodfill(i,j-1);
    floodfill(i,j+1);
    
}



int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
  
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tarea=0;
            tperimeter=0;
            if(!visited[i][j] && grid[i][j]=='#'){
                
                floodfill(i,j);
                if(tarea>area){
                    area=tarea;
                    perimeter=tperimeter;
                }
                else if(tarea==area){
                    if(perimeter>tperimeter){
                        perimeter=tperimeter;
                        area=tarea;
                    }
                }
                
            }
            
        }
    }
    cout << area << " " << perimeter << endl;
    
    
    
    
    return 0;
}
