#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    bool poly1[100];
    bool poly2[100];
    bool poly3[100];
    bool poly4[100];
    bool poly5[100];
    int n,k,l,m,o;
    cout << "Enter the degree of the highest polynomial\n";
    cin >> n;
    n++;
    l = n;
    cout << "Enter the coefficients of highest degree polynomial\n";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> poly1[i];
    }
    cout << "The coefficients of the first polynomial are: \n";
    for(int i = 0 ; i < n ; i++)
    {
        poly3[i] = poly1[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << poly1[i] << endl;
    }
    cout << "Enter the degree of the second polynomial\n";
    cin >> k;
    k++;
    cout << "Enter the coefficients of lowest degree polynomial\n";
    for(int i = 0 ; i < k ; i++)
    {
        cin >> poly2[i];
    }
    cout << "The coefficients of the second polynomial are: \n";
    for(int i = 0 ; i < k ; i++)
    {
        cout << poly2[i] << endl;
    }
    for(int i = 0 ; i < k ; i++)
    {
        poly4[i] = poly2[i];
    }
    if(n > k)
    {
        while(l >= k)
        {
            for(int i = k ; i < l ; i++)
            {
                poly2[i] = 0;
            }
            for(int i = 0 ; i < l ; i++)
            {
                poly3[i] = poly3[i] - poly2[i];
            }
            for(int i = 0 ; i < n ; i++)
            {
                if(poly3[0] == 0)
                {
                    for(int j = 0 ; j < l-1 ; j++)
                    {
                        poly3[j] = poly3[j+1];
                    }
                    l--;
                }
            }
            if(l <= 0)
            {
                for(int i = 0 ; i < k ; i++)
                {
                    cout << poly2[i] << endl;
                }
                break;
            }
            else if(l == 1)
            {
                cout << "GCD is 1 \n";
                break;
            }
        }
    }
    cout << "\n";
    m = k;
    if(l < k)
    {
        while(m >= l)
        {
            for(int i = l ; i < m ; i++)
            {
                poly3[i] = 0;
            }
            for(int i = 0 ; i < m ; i++)
            {
                poly4[i] = poly4[i] - poly3[i];
            }
            for(int i = 0 ; i < k ; i++)
            {
                if(poly4[0] == 0)
                {
                    for(int j = 0 ; j < m-1 ; j++)
                    {
                        poly4[j] = poly4[j+1];
                    }
                    m--;
                }
            }
            if(m <= 0)
            {
                for(int i = 0 ; i < l ; i++)
                {
                    cout << poly3[i] << endl;
                }
                break;
            }
            else if(m == 1)
            {
                cout << "GCD is 1 \n";
                break;
            }
        }
    }
    cout << "\n";
    o = l;
    while(o >= m && o != 0)
    {
        o = l;
        for(int i = m ; i < o ; i++)
        {
            poly4[i] = 0;
        }
        for(int i = 0 ; i < o ; i++)
        {
            poly5[i] = poly3[i] - poly4[i];
        }
        for(int i = 0 ; i < l ; i++)
        {
            if(poly5[0] == 0)
            {
                for(int j = 0 ; j < o-1 ; j++)
                {
                    poly5[j] = poly5[j+1];
                }
                o--;
            }
        }
        cout << "\n";
        if(o <= 0)
        {
            for(int i = 0 ; i < m ; i++)
            {
                cout << poly4[i] << endl;
            }
            break;
        }
        else
        {
            for(int i = 0 ; i < l ; i++)
            {
                poly3[i] = poly4[i];
                l = m;
            }
            for(int i = 0 ; i < m ; i++)
            {
                poly4[i] = poly5[i];
                m = o;
            }
        }
    }
    return 0;
}
