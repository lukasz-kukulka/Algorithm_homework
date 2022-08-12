## Group project

### Requirements: 

1. Gather a group (3-4 people)
2. Make sure you understand at least 50% of Matrix algorithms :)
3. Prepare to excited channlenge!

### Implement Young table

Young table has sorted row and column. You need to implement this interface:

```C++
class Young {
public:
    // std::ostream& os = std::cout will be helpfull to test class
    // because you can provide std::stringstream in test and read
    // what class wanted to write
    Young(int size_x, int size_y, std::ostream& os = std::cout);

    // This method should print table (as a matrix) eg:
    // x x x x
    // x x x x
    // x x x x
    void print() const;

    // Return whether matrix is empty, should be O(1)
    bool empty() const;
    // Return whether matrix is full, should be O(1)
    bool full() const;
    // Clear matrix
    void clear();

    // Return first element (the lowest one) should be O(1)
    int& front();
    // Same as above
    const int& front() const;

    // Return last element (the highest one) should be O(n)
    int& back();
    // Same as above
    const int& back() const;

    // Should insert value, should be O(n)
    bool insert(int value);
    // Should insert few values, should be O(n * m), where m is values.size()
    bool insert(const std::initializer_list<int>& values);

    // Should search value and return position (x, y), should be O(n)
    std::pair<int, int> search(int value) const;
    // Should remove first element and return it, should be O(n)
    int popFront();
    // Should remove last element and return it, should be O(n)
    int popBack();
    // Should remove value (if exist, in othere cases return false), should be O(n)
    bool remove(int value);
    // Should remove few values, should be O(n * m), where m is values.size()
    bool remove(const std::initializer_list<int>& values);
    // Should modify value (if exist) with a new value, should be O(n)
    bool modify(int old_val, int new_val);
```

You class should need only 2 memebrs

```C++
std::vector<std::vector<int>> vec_;
std::ostream& os_;
```

You should not use any other variables (take care of memory complexcity).

If you have some trouble, you can read `Young table` paragraph in module7 (BasicAlgorithm), but try do this by your own!

Good luck!

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