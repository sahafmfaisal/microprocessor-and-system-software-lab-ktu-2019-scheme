#include<stdio.h>
int main(){
    int no_of_frames,frames[10],Pages[30];
    int i,j,k,no_of_pages,faults=0,front=0;
    printf("Enter the number of frames:");
    scanf("%d",&no_of_frames);
    printf("Enter number of pages:");
    scanf("%d",&no_of_pages);
    printf("Enter the Page reference string:");
    for(i=0;i<no_of_pages;i++){
        scanf("%d",&Pages[i]);
    }
    for(i=0;i<no_of_frames;i++){
        frames[i]=-1;
    }
    printf("\nPage Replacement Process:\n");
    for(i=0;i<no_of_pages;i++){
        int flag=0;
        for(j=0;j<no_of_frames;j++){
            if(frames[j]==Pages[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            frames[front]=Pages[i];
            front=(front+1)%no_of_frames;
            faults++;
        }
        printf("Page %d ->",Pages[i]);
        for(k=0;k<no_of_frames;k++){
            if(frames[k]==-1){
                printf(" - ");
            }else{
                printf(" %d ",frames[k]);
            }
        }
        printf("\n");
    }
    printf("\nTotal Page faults=%d\n",faults);
    return 0;
}
