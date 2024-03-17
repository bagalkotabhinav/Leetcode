#include <bits/stdc++.h>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> s;
        int n = a.size();
        s.push(a[0]);
        for(int i = 1; i < n; i++)
        {
            while(i < n && ((s.top() < 0 && a[i] < 0) || (s.top() > 0 && a[i] > 0) || (s.top() < 0 && a[i] > 0)))
            {
                s.push(a[i]);
                i++;
            }
            while(i < n)
            {
                s.push(a[i]);
                while(s.size() >= 2)
                {
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.pop();
                    if(x < 0 && y < 0 || x > 0 && y > 0 || x > 0 && y < 0)
                    {
                        s.push(y);
                        s.push(x);
                        break;
                    }
                    else{
                        if(abs(x) > abs(y))
                        s.push(x);
                        else if(abs(y) > abs(x))
                        s.push(y);
                    }
                }
                i++;
            }
        }
        vector<int> ans;
       while(!s.empty())
        {
            ans.insert(ans.begin() + 0, s.top());
            s.pop();
        }
        return ans;
    }
};