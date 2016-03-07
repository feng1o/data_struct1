for (int k = 0; k<n; ++k) {

	for (int i = 0; i<n; ++i) {

		for (int j = 0; j<n; ++j) {

			/*

			ʵ����Ϊ��ֹ�����������Ҫѡ�ж� dist[i][k]��dist[k][j

			������Inf ��ֻҪһ����Inf����ô�Ϳ϶����ظ��¡�

			*/

			if (dist[i][k] + dist[k][j] < dist[i][j]) {

				dist[i][j] = dist[i][k] + dist[k][j];

			}

		}

	}

}

//������ǿ��������Ǿ��òݸ�ֽģ��һ�飬֮����ͻ��Ȼ���ʡ����Сʱ���ӣ���֪���Ļ����ʡ�ܶ����Сʱ�ˡ����ƻ���
//
//������·���������⣺

void floyd() {

	for (int i = 1; i <= n; i++){

		for (int j = 1; j <= n; j++){

			if (map[i][j] == Inf){

				path[i][j] = -1;//��ʾ  i -> j ��ͨ 

			}
			else{

				path[i][j] = i;// ��ʾ i -> j ǰ��Ϊ i

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

	* ���ǵ����������������ɷ���ջ�У�Ȼ�������

	*

	* ���������Ϊʲô��ȷ�أ�������Ϊ�õ��������ӽṹ���ʣ�

	* �����·������·����Ȼ�����·��

	*/

	while (path[from][to] != from) {

		System.out.print(path[from][to] + "");

		to = path[from][to];

	}

}