template <class Type>
void Merge(Type a[],Type t[],int l,int mid,int r){
    int i = l,j = mid+1;
    int k = 0;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            t[k++]=a[i++];
        }
        else {
            t[k++]=a[j++];
        }
    }
    while(i<=mid)
        t[k++]=a[i++];
    while(j<=r)
        t[k++]=a[j++];
    for(int i = 0; i < k; ++i){
        a[i+l] = t[i];
    }
}
template <class Type>
void MergeSort(Type a[],Type t[],int l,int r){
    if(l>=r)
        return;
    int mid = (l+r)/2;
    MergeSort(a,t,l,mid);
    MergeSort(a,t,mid+1,r);
    Merge(a,t,l,mid,r);
}
