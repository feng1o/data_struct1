#include "creatArrPrinArr.h"
#include "sort.h"


int* creatRandomArray(const int  N)
{
	if (N < 1)
		return NULL;
	time_t  tm;
	unsigned int uint = time(&tm);
	srand(uint);
	int i = 0;
	int *array = (int*)calloc(N, sizeof(int));
	assert(array);
	for (; i < N; i++)
	{
		array[i] = rand() % (N );
	}
	return array;
}

void printInitialArr(const int *array, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf(" %3d", array[i]);
		//if ((i+1)%20 == 0)
		{
			//printf("\n");
		}
	}
	printf("\n");
}

void printSortedArr(const int *array, int N)
{
	//std::cout << "sorted is:----------------------------\n\n";
	int i;
	for (i = 0; i < N; i++)
	{
		printf(" %3d", array[i]);
	//	if ((i + 1) % 20 == 0)
		{
			//printf("\n");
		}
	}
	printf("\n");
}
void printStartTime()
{

	clock_t  start, end;
	start = clock();
	time_t timer;
	time(&timer);
	std::cout << std::cout.fill('_') << std::setw(3) << ' ' << "time = " << ctime(&timer);
	std::cout << std::cout.right << std::cout.fill('_') << "time = " << asctime(gmtime(&timer));
	std::cout << std::cout.fill('_') << "time = " << asctime(localtime(&timer));

	//end = clock();
	//std::cout << std::cout.fill('_') << "difftime =" << difftime(time(NULL), timer) << std::endl;
	//std::cout << std::cout.fill('_') << "clock    =" << static_cast<double> (end - start) / CLOCKS_PER_SEC << std::endl;
}
void printEndTime()
{
	
}