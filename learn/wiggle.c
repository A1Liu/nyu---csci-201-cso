
int main() {
	return 0;
}

// A1 >= A2 <= A3 >= A4 <= A6...
void wiggle(int * items, int count) {
	int up = 1,tmp;
	for (int i = 0; i < count - 1; i++) {
		if (	(up && items[i] > items[i+1]) ||
				(!up && items[i] < items[i+1]) ) {
			tmp = items[i];
			items[i] = items[i+1];
			items[i+1] = tmp;
		}
	}
}
