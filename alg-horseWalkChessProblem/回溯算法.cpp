#if 0
void backtrack(int t)  //������ʿ���������⣬ʵ�ֵ��ҵ�һ��·����ֹͣ�����ģ����һֱ�������е�
{
	if (t > n) output(x);
	else
		for (int i = f(n, t); i <= g(n, t); i++) {
			x[t] = h(i);
			if (constraint(t) && bound(t)) backtrack(t + 1);
		}
}
#endif
