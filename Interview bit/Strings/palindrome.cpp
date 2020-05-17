int Solution::isPalindrome(string A) 
{
    int n = A.size();
    string s;
    for(int i = 0; i<n; i++)
    {
        if((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') ||(A[i] >= 48 && A[i] <= 57))
        {
            if(A[i] > 96)
            {
                s.push_back(A[i]-32);
            }
            else    
            {
                s.push_back(A[i]);
            }
        }
    }

    for(int i=0; i<(s.size()/2); i++)
    {
        if(s[i] != s[s.size()-1-i])
        {
            return 0;
        }
        
    }
    return 1;
}
