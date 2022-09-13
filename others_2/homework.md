## Homework

1. Chapter 3: Reverse triplet in array. For instance you got data: `1 2 3 4 5 6 7 8 9`, after reverse all triplet you got: `3 2 1 6 5 4 9 8 7`, so every triplet is beeing reversed. You also need to handle a range which will be reversed <h>begin</h> and <h>end</h>. 
- Example input: vec: `1 2 3 4 5 6 7 8 9`, begin: `4` end: <h>7</h>.
- Example output: `1 2 3 4 7 6 5 8 9` (we reverse only 3 numbers, because in range 4-7 there is one full triplet).
                           b     e

- Example input2: vec: `1 2 3 4 5 6 7 8 9`, begin: <h>2</h> end: <h>8</h>.
- Example output2: `1 2 5 4 3 8 7 6 9` (we reverse 6 numbers, because in range 2-9 there are two full triplets).
                        b           e

2. Chapter 6: Find longest subsequence, which contain following numbers from range. A range is a sequence of numbers `0 1 2 3...` The numbers don't need to be in sorted order, it could be `3 4 5 0 1 2`. Range don't need to start form <h>0</h>, it could be `5 6 7 8 9`.
- Example input: `5, 0, 4, 7, 1, 2, 8, 5, 3, 4`
- Example output: `0, 1, 2, 3, 4, 5` (in any order)

- Example input2: `0 1 2 3 4 6 7 8 9 10 11`
- Example output: `6 7 8 9 10 11` (in any order)


3. Chapter 10: Sort a table with given order with memoory complexity <h>O(1)</h>. First table contain numbers and second contain indexes. You need to sort first table by reoredering all elements from first table to index presented on second table. For instance tab1 `1 2 3` order `2 0 1`, so first element <h>1</h> need to be on <h>2</h> index, <h>2</h> element need to be on <h>0</h> index and <h>3</h> element need to be on <h>1</h> index. Result: `2 3 1`.

- Example input: vec: `{1,2,3,4,5,6}` | order `{2,4,3,5,1,0}`
- Example output:  `6 5 1 3 2 4`


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