#include <iostream>
#include <cstring>

template<class T>
void to_bin(T v)
{
	using std::cout;
	using std::endl;
	union
	{
		T value;
		unsigned char bytes[sizeof(T)];
	};
	memset(&bytes, 0, sizeof(T));
	value=v;
	// assumes little endian machine
	for (size_t i = sizeof(T);i>0;i--)
	{
		unsigned char pot=128;
		for (int j = 7;j>=0;j--,pot/=2)
			if (bytes[i-1]&pot)
				cout << "1";
			else
				cout << "0";
		cout << " ";
	}
	cout << endl;
}


int main() {
	long unsigned int stack_field;	// Benannte Variable auf dem Stack
	long unsigned int *heap_field = new long unsigned int;	// Pointer, der auf eine unbenannte Variable auf dem Heap zeigt
	short unsigned int *stack_pointer = (short unsigned int*)&stack_field;	// Pointer, der auf die Variable im Stack zeigt, fälschlicherweise als Pointer auf einen "Short" deklariert
	short unsigned int *heap_pointer = (short unsigned int*)heap_field;		// Pointer, der (auch) auf die Variable im Heap zeigt, fälschlicherweise als Pointer auf einen "Short" deklariert

	stack_field = 0;	// Initialisieren der Variable auf dem Stack mit Null
	*heap_field = 0;	// Initialisieren der Variable auf dem Heap mit Null

	*stack_pointer = 1;		// Die Variable auf dem Stack wird über den Pointer auf 1 gesetzt
	*heap_pointer = 2;		// Die Variable auf dem Heap wird über den Pointer auf 2 gesetzt

	stack_pointer = stack_pointer + 1;	// Der Pointer wird um 2 Byte verschoben, da stack_pointer als Pointer auf einen "Short" deklariert wurde und diese 2 Bytes groß sind
	heap_pointer = heap_pointer + 1;	// Der Pointer wird um 2 Byte verschoben, da heap_pointer als Pointer auf einen "Short" deklariert wurde und diese 2 Bytes groß sind

	to_bin(stack_field);	// Binärausgabe der Variable auf dem Stack, also 8 Byte (=1)
	to_bin(*heap_field);	// Binärausgabe der Variable auf dem Heap, also 8 Byte (=2)

	to_bin(*stack_pointer);	 // Binärausgabe von den 2 Byte, auf die der Pointer nach der Verschiebung zeigt. Entspricht dem 3. und 4. Byte von stack_field (von rechts gezählt)
	to_bin(*heap_pointer);	 // Binärausgabe von den 2 Byte, auf die der Pointer nach der Verschiebung zeigt. Entspricht dem 3. und 4. Byte von heap_field (von rechts gezählt)

	*stack_pointer = 2;		// Das 3. und 4. Byte (von rechts gezählt) der Variable stack_field wird mit der Binärdarstellung von 2 überschrieben, da stack_pointer mitten in stack_field hinein zeigt
	*heap_pointer = 1;		// Das 3. und 4. Byte (von rechts gezählt) der Variable heap_field wird mit der Binärdarstellung von 2 überschrieben, da heap_pointer mitten in heap_field hinein zeigt

	to_bin(stack_field);	// Man kann erkennen, wie Teile der Variable über den Pointer überschrieben wurden
	to_bin(*heap_field);	// Man kann erkennen, wie Teile der Variable über den Pointer überschrieben wurden

	to_bin(*stack_pointer);	// Gibt nur die zwei überschriebenen Byte aus
	to_bin(*heap_pointer);	// Gibt nur die zwei überschriebenen Byte aus

	/* Der Inhalt der Speicherzellen, auf die die beiden Pointer zeigen,
	unterscheidet sich von den entsprechenden Variablen, da die Pointer um
	zwei Byte "in die Variable hinein" verschoben wurden. */

	using namespace std;
	cout << "stack_field\t" << sizeof(stack_field) << "\t" << stack_field << "\t" << &stack_field << endl;
	cout << "heap_field\t" << sizeof(*heap_field) << "\t" << *heap_field << "\t" << heap_field << endl;
	cout << "stack_pointer\t" << sizeof(*stack_pointer) << "\t" << *stack_pointer << "\t" << stack_pointer << endl;
	cout << "heap_pointer\t" << sizeof(*heap_pointer) << "\t" << *heap_pointer << "\t" << heap_pointer << endl;

	delete heap_field;
	return 0;
}
