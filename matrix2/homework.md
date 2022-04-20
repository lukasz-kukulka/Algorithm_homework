## Homework

1. Chapter 8: Find a number of steps needed to change negative color (-1) to positive color (+1). Every time positive color can change (top, left, bottom, and right) neighbor color from (-1) to (1), but can't modify neutral fields (0). Your goal is to count the number of turns that are needed to repaint the whole matrix (form -1) to (1).

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