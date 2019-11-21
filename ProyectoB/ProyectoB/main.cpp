//
//  main.cpp
//  ProyectoB
//
//  Created by Antonio Hernández Ruiz on 11/4/19.
//  Copyright © 2019 Antonio Hernández Ruiz. All rights reserved.
//

#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int N1, N2;
int Train1[2100];
int Train2[2100];
int Train3[2100];
int DP[1010][1010];

bool Buscar(int x,int y)
{
    if(DP[x][y]>0) return true;
    if(DP[x][y]<0) return false;
    
    if(Train1[x] == Train3[x+y] && Buscar(x-1,y))
    {
        DP[x][y]=1;
        return true;
    }
    
    if(Train2[y] == Train3[x+y] && Buscar(x,y-1))
    {
        DP[x][y]=1;
        return true;
    }
    
    DP[x][y] = -1;
    return false;
}

bool Funciona()
{
    for(int i=1; i <= N1+N2; i++){
        int temp;
        cin >> temp;
        Train3[i] = temp;
    }
    
    memset(DP,0,sizeof(DP));
    DP[0][0] = 1;

    return Buscar(N1,N2) ? true:false;
}

int main()
{
    while(cin >> N1 >> N2)
    {
        if(N1==0 && N2==0) break;
        
        for(int i=1; i <= N1; i++) {
            int temp;
            cin >> temp;
            Train1[i] = temp;
        }
        for(int i=1; i <= N2; i++){
            int temp;
            cin >> temp;
            Train2[i] = temp;
        }
        if(Funciona()) cout << "possible" << endl;
        else cout << "not possible" << endl;
        
    }
    return 0;
}

/*
3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0

 
 
 
 */




