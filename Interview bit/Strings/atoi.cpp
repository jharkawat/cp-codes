int Solution::atoi(const string A) 
{
    int start, end;
    int flag = 0;
    int minus = 0;
    int count = 1;
    int stag = 1;
    int plus = 0;
    long int ans = 0;
    for(int i = 0; i<A.size(); i++)
    {
        if(((A[i] >= '0') && (A[i] <= '9')) || (A[i] == '-') ||(A[i] == '+'))
        {
            flag = 1;
            //cout << flag << endl;
        }
        if((flag == 0) && ((A[i] != ' ')))
        {
            return 0;
        }
        if((flag == 1) && ((A[i] == ' ') || (A[i] < '0') || (A[i] > '9')))
        {
            if((A[i] != '-') && (A[i] != '+'))
            {
                return 0;
            }
        }
        if(flag && stag)
        {
            stag = 0;
            if((A[i] == '-') || (A[i] == '+'))
            {
                start = i+1;
                minus = 1;
                if((A[i] == '+'))
                {
                    minus = 0;
                    plus = 1;
                }
            }
            else
            {
                start = i;
            }
        }
        if(flag && (A[i] != '-') && (A[i] != '+'))
        {
            if(((A[i+1] >= '0') && (A[i+1] <= '9')))
            {
                count++;
            }
            else
            {
                end = i+1;
                break;
            }
        }
    }
    //cout << start << " " << end << " " << count << " " << endl;
    if(count > 10)
    {
        if(minus)
        {
            return INT_MIN;
        }
        else 
        {
            return INT_MAX;
        }
    }
    else if(count<=10)
    {
        int m =0;
        for(int k = end-1; k >= start; k--)
        {
            ans = ans + (A[k]-'0')*pow(10,m);
            m++;
        }
        if(minus)
        {
            if(ans > 2147483647)
            {
                return INT_MIN;
            }
            else
            {
                return (-ans);
            }
        }
        else 
        {
            if(ans > 2147483647)
            {
                return INT_MAX;
            }
            else
            {
                return ans;
            }
        }
    }
}
