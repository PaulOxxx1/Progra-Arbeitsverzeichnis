### 1. Vererbung
Der Sinn dieser Übungsaufgabe ist es, zu verstehen, dass eine erbende Klasse immer auch ein Objekt der Basisklasse *enthält*.

Das bedeutet, dass bei der *Konstruktion* von B auch immer zuerst ein A "mitgebaut" wird, auf welches das B dann "draufgebaut" wird. Jedes B enthält also ein A!

Wenn nun ein B *abgebaut* wird, muss erst der "B-Teil" vom B abgebaut werden, bevor der "A-Teil" vom B abgebaut wird. Daher die Reihenfolge bei der Ausgabe!

Nun zum C. Da C von B erbt, enthält jedes C auch ein B, und somit auch ein A. Man kann es sich vorstellen wie eine von diesen russischen Babuschka Figuren! Baut man also ein C auf, muss erst ein A, dann ein B und dann ein C aufgebaut werden, beim Abbau genau umgekehrt!
  
### 2. Minus und Plus
In dieser Aufgabe geht es zwar nur darum, ein paar Operatoren zu überladen, es gibt aber zwei relativ fiese Fallen.

**Falle 1:** Innerhalb der Funktion f heißt das *erste* Argument x und das *zweite* Argument y. In der main Funktion, in der f aufgerufen wird, ist es umgekehrt!

**Falle 2:** Damit nach Aufruf von f das richtige Ergebnis herauskommt, muss man etwas kreativer bei den Operatoren sein. Schaut man sich die Rechnung in f genau an, so würde mit x=2 und y=3 bei "normalen" Rechenzeichen **-1** als Ergebnis rauskommen, statt der gewünschten **-3**. Um das richtige Ergebnis zu bekommen, muss man ... entgegen aller Vernunft ... bei den Operatoren dafür sorgen, dass *das + wie ein - funktioniert und umgekehrt!*

