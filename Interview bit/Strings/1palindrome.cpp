bool ispalindrome(string str)
{
    int m = str.size();
    for(int i = 0; i<m/2; i++)
    {
        if(str[i] != str[m-i-1])
        {
            return false;
        }
    }
    return true;
}

int Solution::solve(string A) 
{
    int m = A.size();
    for(int i = 0; i<m; i++)
    {
        string str;
        str = A.substr(0,m-i);
        if(ispalindrome(str))
        {
            return i;
        }
    }
    return (m-1);
}

