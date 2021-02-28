#include<iostream>
using namespace std;

//单链表：根据两个数组A、B构造两个递增单链表，合并成一个新递增单链表C   （A、B由自己输入）

typedef struct LNode {
	int data;
	struct LNode* next;
}LinkNode;

//直接插入排序 
void InsertSort(int R[], int n) {
	int tmp, j;
	for (int i = 1; i < n; i++) {
		tmp = R[i];
		j = i;
		while (j > 0 && tmp < R[j - 1]) {
			R[j] = R[j - 1];
			j--;
		}
		R[j] = tmp;
	}
}

class LinkList {
public:
	LinkNode* L;
	LinkList();
	void CreateList(int a[], int n);   //调用它之前数组a（A、B）就已经拍好序了   尾插 
	void DispList();
};
LinkList::LinkList() {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
void LinkList::CreateList(int a[], int n) {
	LinkNode* s, * r;
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
void LinkList::DispList() {
	LinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << endl;
}

//二路归并
void UnionList(LinkList* LA, LinkList* LB, LinkList*& LC) {
	LinkNode* pa = LA->L->next, * pb = LB->L->next, * r, * s;
	LC = new LinkList();
	r = LC->L;
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
		}
		else {
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pb->data;
			r->next = s;
			r = s;
			pb = pb->next;
		}
	}
	if (pa == NULL) {
		while (pb != NULL) {
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pb->data;
			r->next = s;
			r = s;
			pb = pb->next;
		}
	}
	else if (pb == NULL) {
		while (pa != NULL) {
			s = (LinkNode*)malloc(sizeof(LinkNode));
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
		}
	}
	r->next = NULL;
}

int main() {
	//int A[5] = { 3,1,9,2,10 };
	//int B[5] = { 2,0,8,7,6 };
	int A[5], B[5];
	LinkList* LA, * LB, * LC;
	LA = new LinkList();
	LB = new LinkList();
	cout << "输入数组A的5个元素：";
	for (int i = 0; i < 5; i++) {
		cin >> A[i];
	}
	cout << "输入数组B的5个元素：";
	for (int i = 0; i < 5; i++) {
		cin >> B[i];
	}
	InsertSort(A, 5);
	InsertSort(B, 5);
	LA->CreateList(A, 5);
	LB->CreateList(B, 5);
	cout << "所得到的链表为：" << endl;
	LA->DispList();
	LB->DispList();
	UnionList(LA, LB, LC);
	cout << "归并后得到的链表为：" << endl;
	LC->DispList();
	return 0;
}