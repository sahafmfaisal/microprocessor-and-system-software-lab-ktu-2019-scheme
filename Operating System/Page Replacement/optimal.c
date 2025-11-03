#include <stdio.h>
int main(){
    int no_of_frames,no_of_pages,frames[10],Pages[30];
    int i,j,k,faults=0;
    printf("Enter number of frames:");
    scanf("%d",&no_of_frames);
    printf("Enter number of pages:");
    scanf("%d",&no_of_pages);
    printf("Enter the page reference string:");
    for(i=0;i<no_of_pages;i++)scanf("%d",&Pages[i]);
    for(i=0;i<no_of_frames;i++)frames[i]=-1;
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
            int replace_index=-1;
            for(j=0;j<no_of_frames;j++){
                if(frames[j]==-1){
                    replace_index=j;
                    break;
                }
            }
            if(replace_index==-1){
                int farthest=i+1,pos=-1;
                for(j=0;j<no_of_frames;j++){
                    int found=0;
                    for(k=i+1;k<no_of_pages;k++){
                        if(frames[j]==Pages[k]){
                            if(k>farthest){
                                farthest=k;
                                pos=j;
                            }
                            found=1;
                            break;
                        }
                    }
                    if(found==0){
                        pos=j;
                        break;
                    }
                }
                replace_index=pos;
            }
            frames[replace_index]=Pages[i];
            faults++;
        }
        printf("Page %d -> ",Pages[i]);
        for(k=0;k<no_of_frames;k++){
            if(frames[k]!=-1)printf(" %d ",frames[k]);
            else printf(" - ");
        }
        printf("\n");
    }
    printf("\nTotal Page faults=%d\n",faults);
    return 0;
}