klab6
=====

Drzewo BST


=====
Zalozenia:

 - lewy <= srodek < prawy
 - wskazniki w wezle : potomkowie, opcjonalnie parent, wartosc w wezle
 - (kolejnosc wstawiania wartosci do drzewa zmienia ksztalt drzewa)
 - indexowanie: numery wezlow - kolejnosc przy przeszukiwaniu drzewa, np metoda inOrder
 - algorytm np LVR: na lewo, do skutku, poytem odwiedz, potem na prawo
 - L-idz do lewego, V- visit -wypisz, R-idz na prawo, inne kombinajce VLR,RVL itd
 - at(i) = val nie moze byc przy replace, bo zaburza strukture drzewa
 - inna opcja: remove(i) insert(val)
 - w drzewie op= zrobic: wywolaj funkcje op= z klasy bazowej, zwroc this (zeby nie pisac 2 razy to samo)
