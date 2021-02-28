#include<iostream>
using namespace std;

//������������������A��B�������������������ϲ���һ���µ���������C   ��A��B���Լ����룩

typedef struct LNode {
	int data;
	struct LNode* next;
}LinkNode;

//ֱ�Ӳ������� 
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
	void CreateList(int a[], int n);   //������֮ǰ����a��A��B�����Ѿ��ĺ�����   β�� 
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

//��·�鲢
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
	cout << "��������A��5��Ԫ�أ�";
	for (int i = 0; i < 5; i++) {
		cin >> A[i];
	}
	cout << "��������B��5��Ԫ�أ�";
	for (int i = 0; i < 5; i++) {
		cin >> B[i];
	}
	InsertSort(A, 5);
	InsertSort(B, 5);
	LA->CreateList(A, 5);
	LB->CreateList(B, 5);
	cout << "���õ�������Ϊ��" << endl;
	LA->DispList();
	LB->DispList();
	UnionList(LA, LB, LC);
	cout << "�鲢��õ�������Ϊ��" << endl;
	LC->DispList();
	return 0;
}