#include<stdio.h>

struct data{
    char ftNam[20];
    char ltNam[20];
    float ssc;
    float hsc;
    char phone[15];
};

int main(){
    int n;

    scanf("%d",&n);
    struct data datas[n];
    
    // Input loop
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %f %f %s", datas[i].ftNam, datas[i].ltNam, 
              &datas[i].ssc, &datas[i].hsc, datas[i].phone);
    }

    // Output loop - check eligibility and print
    for (int i = 0; i < n; i++)
    {
        float sum = datas[i].ssc + datas[i].hsc;  // Calculate sum for each student
        
        if (sum >= 9.70 && datas[i].hsc >= 4.75 && datas[i].ssc >= 4.75)
        {
            printf("%s %s\n", datas[i].ltNam, datas[i].ftNam);
        }
    }
    
    return 0;
}