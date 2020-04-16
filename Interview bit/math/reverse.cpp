int Solution::reverse(int A) 
{
    long int ans;
    long int mid;
    if(A<0)
    {
        A = A*(-1);
        string s = to_string(A);
        std::reverse(s.begin(),s.end());
        mid = std::stol(s);
        //cout << "mid :" << mid << endl;
        if(mid > 2147483647)
        {
            return 0;
        }
        ans = (-1)*mid;
    }
    else
    {
        string s = to_string(A);
        std::reverse(s.begin(),s.end());
        mid = std::stol(s);
        if(mid > 2147483647)
        {
            return 0;
        }
        ans = mid;
    }
    return (int)ans;

}
