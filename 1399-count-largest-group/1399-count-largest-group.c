int sum(int k){
    int sum=0;
    while(k){
        sum=sum+(k%10);
        k=k/10;
    }
    return sum;
}

int max(int n,int* k){
    int max=-1;
    for(int i=0;i<n;i++){
        if(k[i]>max){
            max=k[i];
        }
    }

    int freq=0;
    for(int i=0;i<n;i++){
        if(k[i]==max){
            freq++;
        }
    }
    return freq;
}

int countLargestGroup(int n){
    int *grpsize;
    grpsize=(int*)calloc(n,sizeof(int));

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(sum(j)==i){
                grpsize[i-1]+=1;
            }
        }
    }

    return max(n,grpsize);
}