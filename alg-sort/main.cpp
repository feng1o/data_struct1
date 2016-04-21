#include "sort.h"
#include "creatArrPrinArr.h"


int main()
{
	int i2 = 1;
	int k = 2;
	printf("i<<k+2 = %d\n\n", i2 << k + 1);
	int *arr = NULL;
#ifdef __cplusplus
	std::cout << "this is a c++ pro \n";
#else
	std::cout << "this is a c pro \n";
#endif
	int *array = creatRandomArray(def_N);
	printInitialArr(array, def_N);
	int i = 0;
	while (1){
		printf("ÊäÈëÒ»¸öÊý×ÖÑ¡Ôñ£º1.Ñ¡ÔñÅÅÐò£¬2.²åÈë£¬3.¶ÑÅÅÐò£¬4.¹é²¢ÅÅÐò£¬ 5.Ï£¶ûÅÅÐò¡¢6.Ã°ÅÝÅÅÐò\n");
		scanf("%d", &i);
		switch (i){
		case 1:
			SelectSort(array, def_N);
			break;
		case 2:
			InsertSort(array, def_N);
			break;
		case 3:
			HeapSort(array, def_N);
			break;
		case 4:
			break;
		case 5:
			shellSort(array, def_N);
			break;
		case 6:
			BubbleSort(array,  def_N);
			break;
		}
		printSortedArr(array, def_N);

	}
}