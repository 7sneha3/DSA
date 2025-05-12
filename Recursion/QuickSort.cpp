void quickSort(vector<int>& a, int start, int end) {
        if(start >= end) return;
        
        int pivot = end;
        int i = start - 1;
        int j = start;
        
        while(j < pivot){
            if(a[j] < a[pivot]){
                ++i;
                swap(a[j], a[i]);
            }
            ++j;
        }
        ++i; //i is the right position for pivot ele
        swap(a[i], a[pivot]);
        quickSort(a, start, i-1);
        quickSort(a, i+1, end);
    }
//TC => worst case - O(n^2)
//TC => avg case - O(n log n)
