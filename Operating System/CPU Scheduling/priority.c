#include <stdio.h>
void Priority(int n,int P[],int at[],int bt[],int pr[],int ct[],int tat[],int wt[]){
    int i,completed=0,current_time=0;
    int is_completed[100]={0};
    while(completed!=n){
        int index=-1;
        int highest_priority=100000;
        for(i=0;i<n;i++){
            if(at[i]<=current_time&&is_completed[i]==0){
                if(pr[i]<highest_priority){
                    highest_priority=pr[i];
                    index=i;
                }
                else if(pr[i]==highest_priority){
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
        else current_time++;
    }
    float AvgTAT=0,AvgWT=0;
    printf("\npid\tat\tbt\tPriority\tct\ttat\twt\n");
    for(i=0;i<n;i++){
        AvgTAT+=tat[i];
        AvgWT+=wt[i];
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",P[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time : %f\n",AvgTAT/n);
    printf("Average Waiting Time : %f\n",AvgWT/n);
}
int main(){
    int n,i;
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    int P[n],at[n],bt[n],pr[n],ct[n],tat[n],wt[n];
    for(i=0;i<n;i++){
        P[i]=i+1;
        printf("Enter Arrival Time for Process %d: ",P[i]);
        scanf("%d",&at[i]);
        printf("Enter Burst Time for Process %d: ",P[i]);
        scanf("%d",&bt[i]);
        printf("Enter Priority (Lower number = higher priority) for Process %d: ",P[i]);
        scanf("%d",&pr[i]);
    }
    Priority(n,P,at,bt,pr,ct,tat,wt);
    return 0;
}


