int longestMountain(int *arr, int n)
{
        int length = 0;
        for(int i=1;i<n-1;i++)
        {
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])) 
            {
                int st = i;
                int et = i;
                while( st>0 && arr[st] > arr[st-1])
                {
                    st--; 
                    
                }
                while( et<n-1 && arr[et] > arr[et+1] )
                {
                    et++; 
                }
                length = max(length,(et-st+1));
                i = et;
            }
        }
        return length;
}
