void CreateCrossList(CrossList *M)
{
	int m, n, t, i, j, e;
	OLNode* p;
	OLNode* q;
	����/*����ʮ������洢�ṹ������ϡ�����M*/
	scanf("%d%d%d", &m, &n, &t); /*����M������,�����ͷ���Ԫ�صĸ���*/
	M->m = m;
	M->n = n;
	M->len = t;
	if (!(M->row_head = (OLink *)malloc((m + 1)*sizeof(OLink))))
		exit(OVERFLOW);
	if (!(M->col_head = (OLink *)malloc((n + 1)*sizeof(OLink))))
		exit(OVERFLOW);
	����/*��ʼ���С���ͷָ�����������С�������Ϊ�յ�����*/
	for (int h = 0; h < m + 1; h++)
	{
		M->row_head[h] = NULL;
	}
	for (int t = 0; t < n + 1; t++)
	{
		M->col_head[t] = NULL;
	}
	for (scanf("%d%d%d", &i, &j, &e); i != 0; scanf("%d%d%d", &i, &j, &e))
	{
		if (!(p = (OLNode *)malloc(sizeof(OLNode))))
			exit(OVERFLOW);
		p->row = i;
		p->col = j;
		p->value = e; /*���ɽ��*/
		if (M->row_head[i] == NULL)
			M->row_head[i] = p;
		p->right = NULL;
		else
		{
			����/*Ѱ���б��еĲ���λ��*/
			for (q = M->row_head[i]; q->right&&q->right->col < j; q = q->right); /*��ѭ����*/
			p->right = q->right;
			q->right = p; /*��ɲ���*/
		}
		if (M->col_head[j] == NULL)
			M->col_head[j] = p;
		p->down = NULL;
		else
		{
			����/*Ѱ���б��еĲ���λ��*/
			for (q = M->col_head[j]; q->down&&q->down->row < i; q = q->down); /*��ѭ����*/
			p->down = q->down;
			q->down = p; /*��ɲ���*/
		}
	}
}