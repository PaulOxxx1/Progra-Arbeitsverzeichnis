#include<iostream>
#include<cstdlib>
using namespace std;

struct list_element {
	int i;
	list_element *prev, *next;
};

struct list {
	list_element *head, *tail;
};

list construct(int len) {
	srand(len);
	list l;
	l.head=new list_element;
	l.head->i=rand() % len;
	l.head->prev=0;
	l.head->next=0;
	l.tail=l.head;
	for (int i=1;i<len;i++) {
		l.tail->next=new list_element;
		l.tail->next->prev=l.tail;
		l.tail=l.tail->next;
		l.tail->i=rand() % len;
		l.tail->next=0;
	}
	return l;
}

void print_forward(list l) {
	list_element* current=l.head;
	do {
		cout << current->i << endl;
		current=current->next;
	} while (current);
}

void print_backward(list l) {
	list_element* current=l.tail;
	do {
		cout << current->i << endl;
		current=current->prev;
	} while (current);
}

void free(list l) {
	do {
		list_element* current=l.head;
		l.head=l.head->next;
		//cout << "deleting " << current->i << endl;
		delete current;
	} while(l.head);
}

void swap(list* l, list_element* A) {
	list_element* B = A->next;	// B ist Nachfolger von A

	if (B==0) {
			// A liegt am Ende der Liste
			// also muss nichts getan werden
			return;
	}

	if (A->prev==0) {		// A liegt am Anfang der Liste
		l->head = B;
		B->prev = 0;
	} else {						// A hat einen Vorgaenger
		A->prev->next = B;
		B->prev = A->prev;
	}

	if (B->next==0) {		// B liegt am Ende der Liste
		l->tail = A;
		A->next = 0;
	} else {						// B hat einen Nachfolger
		B->next->prev = A;
		A->next = B->next;
	}

	A->prev = B;
	B->next = A;
}

void sort(list* l) {
	int n=0;	// Zaehler

	// Unsortierter Bereich
	list_element* u_head = l->head;
	list_element* u_tail = l->tail;
	list_element* current;
	list_element* lastSwapped;

	while (u_head != u_tail) {	// Stoppe, wenn unsortierter Bereich nur ein Element enthaelt
		current = u_head;	// Waehle erstes unsortiertes Element
		lastSwapped = current;

		while (current != u_tail) {
			n++;
			if (current->i > current->next->i) {
				lastSwapped = current;
				// Spezialfaelle am Rand des unsortierten Bereichs
				if (current->next!=0) {
					if (current->next==u_tail) u_tail = current;
					if (current==u_head) u_head = current->next;
				}
				swap(l,current);
			} else {
				current = current->next;
			}
		}

		u_tail = lastSwapped;

		current = u_tail;	// Waehle letztes unsortiertes Element
		lastSwapped = current;

		while (current != u_head) {
			n++;
			if (current->i < current->prev->i) {
				lastSwapped = current;
				// Spezialfaelle am Rand des unsortierten Bereichs
				if (current!=0) {
					if (current==u_tail) u_tail = current->prev;
					if (current->prev==u_head) u_head = current;
				}
				swap(l,current->prev);
			} else {
				current = current->prev;
			}
		}

		u_head = lastSwapped;
	}

	cout << "Liste sortiert, mit " << n << " Vergleichen!" << endl;
}

int main() {
	list l;
	cout << "Eingabe der Listengroesse: \n";
	int len; cin >> len;
	cout << endl;
	if (len==0) return 0;
	// Konstruktion
	l=construct(len);
	// Ausgabe
	print_forward(l);
	sort(&l);
	print_forward(l);
	// Destruktion
	free(l);
	return 0;
}
