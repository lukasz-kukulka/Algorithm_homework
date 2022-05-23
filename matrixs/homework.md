## Homework

1. Reuse implementation for `printSpiral` and allow to print matrix with some shift eg:

```C++
5 6 7
3 4 8
2 1 9
```

2. Solve topic 4: `Reset chosen rows and columns in matrix` eg:

Input:

```C++
1 1 1 1 0
1 0 1 1 1
1 1 1 1 1
1 1 1 1 1
0 1 1 1 1
```

Output:

```C++
0 0 0 0 0
0 0 0 0 0
0 0 1 1 0
0 0 1 1 0
0 0 0 0 0
```

3. Solve topic 9: `Find all occurence of given number in sorted matrix` eg:

Input: 

```c++
{-5, -2, -1, 3,  4}, 
{-3, -2, -1, 4,  6},
{-2, -1,  0, 5,  8}, 
{-1,  3,  6, 10, 12}, 
{ 5,  8, 10, 13, 15}
```

Output for number 3 : `2`
Output for number 4 : `2`
Output for number -1: `4`


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