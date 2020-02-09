Bei Aufgabe 2 scheint es in der Klausur einen Fehler gegeben zu haben, zumindest kommt man sonst auf keine für mich ersichtliche Weise zu dem gewünschten Ergebnis.

Es scheint so, als müsste in der entscheidenden Zeile eigentlich der Aufruf von `f(...)` und das `a` getauscht werden, damit die Reihenfolge der Operationen anders ist. Der `operator*` nimmt sonst nämlich den alten Wert von `a`, bevor das `f(...)` diesen verändert, und führt damit die Multiplikation aus.

Das `f(...)` muss in jedem Fall eine 1 zurückgeben ... und da das `a` am Anfang 2 ist und nicht 64, wird auch eine 2 ausgegeben.
