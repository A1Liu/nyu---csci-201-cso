
int main() {
	return 0;
}

// A1 >= A2 <= A3 >= A4 <= A6...
void wiggle(int * A, int count) {
	int up = 1,tmp;
	for (int i = 0; i < count - 1; i++) {
		if (	(up && A[i] > A[i+1]) ||
				(!up && A[i] < A[i+1]) ) {
			tmp = A[i];
			items[i] = A[i+1];
			A[i+1] = tmp;
		}
	}
}
