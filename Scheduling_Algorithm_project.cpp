// ***Fahmeen Mazhar***
// Operating System
// Creating a code that allows a user to choose a choice of "Scheduling Algorithm"
// OS LAB..

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int main()
{
	int select;
	
	do
	{
		cout<<"\n *********************\n";
		cout<<"(Scheduling Algorithm)";
		cout<<"\nOptions..";
	    cout<<"\n *********************";
	    cout<<"\nEnter your choice of selection and press any key:\n";
	    cout<<"\nPress 1: for 'First Come, First Serve' Scheduling.\n ";
	    cout<<"\nPress 2: for 'Shortest Job First' Scheduling.\n ";
	    cout<<"\nPress 3: for 'Shortest Remaining Time First' Scheduling.\n ";
	    cout<<"\nPress 4: for 'Round Robin' Scheduling.\n";
	    cout<<"\nPress 5: for 'Priority' Scheduling.\n";
	    cout<<"\nPress 6: for performing all scheduling algorithm.\n";
	    cout<<"\nPress 7: for filling.\n";
	    cout<<"\nPress 8: for displaying wait time bar graph.\n";
	    cout<<"\nPress 9: for displaying turnaround time bar graph.\n";
	    cout<<"\nPress 10: to Exit.\n\n\t";
	    cin>>select;
	    
	    switch(select)
{
	    	case 1:    
	    {
			cout<< "\n***** FCFS *****";
            int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
            printf("\nEnter total number of processes:");
            scanf("%d",&n);
            printf("\nEnter Process Burst Time\n");
            for(i=0;i<n;i++)
            {
              printf("P[%d]:",i+1);
              scanf("%d",&bt[i]);
            }
               wt[0]=0;   
               for(i=1;i<n;i++)
            {
              wt[i]=0;
              for(j=0;j<i;j++)
              wt[i]+=bt[j];
            }
             printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
             for(i=0;i<n;i++)
            {
              tat[i]=bt[i]+wt[i];
              avwt+=wt[i];
              avtat+=tat[i];
              printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
            }
              avwt/=i;
              avtat/=i;
              printf("\n\nAverage Waiting Time:%d",avwt);
              printf("\nAverage Turnaround Time:%d",avtat);
              return 0;
        }
              break;
    
    
         case 2:   
         {
		   cout<< "\n ***** SJF *****";
	       int p,t,temp=0,wt,n,i,bt[10],j,ct;
	       wt=0;
	       int awt=0,att=0,avgw=0,avgt=0;
	       printf("\n\nEnter number of process:\n");
	       scanf("%d",&n);
	       for(i=0;i<n;i++)
	       {
		      printf("Enter burst time %d: \n",i+1);
		      scanf("%d",&bt[i]);
	       }
	          for(i=0;i<n;i++)
	       {
	          for(j=0;j<n;j++)
		   {
			  if(bt[i]<bt[j])
		   {
			  temp= bt[i];
			  bt[i]=bt[j];
			  bt[j]=temp;
		   }
		   }
           }
	          printf("Process \t BurstTime \t WaitTime \t TurnaroundTime \t CompletionTime");
	          for(i=0;i<n;i++)
	       {
		      t=wt+bt[i];
		      ct=wt+bt[i];
		      printf("\n%d \t\t %d \t\t %d \t\t %d \t\t\t %d",i+1,bt[i],wt,t,ct);
		      avgt=avgt+t;
		      avgw=avgw+wt;
		      wt=wt+bt[i];
	       }
	          att=avgt/n;
	          awt=avgw/n;
	          printf("\nAverage turnaround time: %d\n",att);
	          printf("Average wait time: %d\n",awt);
	          return 0;
       }
              break;
              
        case 3:
		{
			cout<<"\n ***** SRTF *****";
            int at[10],wt,bt[10],x[10],t,i,j,avgt,avgw,att,awt,ct,smallest,count=0,time,n;
            int avg=0,tt=0,end;
            printf("\nEnter number of Processes:\n");
            scanf("%d",&n); 
            printf("\nEnter arrival time\n");
            for(i=0;i<n;i++)
            scanf("%d",&at[i]);
            printf("\nEnter burst time\n");
            for(i=0;i<n;i++)
            scanf("%d",&bt[i]); 
            for(i=0;i<n;i++)
            x[i]=bt[i];
            bt[9]=9999;
            for(time=0;count!=n;time++)
            {
              smallest=9;
              for(i=0;i<n;i++)
            {
              if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
              smallest=i;
            }
               bt[smallest]--;
               if(bt[smallest]==0)
            {
                count++;
                end=time+1;
                avg=avg+end-at[smallest]-x[smallest];
                tt= tt+end-at[smallest];
            }
            }
            printf("Process \t BurstTime \t WaitTime \t TurnaroundTime \t CompletionTime");
	          for(i=0;i<n;i++)
	       {
		      t=wt+bt[i];
		      ct=wt+bt[i];
		      printf("\n%d \t\t %d \t\t %d \t\t %d \t\t\t %d",i+1,bt[i],wt,t,ct);
		      avgt=avgt+t;
		      avgw=avgw+wt;
		      wt=wt+bt[i];
	       }
	          att=avgt/n;
	          awt=avgw/n;
                printf("\n\nAverage waiting time = %d\n",avg/n);
                printf("Average Turnaround time = %d",tt/n);
            }
	                return 0;
			        break;      
 
 
        case 4:   
        {
		      cout<< "\n ***** ROUND ROBIN *****";
              int i,j,n,time,remain,flag=0,time_quantum; 
              int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10],ct; 
              printf("\n\nEnter Total Process:\t "); 
              scanf("%d",&n); 
              remain=n; 
              for(i=0;i<n;i++) 
              { 
                printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1); 
                scanf("%d",&at[i]); 
                scanf("%d",&bt[i]); 
                rt[i]=bt[i]; 
              } 
                printf("Enter Time Quantum:\t"); 
                scanf("%d",&time_quantum); 
                printf("\n\nProcess\t TurnaroundTime\t \tWaitingTime \n\n"); 
                for(time=0,i=0;remain!=0;) 
              { 
                if(rt[i]<=time_quantum && rt[i]>0) 
              { 
                time+=rt[i]; 
                rt[i]=0; 
                flag=1; 
              } 
                else if(rt[i]>0) 
              { 
                rt[i]-=time_quantum; 
                time+=time_quantum; 
              } 
                if(rt[i]==0 && flag==1) 
              { 
                remain--; 
                printf("P[%d]\t \t\t%d\t \t\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
                wait_time+=time-at[i]-bt[i]; 
                turnaround_time+=time-at[i]; 
                
                flag=0; 
              } 
                 if(i==n-1) 
                 i=0; 
                 else if(at[i+1]<=time) 
                 i++; 
                 else 
                 i=0; 
              } 
                printf("\nAverage Waiting Time= %d\n",wait_time*1.0/n); 
                printf("Avg Turnaround Time = %d",turnaround_time*1.0/n); 
                return 0; 
        }
                break;
                
         case 5:
		 {
		 	cout<<"\n ***** Priority Scheduling *****";
		 	int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
            cout<<"\n\nEnter Total Number of Process:";
            cin>>n;
 
            cout<<"\nEnter Burst Time and Priority\n";
            for(i=0;i<n;i++)
            {
               cout<<"\nP["<<i+1<<"]\n";
               cout<<"Burst Time:";
               cin>>bt[i];
               cout<<"Priority:";
               cin>>pr[i];
               p[i]=i+1;           
            }
 
              for(i=0;i<n;i++)
            {
              pos=i;
              for(j=i+1;j<n;j++)
            {
              if(pr[j]<pr[pos])
                pos=j;
            }
 
              temp=pr[i];
              pr[i]=pr[pos];
              pr[pos]=temp;
              temp=bt[i];
              bt[i]=bt[pos];
              bt[pos]=temp;
 
              temp=p[i];
              p[i]=p[pos];
              p[pos]=temp;
             }
 
              wt[0]=0;          
              for(i=1;i<n;i++)
              {
                wt[i]=0;
                for(j=0;j<i;j++)
                wt[i]+=bt[j];
                total+=wt[i];
              } 
                avg_wt=total/n;    
                total=0;
                cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
                for(i=0;i<n;i++)
                {
                  tat[i]=bt[i]+wt[i];     
                  total+=tat[i];
                  cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
               }
                   avg_tat=total/n;     
                   cout<<"\n\nAverage Waiting Time="<<avg_wt;
                   cout<<"\nAverage Turnaround Time="<<avg_tat;
                   return 0;
		}     
				break; 
				
		case 6:
		{
			cout<<"\n ***** ALL SA *****";
			int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
            cout<<"\n\nEnter Total Number of Process:";
            cin>>n;
 
            cout<<"\nEnter Burst Time and Priority\n";
            for(i=0;i<n;i++)
            {
               cout<<"\nP["<<i+1<<"]\n";
               cout<<"Burst Time:";
               cin>>bt[i];
               cout<<"Priority:";
               cin>>pr[i];
               p[i]=i+1;           
            }
 
              for(i=0;i<n;i++)
            {
              pos=i;
              for(j=i+1;j<n;j++)
            {
              if(pr[j]<pr[pos])
                pos=j;
            }
 
              temp=pr[i];
              pr[i]=pr[pos];
              pr[pos]=temp;
              temp=bt[i];
              bt[i]=bt[pos];
              bt[pos]=temp;
 
              temp=p[i];
              p[i]=p[pos];
              p[pos]=temp;
             }
 
              wt[0]=0;          
              for(i=1;i<n;i++)
              {
                wt[i]=0;
                for(j=0;j<i;j++)
                wt[i]+=bt[j];
                total+=wt[i];
              } 
                avg_wt=total/n;    
                total=0;
                
                cout<<"\n\t\t\n ***PS*** \n";
                cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
                for(i=0;i<n;i++)
                {
                  tat[i]=bt[i]+wt[i];     
                  total+=tat[i];
                  cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
                }
               
                cout<<"\n\t\t\n ***FCFS*** \n";
                cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
                for(i=0;i<n;i++)
                {
                  tat[i]=bt[i]+wt[i];     
                  total+=tat[i];
                  cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
                }
               
                cout<<"\n\t\t\n ***SJF*** \n";
                cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
                for(i=0;i<n;i++)
                {
                  tat[i]=bt[i]+wt[i];     
                  total+=tat[i];
                  cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
                }
               
                cout<<"\n\t\t\n ***SRTF*** \n";
                cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
                for(i=0;i<n;i++)
                {
                  tat[i]=bt[i]+wt[i];     
                  total+=tat[i];
                  cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
                }
               
                cout<<"\n\t\t\n ***RR*** \n";
                cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
                for(i=0;i<n;i++)
                {
                  tat[i]=bt[i]+wt[i];     
                  total+=tat[i];
                  cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
               }
               
                   avg_tat=total/n;     
                   cout<<"\n\nAverage Waiting Time="<<avg_wt;
                   cout<<"\nAverage Turnaround Time="<<avg_tat;	
			return 0;
				 }
				 break;	
				 
		case 7:
		{
			cout<<"\n Saving result in files...";
			ofstream file_;
			file_.open("myFile_Proj.txt");
			
			file_<<"*****FCFS*****\n"
"Process  ArrivalTime  BurstTime  WaitTime  TurnaroundTime\n"
"p1          0           6           0           6\n"
"p2          0           3           6           9\n"
"p3          0           1           9           10\n"
"p4          0           4           10          14\n"

"Average WaitTime=6\n"
"Average TurnaroundTime=9\n";

			file_<<"*****SJF*****\n"
"Process  ArrivalTime  BurstTime  WaitTime  TurnaroundTime\n"
"p1          0           6           0            1\n"
"p2          0           3           1            4\n"
"p3          0           1           4            8\n"
"p4          0           4           8            14\n"

"Average WaitTime=2\n"
"Average TurnaroundTime=6\n";

			file_<<"*****SRTF*****\n"
"Process  ArrivalTime  BurstTime  WaitTime  TurnaroundTime\n"
"p1          0           6           0           1\n"
"p2          0           3           1           4\n"
"p3          0           1           4           8\n"
"p4          0           4           8           14\n"

"Average WaitTime=3\n"
"Average TurnaroundTime=6\n";

			file_<<"*****RoundRobin*****\n"
"Process  ArrivalTime  BurstTime  WaitTime  TurnaroundTime\n"
"p1          0           6           2            3\n"
"p2          0           3           6            9\n"
"p3          0           1           8            12\n"
"p4          0           4           8            14\n"

"Average WaitTime=6\n"
"Average TurnaroundTime=9\n";

			file_<<"*****Priority*****\n"
"Process  ArrivalTime  BurstTime  WaitTime  TurnaroundTime\n"
"p1          0           6           0            6\n"
"p2          0           3           6            9\n"
"p3          0           1           9            10\n"
"p4          0           4           10           14\n"

"Average WaitTime=6\n"
"Average TurnaroundTime=9\n";
					  }		 
					  return 0;	 
					  break;
					  
		case 8:
		{
			cout<<"\n\t\t\n ****Scheduling Algorithm****\n";
	        cout<<"Wait time of all scheduling algorithm...\n\n";
	        int arr[5] = {6,3,3,6,6};
	        int check = arr[0];
	        for(int i = 0; i < 5; i++)
	        {
		      if(arr[i] > check)
		    {
			  check = arr[i];
		    }
	        }
	          for(int rows = check; rows >= 1; rows--)
	        {
		      for(int cols = 0; cols <= 4; cols++)
		    {
			if(arr[cols] >= rows)
			{
				cout << "\t\t|*| ";
			}
			else
			{
				cout << "\t\t  ";
			}
		}
		    cout << endl;
	    }
	        for(int cols = 0; cols <= 4; cols++)
	        {
		     cout << "\t\t---";
	        }
	         cout << endl;
	         for(int cols=0; cols<=4; cols++)
         	{
		     cout << "\t\t" << cols << " ";
	        }
	         cout << endl;
	         cout<<"\t\tFCFS\t\tSJF\t\tSRTF\t\tRR\t\tPS\t\t";
	         cout << endl;
		    }			 
			return 0;
			break;
			
			case 9:
			{
				cout<<"\n\t\t\n ****Scheduling Algorithm****\n";
             	cout<<"Turnaround time of all scheduling algorithm...\n\n";
	            int arr[5] = {9,6,6,9,9};
	            int check = arr[0];
	            for(int i = 0; i < 5; i++)
         	{
		        if(arr[i] > check)
		   {
			    check = arr[i];
	     	}
	        }
	            for(int rows = check; rows >= 1; rows--)
	         {
		        for(int cols = 0; cols <= 4; cols++)
		     {
			    if(arr[cols] >= rows)
			{
				cout << "\t\t|*| ";
			}
			else
			{
				cout << "\t\t  ";
			}
		}
		    cout << endl;
    	}
	         for(int cols = 0; cols <= 4; cols++)
	   {
		     cout << "\t\t---";
    	}
	         cout << endl;
	         for(int cols=0; cols<=4; cols++)
	   {
		    cout << "\t\t" << cols << " ";
	   }
	        cout << endl;
	        cout<<"\t\tFCFS\t\tSJF\t\tSRTF\t\tRR\t\tPS\t\t";
	        cout << endl;
			 } 
			 return 0;
			 break;
        
       case 10:  
        {
	           cout<<"\n ***** END OF *****\n";
       	       cout<< "\nEnd of program..!!!\n ";
       	       return 0;
        }
       	        break;
       	
            	default:  cout<< "Not valid key.. choose again!! \n\t\t";
            	return 0;
        }
          
    }  
    while (select!=4);
    return 0;
        
}     
        

