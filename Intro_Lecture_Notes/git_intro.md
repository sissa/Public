 
[reference material](https://git-scm.com/book/en/v2)


### What is git?

Git is a free and open source distributed version control system designed to handle everything from small to very large projects with speed and efficiency.

### What is github?

GitHub is an Internet hosting service for software development and version control using Git.

### Let's start!

make sure that you have `git` installed.

initialize it (or it will complain the first time you do anything):

`git config --global user.name "Whatever Name"`
`git config --global user.email whatever@whatever`

### Passwordless access

Let's follow [instructions on github](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/checking-for-existing-ssh-keys).


### Let's fork and clone the course repository

go to https://github.com/sissa/Public and press "fork"

clone the main, sissa repo:

`git clone ADDRESS_FROM_GITHUB`   (choose ssh)

go into the folder

`git remote -v` to see the current remote

`git remote add THINK_OF_A_SHORT_NAME ADDRESS_FROM_GITHUB_OF_YOUR_FORK`

for example,

`git remote add mine ADDRESS_FROM_GITHUB_OF_YOUR_FORK`


`git pull origin main` <--- this is what you should do to update the repo


create any text file in the folder "exercises".

`git status`

`git add YOUR_FILE`

`git commit -m "USEFUL MESSAGE"`


`git push SHORT_NAME_YOU_CHOSE_FOR_YOUR_FORK_REMOTE main`


### Gitignore

[A collection of templates](https://github.com/github/gitignore)

If you are sure that your `.gitignore` is good, you can just do 

```
git add -A
```


### Make your own repository 

Just go to github and follow visual instructions (choose "with README"), then 

`git clone YOUR_REPOSITORY`

add some text file to it

`git push origin main` (bad practice actually - only for "trash repositories" and learning purposes like now)




instead of adding files manually. Sooner of later you will push some trash like this, so only do it on your own repositories or if there are way too many files to add.


### Now let's make a nice bash prompt

https://github.com/magicmonty/bash-git-prompt

