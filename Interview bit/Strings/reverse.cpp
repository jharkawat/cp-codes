string Solution::solve(string A) 
{
    string ans;
    string word;
    for(int i = A.size()-1;i>-1; i--)
    {
        if(A[i] != ' ') 
        {
            word.push_back(A[i]);
        }
        else if(word.size() != 0)
        {
            reverse(word.begin(), word.end());
            ans =  ans + word;
            ans = ans + " ";
            word.erase();
        }
    }
    if(word.size() != 0)
    {
        reverse(word.begin(), word.end());
        ans = ans + word;
    }
    return ans;
}
