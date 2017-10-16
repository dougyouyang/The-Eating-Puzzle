/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>


*/

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
