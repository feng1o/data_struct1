for (int k = 0; k<n; ++k) {

	for (int i = 0; i<n; ++i) {

		for (int j = 0; j<n; ++j) {

			/*

			实际中为防止溢出，往往需要选判断 dist[i][k]和dist[k][j

			都不是Inf ，只要一个是Inf，那么就肯定不必更新。

			*/

			if (dist[i][k] + dist[k][j] < dist[i][j]) {

				dist[i][j] = dist[i][k] + dist[k][j];

			}

		}

	}

}

//如果还是看不懂，那就用草稿纸模拟一遍，之后你就会豁然开朗。半个小时足矣（早知道的话会节省很多个半小时了。。狡猾）
//
//再来看路径保存问题：

void floyd() {

	for (int i = 1; i <= n; i++){

		for (int j = 1; j <= n; j++){

			if (map[i][j] == Inf){

				path[i][j] = -1;//表示  i -> j 不通 

			}
			else{

				path[i][j] = i;// 表示 i -> j 前驱为 i

			}

		}

	}

	for (int k = 1; k <= n; k++) {

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {

				if (!(dist[i][k] == Inf || dist[k][j] == Inf) && dist[i][j] > dist[i][k] + dist[k][j]) {

					dist[i][j] = dist[i][k] + dist[k][j];

					path[i][k] = i;

					path[i][j] = path[k][j];

				}

			}

		}

	}

}

void printPath(int from, int to) {

	/*

	* 这是倒序输出，若想正序可放入栈中，然后输出。

	*

	* 这样的输出为什么正确呢？个人认为用到了最优子结构性质，

	* 即最短路径的子路径仍然是最短路径

	*/

	while (path[from][to] != from) {

		System.out.print(path[from][to] + "");

		to = path[from][to];

	}

}