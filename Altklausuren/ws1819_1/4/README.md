Es gibt zwei Arten, die `is_path` Methode zu implementieren, einmal mithilfe von Rekursion und einmal ohne.

In `main.cpp` habe ich sie mit Rekursion implementiert, das heißt man schaut immer nur, ob der *nächste Schritt* entlang des Pfads gültig ist, und ruft dann die Funktion einfach nochmal mit einem kürzeren Pfad auf, so lange bis der Pfad nur noch einen Knoten enthält. Gelingt dies, so ist der Pfad korrekt.

Wie immer bei Rekursion muss man darauf achten, dass man ihr einen Rekursions**anfang** und einen Rekursions**schritt** gibt, in diesem Fall prüfe ich für den Rekursionsanfang, ob die Liste schon nur noch eine Zahl enthält, und für den Rekursionsschritt verkleinere ich ggf. die Liste. So ist garantiert, dass die Funktion irgendwann an ein Ende gelangt.

In `main2.cpp` ist die Variante ohne Rekursion implementiert, die man sicher etwas leichter verstehen kann. Hier wird der Pfad einfach von Anfang bis Ende geprüft, wobei man immer schauen muss, ob die Verbindungen zwischen zwei benachbarten Knoten im Pfad existieren.

Die Funktion `to_dot` ist vermutlich nur für den Kontext da, so dass man z.B. bemerken kann, dass hinter dem `vertices` immer ein `->` steht, und man es somit auch im eigenen Code nicht vergisst. Außerdem wird ein `std::ofstream` verwendet, was ein Hinweis sein sollte, dass man `fstream` einbinden muss. Ansonsten kann man die Datei, die dadurch generiert wird, online unter http://webgraphviz.com in ein richtiges Bild eines Graphen verwandeln, wenn man nochmal per Hand prüfen will, ob die Pfade alle soweit möglich sind oder nicht.

Die `assert` statements sind soweit recht willkürlich gesäht, da habe ich einfach mal geschaut, was denn so alles sinnvoll wäre. Ob das `assert(filename)` wirklich sinnvoll ist, darüber lässt sich streiten, aber die anderen ergeben durchaus Sinn. Man sollte aber schon darauf achten, dass auch Graphen mit 0 Knoten bzw. Knoten mit 0 Kanten durchaus vorkommen dürfen.

In der Funktion `is_path` sind mir keine guten `assert`s eingefallen, da man hier ohnehin nur den Parameter `path` prüfen könnte ... und dieser Vektor dürfte durchaus auch 0 Zahlen beinhalten, was meiner Meinung nach ein valider Pfad wäre ... aber das ist in der Aufgabe auch nicht genau genug definiert.