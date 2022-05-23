## Znajdywanie najdłuższej sekwencji kolejnych liter w macierzy 

Omawialiśmy już podobne zadanie, tym razem jednak naszym celem jest odnalezienie najdłużej sekwencji kolejnych liter. Nie musimy koniecznie startować od litery <h>A</h>, przykładowo poszukiwany ciąg może wyglądać następująco <h>I J K L M N</h>. Domyślamy się zapewne, że trzeba będzie sprawdzić każde pole w macierzy i dokonać przejścia <h>DFS</h> w celu znalezienia najdłuższej kombinacji dla danego pola.


Oczywiście marnujemy tutaj cenną informację. Przykładowo, jeżeli zbadaliśmy ciąg <h>I J K L M N</h>, to, jeżeli teraz zaczniemy od litery <h>J</h>, to znajdziemy <h>J K L M N</h>, czyli na pewno nie poprawimy wyniku, więc nie ma sensu już dokonywać przeszukiwania. Niestety, aby poradzić sobie z takim problemem musielibyśmy skorzystać z programowania dynamicznego, które przechowywałoby częściowe wyniki. Wykracza to jednak po za zakres podstaw z algorytmów, dlatego też wykonamy ten algorytm przechodząc przez każda literę w macierzy.


Złożoność, obliczeniowa będzie na poziomie <h>O(MN^2)</h>. Gdyż dokonujemy <h>(MN)</h> przejść przez macierz, z czego każde przejście średnio zajmie nam <h>O(MN)</h> czasu. Cały algorytm sprowadza się do przejścia <h>DFS</h>, w którym to sprawdzamy kolejno wszystkie <h>8</h> możliwych ruchów, jeżeli odnajdziemy następną z sekwencji literę <h>prev + 1 == matrix[y][x]</h>, to kontynuujemy poszukiwania, w innym razie zwracamy <h>0</h>. 


Oczywiście aby uwzględnić finałową długość, musimy dodawać do każdego wyniku <h>+1</h> 

```C++
longestSequence(matrix,
                y + y_moves[i], 
                x + x_moves[i],
                matrix[y][x]) + 1;
```

W ten sposób, jeżeli udało nam się w pierwszym kroku znaleźć kolejna liczbę nasz <h>max_length</h> ma już wartość <h>2</h>. Wtedy też w następnym ruchu osiągniemy <h>3</h>, potem <h>4</h> itd.


Gdy zakończymy już rekurencyjne sprawdzanie w każdym z <h>8</h> kierunków zwracamy największą ze znalezionych wartości <h>max_length</h>.

```C++
int longestSequence(const Matrix2& matrix, int y, int x, char prev) {
    constexpr const size_t kMoves = 8;
    constexpr const std::array<int, kMoves> x_moves{-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr const std::array<int, kMoves> y_moves{-1, 0, 1, 1, -1, -1, 0, 1};

    if (prev != '0' && (outOfRange(matrix, x, y) || prev + 1 != matrix[y][x])) {
        return 0;
    }

    int max_length = 1;
    for (int i = 0; i < kMoves; ++i) {
        max_length = std::max(max_length,
                              longestSequence(matrix, y + y_moves[i], x + x_moves[i], matrix[y][x]) + 1);
    }

    return max_length;
}

int longestSequence(const Matrix2& matrix) {
    int max_length = 0;

    for (int y = 0; y < matrix.size(); ++y) {
        for (int x = 0; x < matrix.front().size(); ++x) {
            max_length = std::max(max_length, longestSequence(matrix, y, x, '0'));
        }
    }

    return max_length;
}
```
<!-- .slide: style="font-size: 0.60em" -->


#### Programowanie dynamiczne

Podmienienie tego algorytmu, tak, aby wykorzystywał już raz obliczone wartości (korzystając z programowania dynamicznego), nie jest trudne w tym przypadku. Potraktujcie ten kod, jako przystawkę, do <h>zaawansowanych algorytmów</h>. 

Nie musicie się przejmować, jeżeli nie zrozumiecie algorytmu, gdyż w odpowiednim momencie omówimy wystarczająco dużo przykładów, aby programowanie dynamiczne stało się bardziej intuicyjne.


Tymczasowe wyniki przechowywać będziemy w mapie. Kluczem mapy będzie <h>Point</h>, czyli <h>x, y</h>. Dlatego musimy utworzyć własną funkcję mieszającą w przestrzeni nazw <h>std</h>. 

Dysponując już taką mapą dokonujemy trzech modyfikacji algorytmu:

- W głównej funkcji: Jeżeli dany punkt znajduje się już w mapie, to nie dokonujemy jego sprawdzania, gdyż znamy już dla niego wynik,

- W pomocniczej funkcji: Jeżeli dany punkt był już sprawdzany, kończymy rekurencje i zwracamy aktualny wynik przechowywany w mapie,

- W pomocniczej funkcji: Jeżeli zakończyliśmy wywołania rekurencyjne dla danego kroku w pętli, zapisujemy otrzymany wynik w mapie, a by w przyszłości móc wykorzystać go jeszcze raz.


Rośnie nam w ten sposób złożoność pamięciowa, jednak znacząco przyspieszamy samo wykonanie algorytmu, gdyż tak naprawdę przechodzimy przez dany element w macierzy tylko raz. Za każdym kolejnym razem zwracamy otrzymaną długość dla danego punktu, zatem złożoność maleje w znaczącym stopniu z `O(nm^2)` do `O(nm)`!


```C++
namespace std {
template <>
struct hash<Point> {
    size_t operator()(const Point& point) const {
        return hash<int>{}(point.first) ^ hash<int>{}(point.second);
    }
};
}  // namespace std

int longestSequence2(const Matrix2& matrix, int y, int x, char prev, std::unordered_map<Point, int>& map) {
    constexpr const size_t kMoves = 8;
    constexpr const std::array<int, kMoves> x_moves{-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr const std::array<int, kMoves> y_moves{-1, 0, 1, 1, -1, -1, 0, 1};

    if (prev != '0' && (outOfRange(matrix, x, y) || prev + 1 != matrix[y][x])) {
        return 0;
    }
    if (auto it = map.find({x, y}); it != std::end(map)) {
        return it->second;
    }

    int max_length = 1;
    for (int i = 0; i < kMoves; ++i) {
        max_length = std::max(max_length,
                              longestSequence2(matrix, y + y_moves[i], x + x_moves[i], matrix[y][x], map) + 1);
        map[{x, y}] = max_length;
    }

    return max_length;
}

int longestSequence2(const Matrix2& matrix) {
    int max_length = 0;
    using length = int;
    std::unordered_map<Point, length> map;

    for (int y = 0; y < matrix.size(); ++y) {
        for (int x = 0; x < matrix.front().size(); ++x) {
            if (map.find({x, y}) == std::end(map)) {
                max_length = std::max(max_length, longestSequence2(matrix, y, x, '0', map));
            }
        }
    }

    return max_length;
}
```
<!-- .slide: style="font-size: 0.58em" -->