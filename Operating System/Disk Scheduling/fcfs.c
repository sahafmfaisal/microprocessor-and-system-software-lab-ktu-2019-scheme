#include <stdio.h> 
#include <stdlib.h>

void fcfs(int requests[],int numRequests,int initialHead) {
    int totalSeekTime=0;
    int currentHead=initialHead;

    printf("\nFCFS Disk Scheduling:\n");
    printf("Request Sequence: ");
    for (int i=0;i<numRequests;i++) {
        printf("%d ",requests[i]);
    }
    printf("\n");

    printf("Head Movement:\n");
    printf("%d",currentHead);

    for (int i=0;i<numRequests;i++) {
        int seekTime=abs(requests[i]-currentHead);
        totalSeekTime+=seekTime;
        printf(" -> %d",requests[i]);
        currentHead=requests[i];
    }

    printf("\nTotal Seek Time: %d\n",totalSeekTime);
}

int main() {
    int numRequests;
    int initialHead;
    int totalCylinders;

    printf("Enter the total number of cylinders: ");
    scanf("%d",&totalCylinders);

    if (totalCylinders<=0) {
        printf("Invalid total number of cylinders.\n");
        return 1;
    }

    printf("Enter the number of disk requests: ");
    scanf("%d",&numRequests);

    if (numRequests<=0) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    int requests[numRequests];

    printf("Enter the disk request sequence (values between 0 and %d):\n",totalCylinders-1);
    for (int i=0;i<numRequests;i++) {
        printf("Request %d: ",i+1);
        scanf("%d",&requests[i]);
        if (requests[i]<0 || requests[i]>=totalCylinders) {
            printf("Invalid request! Cylinder number must be between 0 and %d.\n",totalCylinders-1);
            return 1;
        }
    }

    printf("Enter the initial head position (between 0 and %d): ",totalCylinders-1);
    scanf("%d",&initialHead);
    if (initialHead<0 || initialHead>=totalCylinders) {
        printf("Invalid initial head position! Must be between 0 and %d.\n",totalCylinders-1);
        return 1;
    }

    fcfs(requests,numRequests,initialHead);
    return 0;
}


