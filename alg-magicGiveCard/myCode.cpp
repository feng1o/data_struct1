#include "iostream"
#include "memory"
#include "cassert"

using std::cout;
using std::cin;

#define  defMyAssert(x)  if(!x){ \
							cout << "malloc errod:\n" ;\
							cout << __FILE__ << __LINE__ << __FUNCTION__ << std::endl;\
							abort();\
}
struct tag_CardNode
{
	int cardNo;
	struct tag_CardNode* next;
};
typedef struct tag_CardNode  cardNode;
#define  defCardNum  13

cardNode* initCardLink(int N)
{
	cardNode* cardLink = (cardNode*)malloc(sizeof(cardNode));
	defMyAssert(cardLink);
	cardLink->cardNo = 1;
	cardLink->next = cardLink;
	cardNode* tmp = cardLink;
	for (int i = 1;  i < N; i++)
	{
		cardNode* node = (cardNode*)malloc(sizeof(cardNode));
		defMyAssert(node);
		node->cardNo = -1;
		tmp->next = node;
		node->next = cardLink;
		tmp = tmp->next;
	}
	return cardLink;
}

void placeCardToCardLink(cardNode* link, int N)
{
	cardNode* tmp = link;
	for (int k = 1, cardN = 2; cardN <= N; cardN++)
	{
		while (true)
		{
			if (k == cardN && tmp->cardNo == -1)
			{
				tmp->cardNo = cardN;
				tmp = tmp->next;
				k = 1;
				break;
			}
			else if (tmp->cardNo == -1)
			{
				++k;
				//tmp = tmp->next;
			}
			tmp = tmp->next;
		}
	}
}

void travelLink(cardNode* link,int N)
{
	int n = 0;
	while (link)
	{
		cout << link->cardNo << std::endl;
		link = link->next;
		if (++n == N)
			break;
	}
}
int main()
{
	cardNode* cardLink = initCardLink(defCardNum);
	placeCardToCardLink(cardLink, defCardNum);
	travelLink(cardLink, defCardNum);
	
	return 0;
}