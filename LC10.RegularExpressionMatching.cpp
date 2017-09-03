class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector< vector<int>> match;
        for(int i=0;i<n;i++)
        {
            vector<int> v(m,0);
            match.push_back(v);
        }
           // match.push_back(vector<int> v (m,0));
        
        if(p[0]==s[0]||p[0]=='.')
            match[0][0]=1;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<m-1;j++)
            {
                if(match[i][j])
                {
                    if(p[i+1]=='.')
                        match[i][j+1]=1;
                    if(p[i+1]=='*')
                    {//todo deal with *
                        
                        match[i+1][j+1]=1;
                    }
                    else if(p[i+1]==s[j+1])
                    {
                        match[i][j+1]=1;
                    }
                }
            }
            
            
        }
        
        
        return match[n-1][m-1];
        
        
        
        
    }
};