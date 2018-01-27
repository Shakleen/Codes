int D[1000010];
void DivisorGenerate(){
    int i,j,val,N,M,count;
    D[1]=1;                     //1 has only factor that is itself
    for(i=2;i<=1000000;i++){    //Generates from 2 to 1000000
        N=M=i;
        val=sqrt(N)+1;
        for(j=0;primes[j]<val;j++){
            if(M%primes[j]==0){
                count=0;
                while(M%primes[j]==0){
                    M/=primes[j];
                    count++;
                }
                D[N]=(count+1)*D[M];//According to property
                break;
            }
        }
        if(M==N){		//Special Case if N equal prime
            D[N]=2;     //Prime number has only 2 factors
        }
    }
}
