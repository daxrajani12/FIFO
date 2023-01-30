#include<stdio.h>
int main()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0; // Declaration of variable required
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d",&n); // total number of pages in reference string
    printf("\n ENTER THE PAGE NUMBER :\n");
    for(i=1;i<=n;i++){ // accept emtire referernce string 
        scanf("%d",&a[i]);
    }
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d",&no);
    for(i=0;i<no;i++){ //initialize all page frame to 1-
        frame[i]= -1; 
    }
    j=0; // initialize page frame pointer
    printf("ref string\t page frames\n");
    for(i=1;i<=n;i++){
        printf("%d\t\t",a[i]);
        avail=0; // default value of available flag is 0
        for(k=0;k<no;k++){
            if(frame[k]==a[i]){ // input of page request is compared with existing content
                avail=1; //as page found available is turedned 1
            }
        }
        if (avail==0){ // input page required not existing in FRAME
            frame[j]=a[i]; // place page requested at jth location
            j=(j+1)%no; //update j for next cycle
            count++; //increment counter for page fault
            for(k=0;k<no;k++){
                printf("%d\t",frame[k]); //print current state of frame
            }
        }
        printf("\n");
    }
    printf("Page Fault Is %d",count);
    return 0;
}