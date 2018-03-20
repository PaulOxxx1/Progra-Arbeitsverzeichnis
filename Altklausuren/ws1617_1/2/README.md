### Landkarte

Die *Ausgabe* stimmt zwar nicht mit der in der Klausur geforderten überein (hab ich nicht hingekriegt), aber vom Prinzip her tun die beiden *Erreichbar*-Funktionen das Richtige und die Landkarte funktioniert!

Ein paar Anmerkungen zu der Aufgabe:

1. Relativ verwirrend ist der Pointer *nachbarn* in der *land_t* Klasse. Hier wird der Typ (bzw. Struct) *nachbar_t* quasi *vor dem Sternchen der Pointer-Deklaration **komplett** definiert* ... sozusagen *auf einer Zeile!* So etwas hatte ich vor dieser Klausur *noch nie* gesehen, denn normalerweise definiert man sich seine Typen (bzw. Structs) irgendwo anders, niemals in *der selben Zeile, in der man sie zum ersten Mal verwendet!*
2. Sowohl die Liste aller Länder (Landkarte), als auch die Liste von den eigenen Nachbarn, die jedes Land für sich führt, sind alle als **einfach verkettete Liste** implementiert. Bei einer Landkarte mit 5 Ländern gibt es z.B. *eine Hauptliste* und *fünf Listen mit Nachbarn*, jedes Land hat seine eigene Liste. Zum Thema "einfach verkettete Liste" findet man sehr viel auf Google.
3. Das schwerste an der Aufgabe sind die beiden Funktionen **erreichbar** in den beiden Klassen *landkarte_t* und *land_t*. Die beiden Funktionen arbeiten zusammen, um herauszufinden, ob zwischen zwei Ländern der Landkarte eine Route besteht. Dabei ist die gefundene Route nicht zwangsläufig die kürzeste, sondern die erste, die gefunden wird, also relativ zufällig. Ausgehend vom Startland werden *alle möglichen Routen* zu *allen erreichbaren Ländern* abgelaufen, und jeweils geschaut, ob das Zielland unter diesen Ländern zu finden ist. Ich habe versucht, die Funktionsweise in den Kommentaren im Code zu erklären. 
