/*
*
*Created by UnitedTimur
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Usel {

	int key;

	Usel *next;

	Usel *pr;
};

struct Sp {

	Usel * head;

	Usel * tail;

	Sp() : head(0), tail(0) {}

	void AddtoHead(int k) {

		Usel *p = new Usel;

		p->key = k;

		p->next = head;

		p->pr = 0;

		head ? head->pr = p : tail = p;

		head = p;
	}
	void AddtoTail(int k) {

		Usel *p = new Usel;

		p->key = k;

		p->next = 0;

		p->pr = tail;

		tail ? tail->next = p : head = p;

		tail = p;
	}
	void AddAfterKey(int k, int x) {

		Usel * p = Find(k);

		if (p) {

			Usel *n = new Usel;

			n->key = x;

			n->next = p->next;

			if (p->next) {

				p->next->pr = n;

			}

			p->next = n;

			if (n->next == 0) {

				tail = n;

			}

		}

	}
	void PrintSp() {

		Usel *p;

		for (p = head; p; p = p->next)
			std::cout << p->key << " ";

	}
	void DelHead() {

		if (head) {

			Usel *p = head;

			if (head->next) {

				head = head->next;

				head->pr = 0;

			}
			else {

				head = tail = 0;

			}

			delete p;

		}

	}
	Usel* Find_Position(int k) {

		int i = 1;

		Usel *p;

		for (p = head; p->next && i != k; p = p->next, i++);

		return p = i ? p : nullptr;

	}
	Usel *Find(int k) {

		Usel *p;

		for (p = head; p&&p->key != k; p = p->next);

		return p ? p : nullptr;

	}
	bool DelKey(int k) {

		Usel * p;

		Usel * q;

		p = Find(k);

		if (!p) return false;

		q = p->next;

		p->next = q->next;

		delete q;

		//DELETE(p);

		return true;

	}
	void DELETE(Usel *pr) {

		Usel * p = pr->next;

		pr->next = p->next;

		delete p;

	}
	void DelTail() {

		Usel * p;

		Usel * tail;

		for (p = head->next, tail = head->next; tail->next; p = tail, tail = tail->next);

		p->next = 0;

		delete tail;

	}
};


void main(void){

	Sp table;

	int k;

	for (int i = 0; i < 20; i++) {

		table.AddtoTail(i);

	}

	for (int i = 20; i < 30; i++) {

		table.AddtoTail(i);

	}

	//EXAMPLE
	table.AddtoHead(999999);
	table.AddtoTail(142512125);

	std::cout << "First var." << std::endl;
	table.PrintSp();
	std::cout << std::endl;

	std::cout << "Second var." << std::endl;
	table.AddAfterKey(11, 1000);
	table.PrintSp();
	std::cout << std::endl;

	std::cout << "Third var." << std::endl;
	table.DelHead(); table.DelTail();
	table.PrintSp();
	std::cout << std::endl;

	std::cout << "Fourth var." << std::endl;
	table.DelKey(0);
	table.PrintSp();
	std::cout << std::endl;

	system("pause");
}
