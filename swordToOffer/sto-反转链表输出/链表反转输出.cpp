/**
*
* http://www.nowcoder.com/ta/coding-interviews/question-ranking?uuid=d0267f7f55b3412ba93bd35cfa8e8035&rp=1
*struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution{
public:
	vector<int> printListFromTailToHead(struct ListNode* head){
		struct ListNdoe* a = nullptr, b = nullptr, c = nullptr;
		while ()
	}
private:
	vector<int> ivec;

};
/*
class Solution{
public:
vector<int> printListFromTailToHead(struct ListNode* head) {
vector<int> ivec;
stack<int> istack;
while(head!=NULL)
{
istack.push(head->val);
head=head->next;
}
while(!istack.empty())
{
ivec.push_back(istack.top());
istack.pop();
}
return ivec;
}
private:
vector<int> ivec;

};
*/
/*
class Solution{
public:
vector<int> printListFromTailToHead(struct ListNode* head) {

if(head!=nullptr)
{
if(head->next!=NULL)
{
//head = head->next;//if do this,what will happen?
printListFromTailToHead(head->next);
}
// ivec.insert(ivec.end(),head->val);
ivec.push_back(head->val);

}
return ivec;
}
private:
vector<int> ivec;

};
*/
/*
class Solution {
public:
vector<int> printListFromTailToHead(struct ListNode* head) {
vector<int> v;
while(head != NULL)
{
v.insert(v.begin(),head->val);
head = head->next;
}
return v;
}
};
*/