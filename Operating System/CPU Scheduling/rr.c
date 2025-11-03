#include <stdio.h>
void round_robin(int n,int P[],int at[],int bt[],int ct[],int tat[],int wt[],int tq){
    int rem_bt[100],is_completed[100]={0},visited[100]={0},queue[100];
    for(int i=0;i<n;i++)rem_bt[i]=bt[i];
    int current_time=0,completed=0,front=0,rear=0;
    float AvgTAT=0,AvgWT=0;
    for(int i=0;i<n;i++)if(at[i]<=current_time&&!visited[i]){queue[rear++]=i;visited[i]=1;}
    while(completed<n){
        if(front==rear){
            current_time++;
            for(int i=0;i<n;i++)if(at[i]<=current_time&&!visited[i]){queue[rear++]=i;visited[i]=1;}
            continue;
        }
        int index=queue[front++];
        if(rem_bt[index]>tq){
            current_time+=tq;
            rem_bt[index]-=tq;
        }else{
            current_time+=rem_bt[index];
            rem_bt[index]=0;
            ct[index]=current_time;
            tat[index]=ct[index]-at[index];
            wt[index]=tat[index]-bt[index];
            is_completed[index]=1;
            completed++;
        }
        for(int i=0;i<n;i++)if(at[i]<=current_time&&!visited[i]){queue[rear++]=i;visited[i]=1;}
        if(rem_bt[index]>0)queue[rear++]=index;
    }
    printf("\npid\tat\tbt\tct\ttat\twt\n");
    for(int i=0;i<n;i++){
        AvgTAT+=tat[i];
        AvgWT+=wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",P[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time : %f\n",AvgTAT/n);
    printf("Average Waiting Time : %f\n",AvgWT/n);
}
int main(){
    int n,i,tq;
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    int P[n],at[n],bt[n],ct[n],tat[n],wt[n];
    for(i=0;i<n;i++){
        P[i]=i+1;
        printf("Enter Arrival Time for Process %d: ",P[i]);
        scanf("%d",&at[i]);
        printf("Enter Burst Time for Process %d: ",P[i]);
        scanf("%d",&bt[i]);
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
    round_robin(n,P,at,bt,ct,tat,wt,tq);
    return 0;
}


