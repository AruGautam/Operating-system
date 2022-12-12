#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pagesCount(int n ,int frames,int pages[])
{
    int count=0;
    unordered_map<int,int> mp;
    unordered_set<int> s;

    for(int i =0;i<n;i++)
    {
        if(s.size()<frames)
        {
            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                count++;
            }
            mp[pages[i]]=i;
        }
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int lru = INT_MAX,val;
                for(auto it = s.begin(); it!=s.end();it++)
                {
                    if(mp[*it]<lru)
                    {
                        lru = mp[*it];
                        val= *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                count++;
            }
            mp[pages[i]]=i;
        }

    }
    return count;

}

int main()
{
    int n ,frames;
    cout<<"enter the number of pages: ";
    cin>>n;

    int pages[n];
    cout<<"enter the pages: "<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>pages[i];
    }
    cout<<"\nenter frames size: ";
    cin>>frames;

    cout<<"total page faults are : "<<pagesCount(n,frames,pages)<<endl;
    return 0;
}
