#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char p[10][10],t[10];
    int at[10],bt[10],st[10],ct[10],tat[10],wt[10],i=0,j=0,n,temp=0;
    int  atat=0,awt=0;

    printf("enter the number of processes:\n");
    scanf("%d",&n);

    printf("enter the pnme,at,bt\n");
    for( i =0;i<n;i++)
    {
        scanf("%s%d%d",p[i],&at[i],&bt[i]);
    }
    for(i =0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(at[i]<at[j])
            {
                temp = at[i];
                at[i]= at[j];
                at[j]=temp;

                temp = bt[i];
                bt[i]= bt[j];
                bt[j]=temp;

                strcpy(t,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],t);

            }
        }
    }
//ct[0]=at[0]+bt[0];
    for(i =0;i<n;i++)
    {
        if(i==0)
            st[i]=at[i];
        else
            st[i]= ct[i-1];
        wt[i]= st[i]-at[i];
        ct[i]= st[i]+bt[i];
        tat[i]= ct[i]-at[i];

    }

    printf("\npname arrTime Bursttime waittime starttime \t tat\tct");
    /*for(int i =0;i<n;i++)
    {
        printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d",p[i],at[i],bt[i],st[i],wt[i],tat[i],ct[i]);
        atat+= tat[i];
        awt+= wt[i];
    }*/
    for(i=0;i<n;i++)
    {
        printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d",p[i],at[i],bt[i],wt[i],st[i],tat[i],ct[i]);
        atat+=tat[i];
        awt+=wt[i];
    }
    printf("\n");
    printf("\navg wt = %f\n",(float)awt/n);
    printf("\ntat avg = %f\n",(float)atat/n);
}
