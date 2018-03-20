#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

class matrix {
  int s, **m; // Größe und Einträge der Matrix
  
public:
  // Konstruktor
  matrix(ifstream& in) {
    in >> s;  // Größe der Matrix einlesen
    m = new int*[s];
    for (int i=0; i<s; i++) {
      m[i] = new int[s];
      for (int j=0; j<s; j++) {
        in >> m[i][j];  // Einträge einlesen
      }
    }
  }
  
  // Destruktor
  ~matrix() {
    for (int i=0; i<s; i++) delete[] m[i];
    delete[] m;
  }
  
  // Kopierkonstruktor
  matrix(const matrix& n): s(n.s) { // kopierte Matrix hat gleiche Größe
    m = new int*[s];
    for (int i=0; i<s; i++) {
      *m = new int[s];
      for (int j=0; j<s; j++) {
        m[i][j] = n.m[i][j];  // Einträge kopieren
      }
    }
  }

  // Zuweisungsoperator
  matrix& operator=(const matrix& n) {
    assert(s==n.s); // Größe der Matrizen muss gleich sein!
    for (int i=0; i<s; i++) {
      for (int j=0; j<s; j++) {
        m[i][j] = n.m[i][j];  // Einträge übertragen
      }
    }
    return *this; // Rückgabe von "sich selbst"
  }
  
  // Spur der Matrix berechnen
  int trace() { 
    int result = 0;
    for (int i=0; i<s; i++) result += m[i][i];  // Summe der Diagonaleinträge
    return result;
  }
  
  // Matrix ausgeben
  void print(ofstream& out){
    out << s << endl; // Größe ausgeben
    for(int j=0;j<s;j++)
      for(int i=0;i<s;i++)
        out << m[j][i] << " ";  // Einträge hintereinander ausgeben
    out << endl;
  }
};

class matrix_list_element {
  matrix *m;  // Pointer auf Matrix
  matrix_list_element *next;  // Pointer auf nächstes Element
  
public:
  // Kostruktor
  matrix_list_element(matrix* m): m(m), next(0) {}

  // Destruktor
  ~matrix_list_element() {
    /* Reihenfolge der "deletes" ist hier unwichtig.
    So wie es hier steht, löscht sich die Liste von
    hinten nach vorne, anders herum würde sie sich
    von vorne nach hinten löschen! */
    delete next;  // nächstes Element (falls != 0) deallozieren
    delete m; // eigene Matrix deallozieren
  }
  
  // Verbot von...
private:
  // ...Kopierkonstruktor
  matrix_list_element(const matrix_list_element&);
  // ...Zuweisungsoperator
  matrix_list_element& operator=(const matrix_list_element&);
 
  // Erlaubnis Zugriff auf private Daten durch matrix_list
  friend class matrix_list;
}; 

class matrix_list {
  matrix_list_element* head;  // Pointer auf erstes Element
  
public:
  // Konstruktor
  matrix_list() : head(0) {} // Null pointer, denn es gibt noch kein erstes Element

  // Destruktor
  ~matrix_list() {
    delete head;  // erstes Element (falls != 0) deallozieren (Kettenreaktion!)
  }
  
  // Matrix an Liste anhängen
  void add_matrix(matrix* m) {
    if (head) { // es gibt mindestens 1 Element
      matrix_list_element* p = head;  // Hilfspointer erstellen
      while (p->next) p = p->next;  // rücke Pointer bis ans Ende der Liste
      p->next = new matrix_list_element(m); // füge letztem Element ein neues Element hinzu
    } else {  // Liste ist noch leer
      head = new matrix_list_element(m);  // füge erstes Element hinzu
    }
  }

  // Matrix mit größter Spur finden
  matrix* max() {
    if (head) { // es gibt mindestens 1 Element
      // Zwei Hilfspointer:
      matrix_list_element* current = head;  // aktuell untersuchtes Element
      matrix_list_element* highest = head;  // größtes Element
      while (current->next) { // durch alle Element der Liste gehen
        if (current->m->trace() > highest->m->trace()) { // vergleiche aktuelles mit größtem Element
          highest = current;  // aktuelles Element ist größer
        }
        current = current->next; // nächstes Element
      }
      return highest->m; // Rückgabe der Matrix mit größter Spur
    } else { // Liste is leer!
      return 0;
    }
  }
  
  // Verbot von...
private:
  // ...Kopierkonstruktor
  matrix_list(const matrix_list&);
  // ...Zuweisungsoperator
  matrix_list& operator=(const matrix_list&);
};

int main(int c, char* v[]) {
  assert(c==3); // Wir brauchen drei Argumente
  ifstream in(v[1]);  // Name der Eingabedatei
  ofstream out(v[2]); // Name der Ausgabedatei
  int l; in >> l; // Anzahl Matrizen in der Liste einlesen
  matrix_list ml; // Neue (leere) Liste erstellen
  for (int i=0;i<l;i++)
    ml.add_matrix(new matrix(in)); // Matrizen einzeln hinzufügen
  ml.max()->print(out); // Matrix mit größter Spur ausgeben
  return 0;
}