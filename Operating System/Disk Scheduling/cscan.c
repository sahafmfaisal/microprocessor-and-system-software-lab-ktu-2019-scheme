#include <stdio.h>
#include <stdlib.h>

void cscan(int requests[],int numRequests,int initialHead,int totalCylinders) {
    int totalSeekTime=0;
    int currentHead=initialHead;

    for (int i=0;i<numRequests-1;i++) {
        for (int j=0;j<numRequests-i-1;j++) {
            if (requests[j]>requests[j+1]) {
                int temp=requests[j];
                requests[j]=requests[j+1];
                requests[j+1]=temp;
            }
        }
    }

    printf("\nC-SCAN Disk Scheduling:\n");
    printf("Request Sequence: ");
    for (int i=0;i<numRequests;i++) {
        printf("%d ",requests[i]);
    }
    printf("\n");

    printf("Head Movement:\n");
    printf("%d",currentHead);

    int i;
    for (i=0;i<numRequests;i++) {
        if (requests[i]>=currentHead) {
            break;
        }
    }

    for (int j=i;j<numRequests;j++) {
        totalSeekTime+=abs(currentHead-requests[j]);
        currentHead=requests[j];
        printf(" -> %d",currentHead);
    }

    if (currentHead!=totalCylinders-1) {
        totalSeekTime+=abs(currentHead-(totalCylinders-1));
        currentHead=totalCylinders-1;
        printf(" -> %d",currentHead);
    }

    totalSeekTime+=currentHead;
    currentHead=0;
    printf(" -> %d",currentHead);

    for (int j=0;j<i;j++) {
        totalSeekTime+=abs(currentHead-requests[j]);
        currentHead=requests[j];
        printf(" -> %d",currentHead);
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
    for (int i=0;i<numRequests; i++) {
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

    cscan(requests,numRequests,initialHead,totalCylinders);
    return 0;
}


