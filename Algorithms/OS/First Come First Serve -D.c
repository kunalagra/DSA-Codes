#include<stdio.h>

int main() {
	int i, j, sum = 0, n;
	int ar[20], tm[20];
	int disk;
	printf("Enter number of location: ");
	scanf("%d", & n);
	printf("Enter position of head: ");
	scanf("%d", & disk);
	printf("Enter elements of disk queue: ");
	for (i = 0; i < n; i++) {
		scanf("%d", & ar[i]);
		tm[i] = disk - ar[i];

		if (tm[i] < 0) {
			tm[i] = ar[i] - disk;
		}
		disk = ar[i];
		sum = sum + tm[i];
	}

	printf("\nMovement of total cylinders %d", sum);
	return 0;
}