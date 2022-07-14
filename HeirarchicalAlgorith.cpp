#include<iostream> using namespace std; int main ()
{
 int n, m, p, q;
cout << "Enter the number of processes: "; cin >> p;
cout << "Enter the number of resources: "; cin >> n;
int res[n];
int proc[p];
int att[p];
int priority[n];
int pri[p];
for (int i = 0; i < p; i++)
{
    att[i] = 0; //Initializing that before the start that no process holds any resource 
    }
for (int i = 0; i < p; i++) {
pri[i] = 0; //Initializing that before the start that no process holds any resource 
}
cout << "\nEnter: 1 for resource NOT FREE OR 0 for resource FREE:\n"; 
for (int i = 0; i < n; i++) {
cin >> res[i]; }
//This part of code is to
cout << "\nEnter the Priority for every resource\n"; // This part of the code is to know thhe priority of each resource
for (int i = 0; i < n; i++) {
cin >> priority[i]; }
int choice = 0; 
while (choice == 0)
{
cout <<"\n***********************\n"; int l = 0;
int q1;
cout << "\nEnter the process no: P";
cin >> q;
cout << "\nEnter the resource no. process want to access:\n";
cin >> m;
if (att[q - 1] != 0 && pri[q - 1] >= priority[m - 1]) //This will work if a process has a resource and the
priority of the required resource is less than the acquired resource {
cout << "\nrefuse the request\n"; cout <<
"\nWait till the release of all items held by process press 0 for no 1 for yes\n"; {
cin >> l; if (l == 1)
{
int a = proc[q-1]; res[a-1]=0;
att[q - 1] = 0; pri[q - 1] = 0; proc[q - 1] = 0;
}
} }
else if (m > n || m < 1)
cout << "\nResource does not exists\n"; // This is for the input out of range
else {
    if (res[m - 1] != 0) {
cout << "\nwait until resource free \n"; for (int i = 0; i < p; i++)
{
if (proc[i] == m) // This part describes which process holds the required resource
{
cout << "Process" << (i + 1) << " has this resource"; att[i]=0;
pri[i]=0;
proc[i]=0;
} }
res[m - 1] = 0; 
pri[q - 1] = 0; 
proc[q - 1] = 0; 
att[q - 1] = 0;
}
else if (res[m - 1] == 0) //This is for the granting the process to the required resource
{
cout << "\ngrant process P exclusive access to resources\n";
proc[q - 1] = m;
att[q - 1] = 1;
res[m - 1] = 1;
pri[q - 1] = priority[m - 1];
cout <<"Process want to leave the resource press 0 for no or 1 for yes "; cin >> q1;
if (q1 == 1) {
proc[q - 1] = 0; att[q - 1] = 0; pri[q - 1] = 0; res[m - 1] = 0;
} }
}
cout << "\nProcess want to end\n0 for No\n1 for Yes\n"; cin >> choice;
} return 0;
}