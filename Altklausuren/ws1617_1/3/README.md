### Approximation der ersten Ableitung

Bei dieser Aufgabe ist es sehr schwer, überhaupt zu verstehen, um was es geht. Nachdem man das Prinzip verstanden hat, wird aber eigentlich nur gefordert, ein paar Includes und zwei etwas anspruchsvollere Konstruktoren zu schreiben, eine handvoll (teilweise schwerer) Operatoren zu überladen und einen Eingabevektor einzulesen.

Da die Aufgabe so seltsam gestellt ist, ist meine Lösung mit **viel Vorsicht** zu genießen, denn ich bin mir selbst nicht sicher, ob ich das alles so richtig verstanden habe ... also keine Gewähr!

1. Die Includes. Damit der Code funktioniert, müssen einige Dinge eingebunden werden, unter Anderem auch das weniger bekannte **cfloat** für das DBL_EPSILON, **cmath** für den Sinus, **cassert** & **vector**, sowie die üblichen Verdächtigen **iostream** und **cstdlib**.

2. Die Konstruktoren. Es werden zwei Stück benötigt:
  - Ein Konstruktor, der ein fd Objekt mit einem gegebenen Startwert erstellt. Dieser Konstruktor sollte v und vs *beide* auf den mitgegebenen Wert setzen, erst die Funktion s() kann das Objekt *stören* und die beiden Werte voneinander abweichen lassen.
  
  - Ein zweiter Konstruktor, der ein *leeres* fd Objekt erstellen kann. Dieser Konstruktor sollte v und vs sinnvoller Weise auf 0 setzen.
  
  **Beide Konstruktoren müssen auch *logger* initialisieren, denn jedes *fd* Objekt enthält auch ein *logger* Objekt!** Da es keinen von C++ automatisch erstellten Standardkonstruktor für *logger* gibt (denn es wurde ein eigener erstellt!), müssen wir diesem Konstruktor einen Wert v mitgeben, welchen *logger* dann ausgibt. Wie das gemacht wird, seht ihr im Code.
  
  Der erste Konstruktor (mit Argument) ist besonders hilfreich, denn er wird von C++ **automatisch angewendet**, sobald für einen Operator *eigentlich* ein fd gebraucht wird, aber ein Double oder Int oder irgendwas Anderes da ist. Wenn ich im Code also schreibe "y=x+50", und y und x sind Variablen vom Typ fd, dann benutzt C++ ganz von alleine den angesprochenen Konstruktor, um aus dem Int 50 ein fd zu "basteln". In den meisten Fällen ist dies ausgesprochen praktisch, denn man muss nicht für jeden Zahlentyp ein eigenes Minus, Plus, Mal, Geteilt usw. schreiben!
  
3. Die Operatoren. Meiner Meinung nach müssen hier **fünf** Operatoren überladen werden, nämlich **++**, *****, **-**, **+=** und **sin()**. Damit das Testen leichter war, hab ich zusätzlich noch **<<** überladen. Bei allen Operatoren muss man einfach dafür sorgen, *dass mit v und vs das gleiche passiert*. 

  Damit der *logger* auch immer etwas sinnvolles ausgibt (das tut er nämlich immer, wenn ein fd *irgendwo* konstruiert wird!), habe ich den Wert für v meistens direkt im Konstrukor übergeben, und danach den Wert von vs manuell überschrieben. Das kann man bei sin(), \* und - sehen.
  
  **Operator++** ist fies, denn hier muss man ein "Dummy"-Argument angeben, weil es der *Postfixoperator* ist. Deswegen das int. Immer wenn man einen Postfixoperator überlädt, muss man darauf achten, eine *unveränderte Kopie des Originalwertes* zurückzuliefern. Das solltet ihr im Code sehen können.
  
  Beim **Operator+=** ist wichtig, dass die erste Referenz (also a) *nicht const ist*, denn die wollen wir ja verändern! Übrigens spielt der Rückgabetyp dieses Operators in diesem Fall keine Rolle, deshalb habe ich in void gelassen. Man darf hier aber auch fd oder eine fd Referenz zurückgeben!
  
4. Der Eingabevektor. Hier wusste ich nicht so recht, was hier überhaupt von einem verlangt wird. Ich habe das jetzt mal so interpretiert, dass man für den Eingabevektor die einzelnen Einträge vom User abfragen soll... Wo sonst sollte man irgendwelche Werte herbekommen?

Ich hoffe, meine Lösung ist hilfreich für euch.
  