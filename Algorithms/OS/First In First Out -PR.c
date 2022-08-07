#include <stdio.h>

int main() {
	int referenceString[10], pageFaults = 0, m, n, s, pages, frames;
	printf("*** FIFO Page Relacement Algorithm ***\n");
	printf("\nEnter Number of Frames: ");
	scanf("%d", & frames);
	printf("Enter Number of Pages : ");
	scanf("%d", & pages);
	printf("Enter Element in Page Table:\n");
	for (m = 0; m < pages; m++) {
		printf("Element No. [%d]: ", m + 1);
		scanf("%d", & referenceString[m]);
	}

	int temp[frames];
	for (m = 0; m < frames; m++) {
		temp[m] = -1;
	}
	for (m = 0; m < pages; m++) {
		s = 0;
		for (n = 0; n < frames; n++) {
			if (referenceString[m] == temp[n]) {
				s++;
				pageFaults--;
			}
		}
		pageFaults++;
		if ((pageFaults <= frames) && (s == 0)) {
			temp[m] = referenceString[m];
		} else if (s == 0) {
			temp[(pageFaults - 1) % frames] = referenceString[m];
		}
		printf("\n");
		for (n = 0; n < frames; n++) {
			printf("%d\t", temp[n]);
		}
	}
	printf("\n\nTotal Page Faults:\t%d\n", pageFaults);
	return 0;
}