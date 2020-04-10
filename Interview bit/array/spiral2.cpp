vector<vector<int> > Solution::generateMatrix(int A) 
{
    vector<vector<int> > vec( A , vector<int> (A, 0)); 
    int m = A;
    int n = A;
    int total = m*n;
    int row_up = 0; 
    int row_low = 0;
    int col_up = 0; 
    int col_low = 0;
    int t=1;
    int row = 0;
    int col = 0;
    int j = 0;
    int i;
    while(total != 0)
    {
        if((row == 0) && (col == 0))
        {
            for(i = row_low; i<n-row_up; i++ )
            {
                vec[j][i] = t;
                total--;
                t++;
            }
            j = i-1;
            col_low++;
            col = 1;

        }
        else if((row == 0) && (col == 1))
        {
            for(i = col_low; i<m-col_up; i++ )
            {
                vec[i][j] = t;
                total--;
                t++;
            }            
            row_up++;
            j = i-1;
            row = 1;
        }
        else if((row == 1) && (col == 1))
        {
            for(i = n-row_up-1; i>= (0 + row_low); i-- )
            {
                vec[j][i] = t;
                total--;
                t++;
            }
            col = 0;
            col_up++;
            j=i+1;
        }
        else
        {
            for(i = m-col_up-1; i>=(0+col_low); i-- )
            {
                vec[i][j] = t ;
                total--;
                t++;
            }
            row = 0;
            row_low++;
            j=i+1;
        }
        
    }
    return vec;

}

a
