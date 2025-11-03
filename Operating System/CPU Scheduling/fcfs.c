#include <stdio.h>
void fcfs(int n,int p[],int at[],int bt[],int ct[],int tat[],int wt[]){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i];at[i]=at[j];at[j]=temp;
                temp=bt[i];bt[i]=bt[j];bt[j]=temp;
                temp=p[i];p[i]=p[j];p[j]=temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        if(at[i]>ct[i-1])ct[i]=at[i]+bt[i];
        else ct[i]=ct[i-1]+bt[i];
    }
    float avg_tat=0,avg_wt=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    printf("\np\tat\tbt\tct\ttat\twt\n");
    for(i=0;i<n;i++)printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAverage Turnaround Time: %.2f",avg_tat/n);
    printf("\nAverage Waiting Time: %.2f\n",avg_wt/n);
}
int main(){
    int n,i;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
    for(i=0;i<n;i++){
        p[i]=i+1;
        printf("Enter Arrival time of P%d: ",p[i]);
        scanf("%d",&at[i]);
        printf("Enter Burst time of P%d: ",p[i]);
        scanf("%d",&bt[i]);
    }
    fcfs(n,p,at,bt,ct,tat,wt);
    return 0;
}
