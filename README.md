# 103.4 Statki

## Skład zespołu
Michał Kaczmarczyk  
Maciej Stranz
## Opis projektu i główne założenia
1. Plansza do gry:
Plansza powinna być dwuwymiarową siatką, na której gracze rozmieszczają statki, możliwość wczytania ustawienia statków z pliku.
Plansza może być o dowolnym rozmiarze, na przykład 10x10.
Każde pole planszy reprezentuje jedno pole dla statku.
2. Statki:
Gra powinna obejmować różne rodzaje statków o różnych długościach (np. lotniskowiec, okręt wojenny, łódź podwodna).
Każdy statek zajmuje określoną ilość pól na planszy.
Statki nie mogą nachodzić na siebie ani stykać się bokami.
3. Rozstawianie statków:
Gracze powinni mieć możliwość rozmieszczenia swoich statków na planszy przed rozpoczęciem gry.
Rozstawianie może być losowe lub manualne, zależnie od wyboru gracza lub wybrane z pliku.
4. Ruchy graczy:
Gracze wykonują ruchy, oddając strzały na planszę przeciwnika.
Po oddaniu strzału, gra informuje gracza, czy trafił w statek przeciwnika czy nie.
5. Cel gry:
W zależności od typu gry mogą być różne cele:
Celem gry jest zatopienie wszystkich statków przeciwnika.
Gracz, który zatopi wszystkie statki przeciwnika, wygrywa.
Celem gry jest dotarcie do ustalonego punktu szybciej niż przeciwnicy
6. Zasady strzałów:
Gracz podaje współrzędne strzału, np. A3.
Gra informuje, czy strzał trafił, zatopił statek czy chybiono.
7. Komunikaty:
Gra powinna dostarczać czytelne komunikaty, informujące gracza o wynikach jego ruchu.
8. Tryb gry:
Gra może oferować tryb jednoosobowy (gracz kontra komputer) oraz tryb wieloosobowy (gracz kontra gracz).
9. Interfejs użytkownika:
Komunikacja odbywa się przez konsolę
10. Walidacja danych:
Zapewnienie sprawdzania poprawności wpisanych przez użytkownika pół np. niedozwolone są pola znajdujące się poza planszą.
11. Zapis i wczytywanie gry:
Gra powinna umożliwiać zapisywanie stanu gry, aby gracze mogli kontynuować rozgrywkę później.
12. Gra wieloetapowa:
Etap rozmieszczania statków i etap właściwej gry, aby umożliwić graczom planowanie strategii.
13. Zastosowanie struktur danych:
Wykorzystanie struktur danych z biblioteki standradowej. 
14. Obsługa błędów:
Obsługa błędów dla sytuacji wyjątkowych, takich jak podanie nieprawidłowych współrzędnych czy próba ruchu poza planszą.
## Początkowy podział na klasy i podklasy

-  Game

-  GameRules
    - SeaBattle
    - SailToDestination
    - ExtendedSeaBattle
-  Ship
    - SmallShip
    - BigShip
    - RadarShip
-  Player
    - RandomPlayer
    - HumanPlayer
    - AIPlayer
-  Map

## Wstępny diagram klas UML
![uml_statki.drawio](/uploads/601f0317cb058c9d87de30a45ddd7402/uml_statki.drawio.png)


