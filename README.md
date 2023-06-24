# Miniprojekt
Wymagania do projektu:
W ramach zadania należy napisać własną metodę Algorytmu Genetycznego (AG). AG służy
do wyszukiwania jak najlepszych rozwiązań dla problemów optymalizacyjnych. Niniejsze zadanie, dla celów dydaktycznych związanych z kursem TEP, ograniczy się do
rozwiązywania binarnego problemu plecakowego (0/1 Knapsack Problem).

W ramach wykonania programu oprogramowano następujące klasy:
1. CKnapsackProblem
- Klasa pozwala na obsługę konkretnych instancji binarnego problemu
plecakowego
- umożliwia skonfigurowanie konkretnego obiektu tej klasy
(wprowadzenie informacji o liczbie przedmiotów, tabeli rozmiarów, oraz
wartości)
- dostarcza metodę, pozwalającą na wyliczenie wartości rozwiązania
zapisanego na konkretnym genotypie (tablicy, wektorze, liście zer i jedynek)

2. CGeneticAlgorithm
- klasa do obsługi uruchomienia konkretnej instancji AG
- uwzględniamy parametry wykonania AG (rozmiar populacji,
prawdopodobieństwo krzyżowania i mutacji)
- jako kryterium zatrzymania przyjęto liczbę iteracji metody
- po zakończeniu przebiegu AG obiekt daje możliwość pobrania
najlepszego rozwiązania znalezionego w trakcie przebiegu metody
3. CIndividual
- klasa osobnika
- osobnik posiada genotyp, kodujący rozwiązanie
- zawarta jest metoda wyliczająca przystosowanie danego osobnika, metoda mutująca danego osobnika oraz metoda pozwalająca skrzyżować danego osobnika z innym i
zwracająca utworzone w ten sposób dzieci 

# *INSTRUKCJA OBSLUGI ALGORYTMU GENETYCZNEGO*

Aby uruchomić algorytm, w klasie main tworzymy obiekt CKnapsackProblem opisujący nasz problem.Obiekt posiada składowe:
-liczba przedmiotów
-pojemność plecaka
-tabela rozmiarow
-tabela wartosci

Powyższe dane ładowane są z wybranego pliku testowego lub wpisywane w kodzie.

Następnie tworzona jest instancja CGeneticAlgorithm, która wymaga parametrów określających działanie algorytmu genetycznego:
-referencja do obiektu CKnapsackProblem, które przychowuje informacje o problemie
-liczebność jednej populacji 
-prawdopodobieństwo mutacji ( 0-1 )
-prawdopodobieństwo krzyżowania ( 0-1 )

Następnie program wykonuje się zadaną w pętli liczbę iteracji. Dla każdej iteracji zwracamy najlepszego osobnika( o najepszym fitnesie).
Widzimy, że w większości przypadków wraz ze zwiększaniem się iteracji fitness rośnie, ale zdarzają się anomalie.

Preferowane wartosci dla optymalnego dzialania:
    rozmiar populacji: 50-150
    prawdopodobienstwo krzyzowania: 0.5-0.7
    prawdopodobienstwo mutacji: 0.05-0.1
    liczba iteracji problemu: 50-200
