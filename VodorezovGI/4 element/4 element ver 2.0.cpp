// 4 element ver 2.0.cpp 
#include <iostream>

int main()
{
	int a[10] = { 0,9,8,7,2,3,4,5,1,6 };
	int max[5] = { a[0] };
	int num[5] = {0};
	int i=0;

	if (max[1] <= a[i]) {
		max[1] = a[i];
		num[1] = i;
	}

	i++;

	if (max[1] <= a[i]) {
		max[1] = a[i];
		num[1] = i;
	}

	if ((max[2] <= a[i - 1]) && (i - 1 != num[1])) {
		max[2] = a[i - 1];
		num[2] = i - 1;
	}

	i++;

	if (max[1] <= a[i]) {
		max[1] = a[i];
		num[1] = i;
	}

	if ((max[2] <= a[i - 1]) && (i - 1 != num[1])) {
		max[2] = a[i - 1];
		num[2] = i - 1;
	}

	if ((max[3] <= a[i - 2]) && (i - 2 != num[1]) && (i - 2 != num[2])) {
		max[3] = a[i - 2];
		num[3] = i - 2;
	}

	i++;

	for (; i < 10; i++) {
		if (max[1] <= a[i]) {
			max[1] = a[i];
			num[1] = i;
		}

		if ((max[2] <= a[i - 1]) && (i - 1 != num[1])) {
			max[2] = a[i - 1];
			num[2] = i - 1;
		}

		if ((max[3] <= a[i - 2]) && (i - 2 != num[1]) && (i - 2 != num[2])) {
			max[3] = a[i - 2];
			num[3] = i - 2;
		}

		if ((max[4] <= a[i - 3]) && (i - 3 != num[1]) && (i - 3 != num[2]) && (i - 3 != num[3])) {
			max[4] = a[i - 3];
			num[4] = i - 3;
		}
	}

	i++;

	if ((max[2] <= a[i - 1]) && (i - 1 != num[1])) {
		max[2] = a[i - 1];
		num[2] = i - 1;
	}

	if ((max[3] <= a[i - 2]) && (i - 2 != num[1]) && (i - 2 != num[2])) {
		max[3] = a[i - 2];
		num[3] = i - 2;
	}

	if ((max[4] <= a[i - 3]) && (i - 3 != num[1]) && (i - 3 != num[2]) && (i - 3 != num[3])) {
		max[4] = a[i - 3];
		num[4] = i - 3;
	}

	i++;

	if ((max[3] <= a[i - 2]) && (i - 2 != num[1]) && (i - 2 != num[2])) {
		max[3] = a[i - 2];
		num[3] = i - 2;
	}

	if ((max[4] <= a[i - 3]) && (i - 3 != num[1]) && (i - 3 != num[2]) && (i - 3 != num[3])) {
		max[4] = a[i - 3];
		num[4] = i - 3;
	}

	i++;

	if ((max[4] <= a[i - 3]) && (i - 3 != num[1]) && (i - 3 != num[2]) && (i - 3 != num[3])) {
		max[4] = a[i - 3];
		num[4] = i - 3;
	}

    std::cout << max[4];
}
