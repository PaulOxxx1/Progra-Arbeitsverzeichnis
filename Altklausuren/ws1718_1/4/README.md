Die Aufgabe handelt hauptsächlich von *Operatorüberladung*, mit deren Hilfe man "automatisches Differenzieren" implementieren kann.

Bei `main.cpp` handelt es sich um die (vermutlich) geforderte Lösung der Aufgabe, zu `main2.cpp` komme ich später...

Die Anmerkungen im Code sollten eigentlich recht selbsterklärend sein, trotzdem ein paar kleine Anmerkungen:

1. Ich verstehe nicht ganz, warum man für den _einen_ Konstruktor bereits 4 Punkte laut Aufgabe bekommen sollte ... allerdings benötigt die Klasse definitv keine Destruktoren, Kopierkonstruktoren oder Zuweisungsoperatoren, weil sie keine dynamischen Daten verwaltet und auch sonst nix besonderes machen muss, wenn Objekte kopiert oder zerstört werden. Vielleicht gab es die vielen Punkte für diese Erkenntnis.

2. Laut Aufgabe braucht man 7 verschiedene Operatoren, allerdings funktioniert der Code auch einwandfrei mit nur 6. Man kann spekulieren, dass man noch ein "einseitiges Minus" implementieren sollte, weil ja auch der Hinweis in der Aufgabenstellung die Ableitungsregeln "(-w).dvdx = -w.dvdx" enthält. Dennoch würde dieser Operator theoretisch niemals aufgerufen, weil er im Code der Beispielfunktionen nicht auftaucht. Das einseitige Minus in f2 (vor der 42.42) steht nicht vor einem "A", sondern vor einem float, und ist daher schon implementiert.

*Implizite Typkonvertierung - und warum die Aufgabe komisch gestellt ist*

In C++ gibt es sogenannte "implizite Typkonvertierung" (kann man googlen ...). Sie handelt nach dem Prinzip "was nicht passt, wird passend gemacht" ... sofern es möglich ist. Wenn es also irgendwo einen Konstruktor gibt, der `float`s in `A`s umwandelt, so kann man auch `float`s in Funktionen stecken, die eigentlich nur `A`s akzeptieren würden ... die Konvertierung passiert automatisch. Durch diesen Trick ist es möglich, einfach einen solchen Konstruktor zu definieren, und dann kann man sich die Hälfte der Operatoren sparen ... man muss zB `operator*` jetzt nur noch für zwei `A`s definieren, und nicht mehr für den Fall, dass die rechte Seite ein `float` ist.

In `main2.cpp` habe ich eine solche alternative Lösung implementiert, die zum gleichen Ergebnis kommt, allerdings mit nur 3 Operatoren.

Da in der Aufgabenstellung nach 7 Operatoren gefragt wurde, vermute ich, dass eine solche Lösung nicht explizit gewünscht gewesen ist, aber bestimmt auch akzeptiert worden wäre.