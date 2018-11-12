#include<iostream>
using namespace::std;

int findPisanoPeriod(int num)
{
    int prev_prev=0,prev=1,fibrem,pisano_period=0;
    bool found_zero;

    for(int i=2;;++i)
    {
        fibrem = prev_prev + prev;
        if(fibrem >= num)
        {
            fibrem = fibrem % num;
        }
        prev_prev = prev;
        prev = fibrem;
        pisano_period++;
        
        if(fibrem == 0)
        {
            found_zero = true;
            continue;
        }
        
        if(found_zero == true && fibrem == 1)
        {
            break; 
        }else
        {
            found_zero = false;
        }
    }
    return pisano_period;
}

int findFibonacciMod(long long n, int m)
{
    int prev=1,prev_prev=0,fibremainder;
    if(n == 1)
    {return n;}
    for(int i=2;i<=n;i++)
    {
        fibremainder = prev + prev_prev;
        if(fibremainder >= m)
        {
            fibremainder = fibremainder % m;
        }
        prev_prev = prev;
        prev = fibremainder;
        
    }

    return fibremainder;
}


int main()
{
    long long n;
    int re,interval;
    cin>>n;

    if(n == 0)
    { re = 0; }
    else
    {
        interval = findPisanoPeriod(10);
       // cout<<interval<<"\n";
        interval = (n+2)%60;
       re = findFibonacciMod(interval,10);
       if(re == 0)
       {
           re = 9;
       }
       else
       {
          re--;
       }
       
    }

    cout<<re;
    
    return 0;
}