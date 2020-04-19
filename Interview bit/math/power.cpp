int Solution::isPower(int A) 
{
    int sr = sqrt(A);
    //cout << sr << endl;
    int j = -1;
    int B = A;
    if(A==1 || A==0)
    {
        return true;
    }
    if(A<4)
    {
        return false;
    }
    //cout << "In here" << endl;
    for(int i =2; i<=sr; i++)
    {
        //cout << "i : " << i << endl;
        A = B;
        if(A%i == 0)
        {
            j = i;
            //cout << "j : " << j << endl;
            
            while((A>1) && (j != -1))
            {
                if(A%j != 0)
                {
                    //cout << "In here " << i << endl;
                    j = -1;
                }
                A = A/j;
            }
            if(j != -1)
            {
                return true;
            }

        }
    }
    if(j == -1)
    {
        return false;
    }

    return true;
}
    
