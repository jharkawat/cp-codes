string Solution::convertToTitle(int A) 
{
    string s;
    while(A)
    {
        
        char ch = (A%26 + 64);
        if(A%26 == 0)
        {
            ch = 90;
            A = A -26;
        }
        s.push_back(ch);
        A = A/26;
    }
    reverse(s.begin(), s.end());
    return s;
    
}
