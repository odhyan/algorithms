//Maximal subarray in O(n) time 
#include<iostream>

int max_sum(int *vector, int len)
{
    int best = 0, current = 0;
    int i = 0;
    for(i = 0; i < len; ++i)
    {
        current += *(vector + i);
        if(current < 0)
        {
            current = 0;
        }
        if(current>best)
			best=current;
    }
    return best;
}

int main()
{
	int vector[]={2,5,3,-11,1,9,-12,-19};
	cout<<max_sum(vector,8);
}	