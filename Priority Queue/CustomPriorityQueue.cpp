#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class custom_priority_queue : public priority_queue<T,vector<T>,greater<T>>
{
    public: bool remove(const T& value)
    {
        auto it=find(this->c.begin(),this->c.end(),value);
        if(it!=this->c.end())
        {
            this->c.erase(it);
            make_heap(this->c.begin(),this->c.end(),this->comp);
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
int main() {
    custom_priority_queue<int> pq;
    int t;
    int a,b;
    cin>>t;
    while(t--)
    {
        cin>>a;
        if(a!=3)
        {
            cin>>b;
            if(a==1)
            {
                pq.push(b);
            }
            else
            {
                pq.remove(b);
            }
        }
        else
        {
            cout<<pq.top()<<endl;
        }
    }
    return 0;
}
