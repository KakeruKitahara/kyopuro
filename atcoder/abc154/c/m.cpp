#include <cstdio>
#include <cstdlib>
#include <ctime>
#define N 200000

int a[N];

void swap(int *x_ptr, int *y_ptr);
void heap_struct(int t, int last);

void heap_sort(int a[], int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		heap_struct(i, n - 1);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);
		heap_struct(0, i - 1);
	}
}

int main(void)
{
	int n, min, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}

	heap_sort(a, n);

	for (i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	return 0;
}

void swap(int *x_ptr, int *y_ptr)
{
	int temp = *x_ptr;
	*x_ptr = *y_ptr;
	*y_ptr = temp;
}
void heap_struct(int t, int last)
{
	int tmp;
	int j;
	tmp = a[t];
	while (1)
	{
		j = 2 * t + 1;
		if (j > last)
			break;
		if (j != last && a[j + 1] > a[j])
			j++;
		if (tmp >= a[j])
			break;
		a[t] = a[j];
		t = j;
	}
	a[t] = tmp;
}