#include "sort.h"

#define  def_Swap(a, b)  {(a)^=(b)^=(a)^=(b);}
#define  def_Swap2(type, a, b)  {type c; c=(a); (a)=(b);(b)=c; }
void SelectSort(int array[], int N)
{
				clock_t  start, end;
				start = clock();
				time_t timer;
				time(&timer);
			//	std::cout << std::cout.fill('_') << std::setw(3)<<' '<< "time = " << ctime(&timer) ;
			//	std::cout <<std::cout.right<< std::cout.fill('_') << "time = " << asctime(gmtime(&timer));
			//	std::cout << std::cout.fill('_') << "time = " << asctime(localtime(&timer));

	for (int i = 1; i < N; i++)
	{
		int index = i-1;
		for (int j = i ; j < N; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		if (index != i - 1)
			//def_Swap2(int, array[index], array[i-1]);
			def_Swap(array[index], array[i - 1]);
	}

				end = clock();
			  //std::cout << std::cout.fill('_') << "difftime =" << difftime(time(NULL), timer) << std::endl;
				std::cout << std::cout.fill('_') << "clock=" << static_cast<double> (end - start) / CLOCKS_PER_SEC << std::endl;

}
