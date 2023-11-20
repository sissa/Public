### Basics

#### Normal mode (default)

 - navigation: arrows (same as hjkl), `0` (start of line), `^` (non-blanc start of line), `$` (end of line), `b, e, B, E` (beginning and end of words, capitals are for "words" with dots)
 - editing: `x` (delete a chracter), `u` (undo), `p` to paste (put), `dd` (delete/cut a line), `yy` (yank/copy a line)

#### Visual mode
 - press `v` to enter
 - move cursor to select
 - `x` (or `d`) to cut, `y` to copy

### Insert mode
 - enter with `i` (at cursor), `a` (append, after cursor), `A` (append at the end of line)
 - edit like any text
 - escape to go back to normal mode


### Useful changes to .vimrc

 - `set number` (to always show line number)
 - `set mouse =a` (to go into visual/selecting mode easier)
 - `set whichwrap+=<,>,h,l` (to navigate between lines continuosly)

### Exercise
 Run vimtutor and complete it

### Summary

**These are the things you absolutely have to remember**:
 
 - switching in and out of insert mode

 - `:wq`, `:q!`

The rest is just for making life easier.


