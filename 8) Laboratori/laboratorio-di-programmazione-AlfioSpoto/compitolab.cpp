#include <iostream>

using namespace std;

int interazione(bool interazione){
    if(interazione){
        return 1;
    }
    else return -1;
}


int popolaritàmax(int *I,int *T,int n){

    const float a=0.66;
    float pmax=0.0;
    int ptmax=T[3];

    for(int i=3;i<n;++i){
        float s=(((1/4.0)*I[i-3])+((1/3.0)*I[i-2])+((1/2.0)*I[i-1])+I[i]);

        float f=0.0;
        for(int j=i;j>i;--j){ 
            f+=(T[j]-T[--j]);
        }
        f*=1/ (float)n;

        float Pt= a*s+(1-a)*f;

        if(Pt>pmax){
            pmax=Pt;
            ptmax=T[i];
        }
    }
    return ptmax;
}

double ST(int timestamp[],int N){
    double S=0;

    for(int i=0;i<N;++i){
        int c=0;
        int c1=4;
        while(c<4){
            if(c1!=1){
            S+=(double) 1/c1 + timestamp[i];
            }
            else{S+=timestamp[i];}
            ++c;
            --c1;
        }
    }
    return S;
}

double FT(int timestamp[],int N){
    double f=0;
    for(int i=N-1;i<=0;++i){
        if(i!=0)
        f+=(double)1/N *(timestamp[i]-timestamp[--i]);
    }
    return f;
}

int main(){

    int N=10;

    bool like;

    srand(time(NULL));

    int timestamp[N]={10,23,30,35,40,45,50,55,60,65};
    int interaction[N];
    for(int i=0;i<N;++i){
        interaction[i]=0;
    }

    for(int i=0;i<N;++i){
        int c=0;
        
        while(1){
            like=rand()%2;
            interaction[i]+=interazione(like);
            ++c;
            if(c==10){
                break;
            }
        }
    }

    cout << popolaritàmax(interaction,timestamp,N);


}