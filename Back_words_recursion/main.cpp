#include <iostream>

void printCharecters(char* character) {
    for (auto i = character; *i != '\0'; i++) {
        std::cout << *i;
    }
}

void wordRecursion(char* character) {
    auto begin = character;
    if (*character == '\0') {
        return;
    }
    if (*character == ' '){
        character++;
        
    } else {
        while(*character != ' ' && *character != '\0') {
            character++;
        } 
    }
    wordRecursion(character);
    for (auto i = begin; i < character; i++) {
        std::cout << *i;
    }
}

int main() {
    char test[] = "aaa  bbb cccccccc  nnn zzz  ww   qqq";
    std::cout << "BEFORE: ";
    printCharecters(&test[0]);
    std::cout << '\n';
    std::cout << " AFTER: ";
    wordRecursion(&test[0]);
    std::cout << '\n';
    return 0;
}