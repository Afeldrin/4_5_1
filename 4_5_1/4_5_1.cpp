#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int partition(int arr[], int low, int high)
{

    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int pi = partition(arr, low, high);


        thread t1(quickSort, arr, low, pi - 1);

        thread t2(quickSort, arr, pi + 1, high);
        
        t1.join();
        t2.join();
    }
}

int main()
{
    srand(time(0));
    
	int a[2000];

	for (int i = 0; i <= 1999; i++) 
	{
		a[i] = rand()%1000;
	}

    cout << "unsorted array:" << endl;

	for (int i = 0; i <= 1999; i++)
	{
		cout << a[i] << " ";
	}
    cout << endl;

    auto start_time = std::chrono::steady_clock::now();

    quickSort(a, 0, 1999);

    auto end_time = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Elapsed time: " << elapsed_ms.count() << " mcs\n" << std::endl;

    cout << "Sorted array: " << endl;

    for (int i = 0; i <= 1999; i++)
    {
        cout << a[i] << ",";
    }

    cout << endl;

    cout << a[1999] + a[1998] + a[1997] << endl;

	return 0;
}