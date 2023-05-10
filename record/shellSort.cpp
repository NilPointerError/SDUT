template <class Type>
void InsertSort(Type a[],int n,int d){//插入排序
    for(int i=d;i<n;++i){
        for(int j=i-d;j>=0;--j){
            if(a[j]>a[j+d]){
                swap(a[j],a[j+d]);
            }
        }
    }
}
template <class Type>
void ShellSort(Type a[],int n){
    for(int d=n/2;d>=1;d/=2){
        InsertSort(a,n,d);
    }
}
