## Homework

1. Chapter 8: Find a number of steps needed to change negative color (-1) to positive color (+1). Every time positive color can change (top, left, bottom, and right) neighbor color from (-1) to (1), but can't modify neutral fields (0). Your goal is to count the number of turns that are needed to repaint the whole matrix (form -1) to (1).

Obliczanie w ilu ruchach wszystkie niebieskie kolory zostaną zastąpione zielonymi

Na wejściu otrzymujemy mapę składającą się z trzech kolorów: czarny (neutralny), niebieski (wrogi) i zielony (przyjazny).

Img

W każdym ruchu, zielone pole może zamienić sąsiednie wrogie pola na przyjazne (z prawej, lewej, dolnej i górnej strony). Naszym zdaniem jest obliczenie w ilu ruchach, wszystkie wrogie pola zostaną zamienione na przyjazne. Podczas implementacji wrogie pole oznaczać będziemy, jako -1 neutralne, jako 0, a przyjazne, jako 1.

Całe zadanie opiera się na przejściu BFS. Na początku wyznaczamy wszystkie liczby 1 i dodajemy je do kolejki, następnie tworzymy tymczasową kolejkę dla tych liczb i dokonujemy transformacji sąsiednich wartości, jeżeli są ujemne. Każdorazowo po dokonaniu takiej zmiany, dodajemy nowe punkty na kolejkę positive. Następnie znów podmieniamy ją z tymczasową tmp i inkrementujemy licznik ruchów.

Algorytm kończy się, gdy nie dokonamy już żadnej konwersji. Złożoność obliczeniowa to O(n*m).

bool outOfRange(const Matrix& matrix, int x, int y) {
    return x < 0 || y < 0 || x >= matrix.front().size() || y >= matrix.size();
}

int countMoves(Matrix matrix) {
    constexpr const size_t kMoves = 4;
    constexpr const std::array<int, kMoves> x_moves{-1, 0, 0, 1};
    constexpr const std::array<int, kMoves> y_moves{0, -1, 1, 0};
    std::queue<std::pair<int, int>> positive;
    for (int y = 0; y < matrix.size(); ++y) {
        for (int x = 0; x < matrix.front().size(); ++x) {
            if (matrix[y][x] > 0) {
                positive.push({y, x});
            }
        }
    }
    int moves = 0;
    while (!positive.empty()) {
        // To avoid mixing positive value with converted nagtive value
        std::queue<std::pair<int, int>> tmp;
        std::swap(tmp, positive);
        ++moves;
        // here we convert all neighbors of positive values
        while (!tmp.empty()) {
            const auto [y, x] = tmp.front();
            tmp.pop();
            for (int i = 0; i < kMoves; ++i) {
                const int new_x = x + x_moves[i];
                const int new_y = y + y_moves[i];
                if (outOfRange(matrix, new_x, new_y) || matrix[new_y][new_x] != -1) {
                    continue;
                }
                matrix[new_y][new_x] = 1;
                positive.push({new_y, new_x});
            }
        }
    }
    // check if any negative value can't be reach by positive one
    for (const auto& row : matrix) {
        for (auto value : row) {
            if (value == -1) {
                return std::numeric_limits<int>::min();
            }
        }
    }

    return moves - 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


2. Chapter 10: Find the longest sequence of increasing characters in the matrix. You can search in every direction (even diagonally)

Input: 

```C++
{'D', 'E', 'H', 'X', 'B'},
{'A', 'O', 'G', 'P', 'E'},
{'D', 'D', 'C', 'F', 'D'},
{'E', 'B', 'E', 'A', 'S'},
{'C', 'D', 'Y', 'E', 'N'}};
```

Output: 7 (this will be `BCDEFGH`)




Znajdywanie najdłuższej sekwencji kolejnych liter w macierzy

Omawialiśmy już podobne zadanie, tym razem jednak naszym celem jest odnalezienie najdłużej sekwencji kolejnych liter. Nie musimy koniecznie startować od litery A, przykładowo poszukiwany ciąg może wyglądać następująco I J K L M N. Domyślamy się zapewne, że trzeba będzie sprawdzić każde pole w macierzy i dokonać przejścia DFS w celu znalezienia najdłuższej kombinacji dla danego pola.

Oczywiście marnujemy tutaj cenną informację. Przykładowo, jeżeli zbadaliśmy ciąg I J K L M N, to, jeżeli teraz zaczniemy od litery J, to znajdziemy J K L M N, czyli na pewno nie poprawimy wyniku, więc nie ma sensu już dokonywać przeszukiwania. Niestety, aby poradzić sobie z takim problemem musielibyśmy skorzystać z programowania dynamicznego, które przechowywałoby częściowe wyniki. Wykracza to jednak po za zakres podstaw z algorytmów, dlatego też wykonamy ten algorytm przechodząc przez każda literę w macierzy.

Złożoność, obliczeniowa będzie na poziomie O(MN^2). Gdyż dokonujemy (MN) przejść przez macierz, z czego każde przejście średnio zajmie nam O(MN) czasu. Cały algorytm sprowadza się do przejścia DFS, w którym to sprawdzamy kolejno wszystkie 8 możliwych ruchów, jeżeli odnajdziemy następną z sekwencji literę prev + 1 == matrix[y][x], to kontynuujemy poszukiwania, w innym razie zwracamy 0.

Oczywiście aby uwzględnić finałową długość, musimy dodawać do każdego wyniku +1

longestSequence(matrix,
                y + y_moves[i], 
                x + x_moves[i],
                matrix[y][x]) + 1;

W ten sposób, jeżeli udało nam się w pierwszym kroku znaleźć kolejna liczbę nasz max_length ma już wartość 2. Wtedy też w następnym ruchu osiągniemy 3, potem 4 itd.

Gdy zakończymy już rekurencyjne sprawdzanie w każdym z 8 kierunków zwracamy największą ze znalezionych wartości max_length.

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

Programowanie dynamiczne

Podmienienie tego algorytmu, tak, aby wykorzystywał już raz obliczone wartości (korzystając z programowania dynamicznego), nie jest trudne w tym przypadku. Potraktujcie ten kod, jako przystawkę, do zaawansowanych algorytmów.

Nie musicie się przejmować, jeżeli nie zrozumiecie algorytmu, gdyż w odpowiednim momencie omówimy wystarczająco dużo przykładów, aby programowanie dynamiczne stało się bardziej intuicyjne.

Tymczasowe wyniki przechowywać będziemy w mapie. Kluczem mapy będzie Point, czyli x, y. Dlatego musimy utworzyć własną funkcję mieszającą w przestrzeni nazw std.

Dysponując już taką mapą dokonujemy trzech modyfikacji algorytmu:

    W głównej funkcji: Jeżeli dany punkt znajduje się już w mapie, to nie dokonujemy jego sprawdzania, gdyż znamy już dla niego wynik,

    W pomocniczej funkcji: Jeżeli dany punkt był już sprawdzany, kończymy rekurencje i zwracamy aktualny wynik przechowywany w mapie,

    W pomocniczej funkcji: Jeżeli zakończyliśmy wywołania rekurencyjne dla danego kroku w pętli, zapisujemy otrzymany wynik w mapie, a by w przyszłości móc wykorzystać go jeszcze raz.

Rośnie nam w ten sposób złożoność pamięciowa, jednak znacząco przyspieszamy samo wykonanie algorytmu, gdyż tak naprawdę przechodzimy przez dany element w macierzy tylko raz. Za każdym kolejnym razem zwracamy otrzymaną długość dla danego punktu, zatem złożoność maleje w znaczącym stopniu z O(nm^2) do O(nm)!

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

## How to create PR?

1. Create fork of algorithm repository (`https://github.com/nauka-programowania-MA/Algorithms_part1`) On the left top there is a button named `fork`.
2. If you have a fork please update it before creating a pull request
    a) `git remote add upstream https://github.com/YOUR_NAME/Algorithms_part1.git`
    b) `git fetch upstream`
    c) `git checkout master`
    d) `git rebase upstream/master`
    e) `git push origin master`
3. If you have few commit's you can always squash it to one (if you prefer)
    a) `git rebase -i origin/master`
    b) then choose which commit you want to squash by replacing `pick` to `squash` or shorter `s`
4. Push your changes
    a) `git push origin YOUR_BRANCH_NAME`
5. Create PR:
    a) Open original algorithm repo `https://github.com/nauka-programowania-MA/Algorithms_part1`
    b) Click `Pull requests` and then on the left click `New pull request`
    c) Click `compare across fork`
    d) As a base choose `master`
    e) As your head repository choose your fork
    f) As a compare choose your branch name
    g) Then just click `Create pull request` (you can check diff before create PR, maybe you find some bugs and fix them before publish changes)