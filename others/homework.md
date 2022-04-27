## Homework

1. Chapter 9: Sort element by order presented in second table. In both tables there could be any values. You need to focus only on valid values and make sort operation.If there is no value in `order` table you need to sort it at the end of `toSort` vector.
- Example input: `toSort {1,2,3,4,5,6}` `order {4,2,7,8,1}`
- Example output: `{4,2,1,3,5,6}`

2. Chapter 13: Find frequency of each value in sorted vector
- Example input: `1,1,1,1,2,2,2,3,3,4,5,5,5`
- Example output: `{{1,4},{2,3},{3,2},{4,1},{5,3}}`

3. Chapter 15: Find element matching predicate. You need to find a value for which all values on left are lower and on the right are higher.
- Example input: `2,3,1,8,7,10,14,12`
- Example output: <h>10</h> -> values `2,3,1,8,7` are lower and `14,12` are higher 


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