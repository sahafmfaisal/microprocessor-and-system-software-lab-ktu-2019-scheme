#include <stdio.h>
void sjf(int n,int p[],int at[],int bt[],int ct[],int tat[],int wt[]){
    int i,j,temp;
    int completed=0;
    int current_time=0;
    int is_completed[100]={0};
    while(completed!=n){
        int index=-1;
        int min_bt=100000;
        for(i=0;i<n;i++){
            if(at[i]<=current_time&&is_completed[i]==0){
                if(bt[i]<min_bt){
                    min_bt=bt[i];
                    index=i;
                }
                else if(bt[i]==min_bt){
                    if(at[i]<at[index]){
                        index=i;
                    }
                }
            }
        }
        if(index!=-1){
            ct[index]=current_time+bt[index];
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];
            is_completed[index]=1;
            completed++;
            current_time=ct[index];
        }
        else{
            current_time++;
        }
    }
    float AvgTAT=0,AvgWT=0;
    printf("\np\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        AvgTAT+=tat[i];
        AvgWT+=wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time : %f\n",AvgTAT/n);
    printf("Average Waiting Time : %f\n",AvgWT/n);
}
int main(){
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter Arrival time for Process %d: ",p[i]);
        scanf("%d",&at[i]);
        printf("Enter Burst time for Process %d: ",p[i]);
        scanf("%d",&bt[i]);
    }
    sjf(n,p,at,bt,ct,tat,wt);
    return 0;
}
