#include <stdio.h>
int findLRU(int time[],int n){
    int i,min=time[0],pos=0;
    for(i=1;i<n;i++){
        if(time[i]<min){
            min=time[i];
            pos=i;
        }
    }
    return pos;
}
int main(){
    int no_of_frames,no_of_pages,frames[10],Pages[30];
    int counter=0,time[10],flag1,flag2,i,j,pos,faults=0;
    printf("Enter number of frames:");
    scanf("%d",&no_of_frames);
    printf("Enter number of pages:");
    scanf("%d",&no_of_pages);
    printf("Enter the page reference string:");
    for(i=0;i<no_of_pages;i++)scanf("%d",&Pages[i]);
    for(i=0;i<no_of_frames;i++){
        frames[i]=-1;
        time[i]=0;
    }
    printf("\nPage Replacement Process:\n");
    for(i=0;i<no_of_pages;i++){
        flag1=flag2=0;
        for(j=0;j<no_of_frames;j++){
            if(frames[j]==Pages[i]){
                counter++;
                time[j]=counter;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0){
            for(j=0;j<no_of_frames;j++){
                if(frames[j]==-1){
                    counter++;
                    faults++;
                    frames[j]=Pages[i];
                    time[j]=counter;
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0){
            pos=findLRU(time,no_of_frames);
            counter++;
            faults++;
            frames[pos]=Pages[i];
            time[pos]=counter;
        }
        printf("Page %d -> ",Pages[i]);
        for(j=0;j<no_of_frames;j++){
            if(frames[j]!=-1)printf(" %d ",frames[j]);
            else printf(" - ");
        }
        printf("\n");
    }
    printf("\nTotal Page faults=%d\n",faults);
    return 0;
}


