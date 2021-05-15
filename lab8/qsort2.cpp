#include<iostream>
#include<algorithm>
void vev(int*a,int len){
    int i;
    std::cout<<"\n";
    for (i=0;i<len;i++){
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}
void sort1(int* a, int len){
    int il,ir,basa;
    float srav;
    if (len<=1){
        return;
    }

    basa=len/2;
    srav=a[basa]+0.5;
    il=0;
    ir=len-1;
    while(ir>il){
        while((ir>il)&&(a[ir]>srav)){
            ir-=1;
        }
        while((ir>il)&&(a[il]<srav)){
            il+=1;
        }
        std::swap(a[ir],a[il]);

    }
    sort1(a,il);
    sort1(&(a[il]),len-il);
}

 int main(){
     int i;
     int a[]={2 ,7, 9 ,3 ,4 ,6 ,5 ,1 ,1,10,18};
     sort1(a,11);
    vev(a,11);

    return 0;
 }
