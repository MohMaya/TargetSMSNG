// Stock Buy Sell to Maximize Profit

#include <iostream>
using namespace std;


struct Interval
{
    int buy;
    int sell;
};

void stockBuySell(int price[], int n)
{
    if (n == 1)
        return;

    int count = 0;
    Interval sol[n/2 + 1];
    int i = 0;
    while (i < n-1)
    {
        while ((i < n-1) && (price[i+1] <= price[i]))
            i++;

        if (i == n-1)
            break;

        sol[count].buy = i++;
        while ((i < n) && (price[i] >= price[i-1]))
            i++;
        sol[count].sell = i-1;
        count++;
    }

    if (count == 0)
        cout<<-1;
    else
    {
       for (int i = 0; i < count; i++)
          cout<<sol[i].buy<<"\t"<<sol[i].sell<<endl;
    }

    return;
}

int main()
{
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price)/sizeof(price[0]);
    stockBuySell(price, n);
    return 0;
}
