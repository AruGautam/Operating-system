#include<bits/stdc++.h>
using namespace std;
int pagesCount(int n ,int frames,int pages[])
{
    int pagesCounts =0;
    unordered_set<int> s;
    queue<int> q;

    for(int i =0;i<n;i++)
    {
        if(s.size()<frames)
        {
            if(s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                q.push(pages[i]);
                pagesCounts++;
            }
        }
        else{
           if(s.find(pages[i])== s.end())
           {
             int curr = q.front();
             q.pop();
             s.erase(curr);
             s.insert(pages[i]);
             q.push(pages[i]);
             pagesCounts++;
           }
        }
    }

    return pagesCounts;
}
int main()
{
    int n ,frames =3;
    cout<<"enter no : ";
    cin>>n;
    int pages[n];
    cout<<"enter pagees"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>pages[i];
    }
    cout<<"pages fault : "<<pagesCount(n,frames,pages);
}
