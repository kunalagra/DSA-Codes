#include<stdio.h>
 
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}
void findTurnAroundTime(int processes[], int n,
    int bt[], int wt[], int tat[]) {    
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Process |  Burst time   |  Waiting time | Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %02d", (i + 1));
        printf("	|	%02d",bt[i]);
        printf("	| 	%02d", wt[i]);
        printf("	|	%02d\n",tat[i]);
    }
    float s = (float) total_wt / (float) n;
    float t = (float) total_tat / (float) n;
    printf("Average waiting time = %f", s);
    printf("\n");
    printf("Average turn around time = %f ", t);
}
int main() {
	int a;
	int processes[100];
	int burst_time[100];
	printf("Enter No. of Elements: ");
	scanf("%d",&a);
	printf("Enter Process No.: ");
	for(int i=0;i<a;i++){
		scanf("%d",&processes[i]);
	}
	printf("Enter Burst Time: ");
	for(int i=0;i<a;i++){
		scanf("%d",&burst_time[i]);
	}
    findavgTime(processes, a, burst_time);
    return 0;
}
