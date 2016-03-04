#if 0
void backtrack(int t)  //参照骑士走棋盘问题，实现的找到一条路径就停止，这个模型是一直找完所有的
{
	if (t > n) output(x);
	else
		for (int i = f(n, t); i <= g(n, t); i++) {
			x[t] = h(i);
			if (constraint(t) && bound(t)) backtrack(t + 1);
		}
}
#endif
