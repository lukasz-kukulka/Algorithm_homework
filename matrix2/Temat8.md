#### Obliczanie w ilu ruchach wszystkie niebieskie kolory zostaną zastąpione zielonymi

Na wejściu otrzymujemy mapę składającą się z trzech kolorów: czarny (neutralny), niebieski (wrogi) i zielony (przyjazny). 

<img width="700" src="../img/BasicModule7/rys3.png" alt="Coders School" class="plain">


W każdym ruchu, zielone pole może zamienić sąsiednie wrogie pola na przyjazne (z prawej, lewej, dolnej i górnej strony). Naszym zdaniem jest obliczenie w ilu ruchach, wszystkie wrogie pola zostaną zamienione na przyjazne. Podczas implementacji wrogie pole oznaczać będziemy, jako <h>-1</h> neutralne, jako <h>0</h>, a przyjazne, jako <h>1</h>. 


Całe zadanie opiera się na przejściu <h>BFS</h>. Na początku wyznaczamy wszystkie liczby <h>1</h> i dodajemy je do kolejki, następnie tworzymy tymczasową kolejkę dla tych liczb i dokonujemy transformacji sąsiednich wartości, jeżeli są ujemne. Każdorazowo po dokonaniu takiej zmiany, dodajemy nowe punkty na kolejkę <h>positive</h>. Następnie znów podmieniamy ją z tymczasową <h>tmp</h> i inkrementujemy licznik ruchów.

Algorytm kończy się, gdy nie dokonamy już żadnej konwersji. Złożoność obliczeniowa to <h>O(n*m)</h>.


```C++
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
```
<!-- .slide: style="font-size: 0.55em" -->

<img width="420" src="../img/BasicModule7/rys3.png" alt="Coders School" class="plain">
