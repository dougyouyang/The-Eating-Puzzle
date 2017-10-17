//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
int bucket[100], c, b;
int ok[30], lar=0;

int check(int n, int a[])
{
    if(a[n])
        return 1;
    return 0;
}

void eat(int comb, int num, int p)
{
    int i;
    if(comb==2)
        for(i=0;i<b;i++)
            ok[i]=1;
    ok[p]=0;
    
    
    if(comb==2 && num==391){
        
    }
    for(i=0;i<b;i++)
    {
        if(num>lar && num<=c)
            lar=num;
        if(num>c)
        {
            ok[p]=1;
            return;
        }
        if(check(i,ok) && comb<=b)
        {
            num+=bucket[i];
            eat(comb+1, num, i);
            num-=bucket[i];
        }
    }
    ok[p]=1;
}

int main()
{
    int i;
    
    cin >> c >> b;
    for(i=0;i<b;i++)
        cin >> bucket[i];
    
    for(i=0;i<b;i++)
        eat(2,bucket[i],i);
    
    cout << lar << endl;
    
    return 0;
}
