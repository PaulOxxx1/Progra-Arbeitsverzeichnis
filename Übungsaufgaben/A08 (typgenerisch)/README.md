Diese neue Version der Aufgabe wurde im ws1819 erstellt, da in diesem Jahr eine **typgenerische** Version der Aufgabe gefordert war (Aufgabe 13).

In der Musterlösung zu der Aufgabe wurden nur .hpp Dateien erstellt, da es diese Aufgabe deutlich leichter macht, einfach den gesamten Code in die Headerdateien zu schreiben. Wenn man die Funktionen allerdings in .cpp Dateien auslagern will, muss man in vor all diese Funktionen `template<typename T>` schreiben, damit man innerhalt der Funktion die typgenerischen Typen verwenden kann.

Außerdem ist es noch entscheidend, dass man in der .cpp Datei *einmal* die Klasse mit dem konkreten Typ aus der Aufgabe erwähnt. Ich habe das immer nach dem Konstruktor der Klassen gemacht, z.B. bei der Polynom Klasse:

`template polynom<double>::polynom(int, std::vector<double>);`

Ich verstehe selbst nicht ganz, warum das notwendig ist, aber es hat etwas damit zu tun, dass Typgenerik nicht richtig funktioniert, wenn man die Klassen in .hpp und .cpp Dateien aufteilt. Der Übersetzungsprozess geht dann schief. Man kann dazu im Internet sicher eine gute Erklärung finden.