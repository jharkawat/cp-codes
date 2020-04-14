// bhai tagda socha hai bande ne manna padega


void swap(int i,int j, vector<int>&a){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void quicksort(vector<int>&arr, int left, int right){
    int min = (left+right)/2;

    int i = left;
    int j = right;
    int pivot = arr[min];

    while(left<j || i<right)
    {
        while(arr[i]<pivot)
        i++;
        while(arr[j]>pivot)
        j--;

        if(i<=j){
            swap(i,j,arr);
            i++;
            j--;
        }
        else{
            if(left<j)
                quicksort(arr, left, j);
            if(i<right)
                quicksort(arr,i,right);
            return;
        }
    }
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n=arrive.size();
    int count=1,i=1,j=0;
    quicksort(arrive,0,n-1);
    quicksort(depart,0,n-1);
    while(i<n && j<n)
    {if(arrive[i]<depart[j])
    {count++;
    i++;
    if(count>K)
    return false;}
        else
        {count--;
        j++;}
    }
    
    return true;
}
