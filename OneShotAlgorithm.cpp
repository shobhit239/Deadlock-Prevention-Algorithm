#include<iostream> 
using namespace std; 
int main()
{
    int n,m,p,q;
    cout<<"Enter the number of processes: ";
    cin>>p;
    cout<<"Enter the number of resources: ";
    cin>>n;
    int res[n]; //resources array
    int proc[p]; //process array maintaining the resource no. which it has 
    int att[p]; //an array to ensure that the process holds some resource 
    for(int i=0;i<p;i++){
        att[i]=0; //Initializing that before the start that no process holds any resource 
    }
    cout<<"\nEnter: 1 for resource NOT FREE OR 0 for resource FREE:\n"; //This part of code is to know the resources that are available to the processes.
    for(int i=0;i<n;i++){
    cin>>res[i];
    }
    int choice=0;
    while(choice==0){
    cout<<"\n***********************\n";
    int c=0,l=0;
    cout<<"\nEnter the process no: P";
    cin>>q;
    cout<<"\nEnter the resource no. process want to access:\n";
    cin>>m;
    if(att[q-1]!=0 ){
    cout<<"\nrefuse the request\n";
    }
    else if(m>n || m<1)
    cout<<"\nResource does not exists\n"; //This part of the code if the resource is out of the range of the process.
    else{
    if(res[m-1]!=0)
    {
    cout<<"\nWait until resource free \n"; // This part of the code is used when process wants to acquire a resource which is not free.
    for(int i=0 ;i<p; i++)
    {
    if(proc[i]==m) // This part describes which process holds the required resource
    {
    cout<<"Process"<<(i+1)<<" has this resource";
    } }
    res[m-1]=0;
    }
    else if(res[m-1]==0)
    {
    cout<<"\nGrant process P exclusive access to resources\n"; // This part of the code is to allocate resource to a process.
    proc[q-1]=m;
    att[q-1]=1;
    res[m-1]=1;
    }
    }
    cout<<"\nProcess want to end \n"; cin>>choice;
    }
return 0; 
}