Krzysztof Banecki, Przemysław Kaleta

Temat naszego projektu:
10.Abelowa gra w zabronione wzorce

W modelu abelowym dwa słowa są równe, jeśli ich multipodzbiory liter są takie same tj. jedno słowo jest spermutowanym drugim słowem.
Dla przykładu wzorzec xx, występuje w słowie abccab, gdyż kolejno powtarza się słowo "abc"="cab".

Na czym polega gra?
Na początku ustalamy pewien wzorzec, przykładowo xx, xyx, xxx, xyy, xxyy itp.
W grę grają dwie osoby. Pierwszy gracz pokazuje miejsce w słowie, drugi wstawia tam wybraną literę z alfabetu. Pierwszy gracz chce zmusić drugiego do ułożenia zakazanego wzorca (w sensie abelowym), drugi stara się układać słowo niezawierające podanego wzorca (w sensie abelowym). Gracz pierwszy wygrywa, gy w słowie wysąpi wzorzec (w sensie abelowym), gracz drugi wygrywa, gdy słowo osiągnie zadaną długość, a wzorzec się nie pojawi (w sensie abelowym).

22.03.2018
W nagłówkach pomocniczych funkcji przy *charach dodałem const.
Zaimplementowałem możliwość gry dwóch graczy ze sobą.