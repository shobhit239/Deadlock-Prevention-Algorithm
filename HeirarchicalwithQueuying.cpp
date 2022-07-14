#include<iostream> 
#include<climits> 
using namespace std;
class kQueues {
public:
// Array of size n to store actual content to be stored in queue 
int *arr;
// Array of size k to store indexes of front elements of the queue 
int *front;
// Array of size k to store indexes of rear elements of queue 
int *rear;
// Array of size n to store next entry in all queues 
int *next;
int n2, k;
int free; // To store the beginning index of the free list
public:
//constructor to create k queue in an array of size n 
kQueues(int k, int n2);
// A utility function to check if there is space available 
bool isFull() { return (free == -1); }
// To enqueue an item in queue number 'qn' where qn is from 0 to k-1 
void enqueue(int item, int qn);
// To dequeue an from queue number 'qn' where qn is from 0 to k-1 
int dequeue(int qn);
// To check whether queue number 'qn' is empty or not
bool isEmpty(int qn) { return (front[qn] == -1); } };

// Constructor to create k queues in an array of size n 
kQueues::kQueues(int k1, int n1)
{
// Initialize n and k, and allocate memory for all arrays k = k1, n2 = n1;
arr = new int[n2];
front = new int[k];
rear = new int[k]; next = new int[n2];
// Initialize all queues as empty 
for (int i = 0; i < k; i++)
front[i] = -1;
// Initialize all spaces as free free = 0;
for (int i=0; i<n2-1; i++)
next[i] = i+1;
next[n2-1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number 'qn' where qn is from 0 to k-1 
void kQueues::enqueue(int item, int qn)
{
// Overflow check 
if (isFull())
{
cout << "\nQueue Overflow\n";
return; }
int i = free; // Store index of first free slot
// Update index of free slot to index of next slot in free list free = next[i];
if (isEmpty(qn)) front[qn] = i;
else
next[rear[qn]] = i;
next[i] = -1;
// Update next of rear and then rear for queue number 'qn'
 rear[qn] = i;
// Put the item in array
arr[i] = item; }

// To dequeue an from queue number 'qn' where qn is from 0 to k-1 
int kQueues::dequeue(int qn)
{
// Underflow checkSAS 
if (isEmpty(qn))
{
cout << "\nQueue Underflow\n";
return INT_MAX; }
// Find index of front item in queue number 'qn' 
int i = front[qn];
front[qn] = next[i]; // Change top to store next of previous top
// Attach the previous front to the beginning of free list 
next[i] = free;
free = i;
// Return the previous front item
return arr[i]; }

int main () {
int n, m, p, q;
kQueues ks(n, p);
cout << "Enter the number of processes: "; 
cin >> p;
cout << "Enter the number of resources: "; 
cin >> n;
int res[n];
int proc[p];
int att[p];
int priority[n];
int pri[p];
for (int i = 0; i < p; i++){
att[i] = 0; //Initializing that before the start that no process holds any resource
}
for (int i = 0; i < p; i++)
{
pri[i] = 0; //Initializing that before the start that no process holds any resource
}

cout << "\nEnter: 1 for resource NOT FREE OR 0 for resource FREE:\n"; 
for (int i = 0; i < n; i++) {
//This part of code is to
cin >> res[i]; }
cout << "\nEnter the Priority for every resource\n"; // This part of the code is to know thhe priority of each resource
for (int i = 0; i < n; i++) {
cin >> priority[i]; }
int choice = 0; while (choice == 0)
{
cout <<
"\n***********************\n"; int l = 0;
int q1;
cout << "\nEnter the process no: P";
cin >> q;
cout << "\nEnter the resource no. process want to access:\n"; 
cin >> m;
if (att[q - 1] != 0 && pri[q - 1] >= priority[m - 1]) //This will work if a process has a resource and the priority of the required resource is less than the acquired resource
{
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
else{
{
for(int i=0;i<p;i++)
{
if(proc[i]==m)
{
res[m-1]=0;
if (res[m - 1] != 0) {
if(ks.arr[ks.front[m-1]]==q)
proc[i]=0;
att[i]=0;
pri[i]=0;
cout<<"Resourced released by the process holding the required resource";
}
}
if (res[m - 1] == 0 && ks.arr[ks.front[m-1]]==q )
{
cout << "\ngrant process P exclusive access to resources\n"; proc[q - 1] = m;
att[q-1] = 1;
res[m - 1] = 1;
pri[q-1] = priority[m - 1];
ks.dequeue(m-1);
cout <<"Process want to leave the resource \npress 0 for no\n1 for yes "; cin >> q1;
if (q1 == 1)
{ proc[q - 1] = 0;
att[q - 1] = 0; pri[q - 1] = 0; res[m - 1] = 0;
} }
}
else{
cout << "\nPut in waiting list \n";
ks.enqueue(q, m-1);
cout <<"Process holding the resource want to leave the resource \npress 0 for no\n1 for yes "; int choice1;
cin>>choice1;
if(choice1==1){
for(int i=0;i<p;i++)
{
if(proc[i]==m)
{
res[m-1]=0;
proc[i]=0;
att[i]=0;
pri[i]=0;
cout<<"Resourced released by the process holding the required resource";
} }
if (res[m - 1] == 0 && ks.arr[ks.front[m-1]] ==q ) {
cout << "\ngrant process P exclusive access to resources\n"; proc[q - 1] = m;
att[q-1] = 1;
res[m - 1] = 1;
pri[q-1] = priority[m - 1];
ks.dequeue(m-1);
cout <<"Process want to leave the resource \npress 0 for no\n1 for yes "; 
cin >> q1;
if (q1 == 1)
{ proc[q - 1] = 0;
att[q - 1] = 0; pri[q - 1] = 0; res[m - 1] = 0;
} }
} } }
else if (res[m - 1] == 0) //This is for the granting the process to the required resource 
{
cout << "\ngrant process P exclusive access to resources\n"; proc[q - 1] = m;
att[q - 1] = 1;
res[m - 1] = 1;
pri[q - 1] = priority[m - 1];
cout <<"Process want to leave the resource press 0 for no or 1 for yes "; 
cin >> q1;
if (q1 == 1) {
proc[q - 1] = 0; att[q - 1] = 0; pri[q - 1] = 0; res[m - 1] = 0;
} }
}
cout << "\nProcess want to end\n0 for No\n1 for Yes\n"; 
cin >> choice;
} return 0;
}