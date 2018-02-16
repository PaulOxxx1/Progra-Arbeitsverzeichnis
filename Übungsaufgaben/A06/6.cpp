#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

struct node {
	const char* label;
	vector<node*> succ;
	vector<float> prob;
};

int traversal(node* current, int steps) {
	// Ausgabe des Knotens
	cout << current->label;

	// Nach Fisch ueberpruefen
	int fish=0;
	if (strcmp(current->label, "Fische ")==0) fish=1;

	// Naechsten Knoten auswaehlen
	float zufall = static_cast<double>(rand()) / RAND_MAX;
	int i=-1;
	while (zufall>=0) {
		zufall -= current->prob[++i];
	}

	// Sprung zum naechsten Knoten
	if (steps > 0) {
		return traversal(current->succ[i], --steps) + fish;
	} else {
		return fish;
	}
}

void node_init(node* a, const char* label) {
	a->label = label;
}

void edge_init(node* a, node* b, float probability) {
	a->succ.push_back(b);
	a->prob.push_back(probability);
}

void init_graph(node* nodes) {
	node_init(nodes, "\n");
	node_init(nodes+1, "Affen ");
	node_init(nodes+2, "Fische ");
	node_init(nodes+3, "faulenzen ");
	node_init(nodes+4, "fischen ");
	node_init(nodes+5, "lieben ");
	node_init(nodes+6, "Bananen ");
	node_init(nodes+7, "Fische ");
	node_init(nodes+8, "Wasser ");
	node_init(nodes+9, "Sonne ");
	edge_init(nodes, nodes+1, 0.5);			// \n -> Affen
	edge_init(nodes, nodes+2, 0.5);			// \n -> Fische
	edge_init(nodes+1, nodes+3, 0.3);		// Affen -> faulenzen
	edge_init(nodes+1, nodes+4, 0.3);		// Affen -> fischen
	edge_init(nodes+1, nodes+5, 0.4);		// Affen -> lieben
	edge_init(nodes+2, nodes+4, 0.5);		// Fische -> fischen
	edge_init(nodes+2, nodes+5, 0.5);		// Fische -> lieben
	edge_init(nodes+3, nodes, 1.0);			// faulenzen -> \n
	edge_init(nodes+4, nodes+6, 0.5);		// fischen -> Bananen
	edge_init(nodes+4, nodes+7, 0.5);		// fischen -> Fische
	edge_init(nodes+5, nodes+6, 0.25);	// lieben -> Bananen
	edge_init(nodes+5, nodes+7, 0.25);	// lieben -> Fische
	edge_init(nodes+5, nodes+8, 0.25);	// lieben -> Wasser
	edge_init(nodes+5, nodes+9, 0.25);	// lieben -> Sonne
	edge_init(nodes+6, nodes, 1.0);			// Bananen -> \n
	edge_init(nodes+7, nodes, 1.0);			// Fische -> \n
	edge_init(nodes+8, nodes, 1.0);			// Wasser -> \n
	edge_init(nodes+9, nodes, 1.0);			// Sonne -> \n
}

int main(int argc, char *argv[]) {
	if (argc > 1) {
		srand(time(0));
		node *nodes= new node[12];
		init_graph(nodes);
		int fische = traversal(nodes,atoi(argv[1]));
		cout << endl << "Anzahl der Fische: " << fische << endl;
		delete [] nodes;
	} else {
		cout << "Call with number of steps for traversal.\n";
	}
	return 0;
}
