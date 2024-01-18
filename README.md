# 103.4 Statki

## Skład zespołu
Michał Kaczmarczyk  
Maciej Stranz
## Opis projektu i główne założenia
1. Plansza do gry:
Plansza powinna być dwuwymiarową siatką wczytujemy ustawienia statków z pliku.
Plansza może być o dowolnym rozmiarze, na przykład 10x10.
Każde pole planszy reprezentuje jedno pole dla statku.
2. Statki:
Gra powinna obejmować statki o różnych długościach
Każdy statek zajmuje określoną ilość pól na planszy.
Statki nie mogą nachodzić na siebie ani stykać się bokami.
3. Rozstawianie statków:
Wybranie rozstawionych statków z predefioniowanych plików
4. Ruchy graczy:
Gracze wykonują ruchy, oddając strzały na planszę przeciwnika.
Po oddaniu strzału, gra informuje gracza, czy trafił w statek przeciwnika czy nie.
Informacja ta znjaduje się na mapie która jest wyświetlana
5. Cel gry:
W zależności od typu gry mogą być różne cele:
Celem gry jest zatopienie wszystkich statków przeciwnika.
Gracz, który zatopi wszystkie statki przeciwnika, wygrywa.
6. Zasady strzałów:
Gracz podaje współrzędne strzału, np. (1, 3).
Gra informuje, czy strzał trafił czy chybiono.
7. Komunikaty:
Gra powinna dostarczać czytelne komunikaty, informujące gracza o wynikach jego ruchu. W naszym wypadku na mapie przeciwnika pokazuje się jeden z 3 oczywistych symboli(x, ?, m) gdzie x oznacza trafiony, m pudło a ? oznacza pole którego nie sprawdzaliśmy
8. Tryb gry:
Gra może oferować tryb jednoosobowy (gracz kontra komputer) oraz tryb wieloosobowy (gracz kontra gracz).
9. Interfejs użytkownika:
Komunikacja odbywa się przez konsolę
11. Zapis i wczytywanie gry:
Gra Zapisuje partię do pliku txt, mapa jest wczytywana z wcześniej predefiniowanych map
12. Gra wieloetapowa:
Etap wyboru typu graczy oraz map i etap właściwej gry.
13. Zastosowanie struktur danych:
Wykorzystanie struktur danych z biblioteki standradowej. 
14. Obsługa błędów:
Obsługa błędów dla sytuacji wyjątkowych, takich jak podanie  próba ruchu poza planszą, a także nieudane próby odczytu.
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

## Końcowy diagram klas UML
![uml_statki_final.drawio.png]

## Planowany podział prac
Michał Kaczmarczyk
- Klasy Game, SeaBattle, ExtendedSeaBattle, RandomPlayer, HumanPlayer
- Klasy odpowiadające za statystyki oraz dobieranie poziomu przeciwnika      

Maciej Stranz
- Klasy Ship, Map, PlayerAI, SailToDestination
- Klasy służace do zapisu i odczytu stanu gry oraz mapy.

## Aktualny stan projektu

Stworzona wersja 3.0 pozwala na przeprowadzenie symulacji gry pomiędzy dwoma graczami, możliwy jest wybór pomiędzy graczem Human, Random oraz AI. Mapa statków jest stała oraz wczytywana z pliku, gra toczy się do momentu, aż wszystkie statki jednego z graczy zostaną zatopione. Na koniec symulacji wyświetlany jest komunikat, który gracz wygrał wraz z gratulacjami dla gracza. W początowym etapie należy wybrać Jakiego typu gracz ma grać oraz wybranie mapy z pliku.
Gracz typu HumanPlayer ma możliwość wyboru czy w danej kolejce chciałby oddać strzał do przeciwnika czy przepłynąć statkiem do innego miejsca. Warunek możliwości przepłynięcia to nieuszkodzony statek.

## Podział plików
Projekt został podzielony na 3 podfoldery
- app (główna aplikacja)
- lib (biblioteka zawierająca wszystkie klasy)
- tests (testy jednostkowe)

W folderze zbudowanej aplikacji przechowywane są również dwie mapy ze statkami o nazwach testmap.txt oraz testmap2.txt

## Ostateczny podział klas
Główną klasą jest klasa Game w której toczy się rozgrywka, klasa agreguje obiekt klasy Communicator oraz dwóch Playerów. Klasa Player reprezenotwana jest przez trzystopniową hierarchię dzdiedziczenia jako nadrzędna jest klasa Player, z klasy Player dziedziczy RandomPlayer i HumanPlayer. Klasą podrzędną do RandomPlayer jest AdvancedAIPlayer.
Gracz ma w sobie strukturę maps która reprezentowana jest przez std::pair dwóch sprytnych wskaźników do Map, swojej oraz mapy przeciwnika. Do mapy przypisane są obiekty typu Ship. Mapa składa się z wektora wektorów klasy Filelds.

## Wyjątki
- Niepoprawna ścieżka do pliku
- Nie można przepłynąć na to pole

## Testy klas
W projeciek zostały przetestowane wszystkie podstawowe funkcjonalności przy użyciu testów jednostkowych, stosowaliśmy do tego bibliotekę Catch2. Poza testami jednostkowymi cały program był przez nas testowany ręcznie w trakcie rozwoju aplikacji oraz sprawdzaliśmy końcową wersję rozgrywki.

## Wybrane struktury danych z STL
W projkecie zostały użyte
- std::vector
- std::pair
- std::shared_ptr

Korzystaliśmy róœnież z funkcji std::sort, std::findif

## Najciekawsze fragmenty kodu

Funkcja shoot dla AdvancedAIPlayer który po trafionym strzale, zamiast strzelać dalej w przypadkowe pola strzela w pola znajdujące się obok ostatnio trafioneg pola. Pozwala nam to zwiększyć prawdopodobieństwo wygranej tego przeciwnika nad RandomPalyerem.

Funkcja move dla klasy ship, wykorzystuje dość podobną mechanikę, musi sprawdzić czy statek którym chcemy się przemieścić jest "cały" następnie, sprawdzić czy będzie miał wystarczająco miejsca aby nie ustawić go na innym statku ale też zachować wymagane odstępy od innych statków.




