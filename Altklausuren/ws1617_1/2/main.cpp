#include <cassert>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class land_t {
  bool besucht; // wurde ich besucht? (wird für "erreichbar" Funktion gebraucht)
  unsigned int i; // meine ID
  land_t* v;  // Pointer auf nächstes Land in der Landkarte
  struct nachbar_t {
    land_t* n;  // Pointer auf das zugehörige Land
    nachbar_t* v; // Pointer auf den nächsten Nachbar
    nachbar_t(): n(0), v(0) {}
  } *nachbarn;  // eine Liste mit all meinen Nachbarn
public:
  land_t(int i): i(i), besucht(false), v(0), nachbarn(0) {}
  
  void neuer_nachbar(land_t* nb) {
    if (nachbarn == 0) {  // ich habe noch keine Nachbarn!
      nachbarn = new nachbar_t(); // neuen Nachbar erstellen
      nachbarn->n = nb; // zugehöriges Land angeben
    } else { // ich habe bereits Nachbarn!
      nachbar_t* p = new nachbar_t(); // neuen Nachbar erstellen
      p->n = nb;  // zugehöriges Land angeben
      p->v = nachbarn;  // bisherige Nachbarn an neuen Nachbar anhängen
      nachbarn = p; // neuen Nachbar ist neuer Anfang der Liste
    }
  }
  
  void ausgabe() {
    cout << i << " ( ";
    nachbar_t* n = nachbarn;
    while (n!=0) { cout << n->n->i << " "; n=n->v; }
    cout << ")" << endl;
  }
  
  bool erreichbar(land_t* b) {
    if (b==this and besucht==false) { // ich bin das Ziel, und bin von mir selbst aus erreichbar!
      cout << i << " "; // Ausgabe meiner ID
      return true;
    } else {
      if (besucht) {  // ich wurde schon besucht, also muss ich nicht alles nochmal prüfen
        return false;
      } else {  // ich werde zum ersten Mal besucht
        besucht = true; // ich merke mir, dass ich besucht wurde
        bool result = false;
        nachbar_t* p = nachbarn;  // Hilfspointer
        while (p) { // frage alle meine Nachbarn, ob Ziel erreichbar ist, bis keine mehr da sind
          result = p->n->erreichbar(b);
          if (result) { // ein Nachbar sagt, das Ziel ist von ihm aus erreichbar!
            cout << i << " "; // Ausgabe der eigenen ID, denn ich bin Teil der Route zum Ziel!
            return true;  // meinem Vorgänger sagen, dass Ziel von mir aus erreichbar ist
          } else { // frage nächsten Nachbar
            p = p->v;           
          }
        }
        return false;  // Ziel ist von keinem meiner Nachbarn erreichbar...
      }
    }
  }
  
  friend class landkarte_t;
};

class landkarte_t {
  land_t* laender;  // Liste aller Länder
public:
  land_t* finde_land(int id) {
    land_t* p = laender;  // Hilfspointer
    while (p->i!=id and p!=0) { // Suche Land in der ganzen Liste
      p = p->v;
    }
    return p;
  }
  
  landkarte_t(ifstream& in) : laender(0) {
    int n; in >> n; // Anzahl Länder einlesen
    for (int i=0;i<n;i++) {
      int id; in >> id; // nächste ID einlesen
      land_t* p = new land_t(id); // neues Land erstellen
      p->v = laender; // bisherige Länder an neues Land anhängen
      laender = p; // neues Land ist neuer Anfang der Liste
    }
    in >> n;  // Anzahl Grenzen einlesen
    for (int i=0;i<n;i++) {
      int a,b; in >> a; in >> b; // Nachbarländer einlesen
      assert(a!=b);
      assert(finde_land(a));
      assert(finde_land(b));
      /* Um Grenze zu erstellen, müssen beide Länder
      sich gegenseitig in ihre Liste aus Nachbarn eintragen! */
      finde_land(a)->neuer_nachbar(finde_land(b));
      finde_land(b)->neuer_nachbar(finde_land(a));
    }
  }
  
  ~landkarte_t() {
    land_t* p = laender;
    while (p) {
      p = p->v; // Vor der Löschung eines Landes, müssen wir noch zum nächsten Land!
      delete laender;
      laender = p;
    }
  }
  
  bool erreichbar(land_t* a, land_t* b) {
    assert(a); assert(b);
    cout << "Erreichbar " << a->i;
    cout << "->" << b->i << "? ";
    /* Hier passiert die komplette Suche, indem alle Länder
    sich untereinander fragen, ob das Ziel von den jeweils anderen erreichbar ist */
    bool e = a->erreichbar(b);
    // Je nach Ergebnis ändert sich die Ausgabe
    if (e) {
      cout << "JA" << endl;
    } else {
      cout << "NEIN" << endl;
    }
    /* Nachdem die Suche abgeschlossen ist, müssen alle
    Länder wieder vergessen, dass sie besucht worden sind,
    damit die nächste Suche funktionieren kann */
    land_t* p = laender;
    while (p) {
      p->besucht = false;
      p = p->v;
    }
    return e; // Gebe Ergebnis zurück (optional, Funktion hätte für die Aufgabe auch "void" sein können!)
  }
  
  void ausgabe() {
    land_t* l=laender;
    while (l!=0) { l->ausgabe(); l=l->v; }
  }
};

int main(int c, char* v[]) {
  assert(c==2);
  ifstream in(v[1]);
  landkarte_t l(in);
  l.ausgabe();
  l.erreichbar(l.finde_land(0),l.finde_land(6));
  l.erreichbar(l.finde_land(0),l.finde_land(0));
  l.erreichbar(l.finde_land(5),l.finde_land(7));
  in.close();
  return 0;
}