## Gnuplot

[documentation](http://www.gnuplot.info/)

_For people still using WSL it will be easier to just install the Windows version of gnuplot for now_

From the homepage:

"Gnuplot is a portable command-line driven graphing utility for Linux, OS/2, MS Windows, OSX, VMS, and many other platforms. The source code is copyrighted but freely distributed (i.e., you don't have to pay for it). It was originally created to allow scientists and students to visualize mathematical functions and data interactively, but has grown to support many non-interactive uses such as web scripting. It is also used as a plotting engine by third-party applications like Octave. Gnuplot has been supported and under active development since 1986."

Gnuplot produces easily customazable pictures from data files or just pure math functions. The amount of options is overwhelming at first, but once you have a few templates with your favourite styles, plotting new things becomes a breeze. 3D plots are also available.


### Let's start with interactive

just type `gnuplot`

Now you should see the output similar to

```
21:23 $ gnuplot

        G N U P L O T
        Version 5.2 patchlevel 2    last modified 2017-11-15 

        Copyright (C) 1986-1993, 1998, 2004, 2007-2017
        Thomas Williams, Colin Kelley and many others

        gnuplot home:     http://www.gnuplot.info
        faq, bugs, etc:   type "help FAQ"
        immediate help:   type "help"  (plot window: hit 'h')

Terminal type is now 'qt'
gnuplot>
```

now type `plot sin(x)`

If you are lucky, you should see a window with the grapth. Otherwise, your gnuplot didn't get right which terminals can be used on your system. The terminal type is printed in the login message, or you can view it by typing `show terminal`. To view all the terminals available on your system, you can do

```
gnuplot> print GPVAL_TERMINALS
```

or

```
set terminal
```

The latter one gives more information. Technically, you do not need a pop-up window, since you would need to save the image anyway, so you can set the terminal to, for example, `pdfcairo` or `png` and view the resulting pictures manually.

If you do not find any terminals that work for you, see what works for people on similar systems, then google how to download them.

To quit the interactive mode simply type `q` (or `quit`).

it makes sense to use the interactive mode if you just want to quicly see the plot of some function, otherwise you plobably want to set a lot of variables and doing so every time in the interactive mode becomes cumbersome. So, you create a script and then run

`gnuplot SCRIPT_NAME.gp`

A large collection of plots and scripts that generated them can be found [here](http://gnuplot.sourceforge.net/demo/) and [here](https://commons.wikimedia.org/w/index.php?title=Category:Images_with_Gnuplot_source_code). Start by looking for a plot similar to what you need, copy the scripts, then modify to your taste.


### Exercise 1:

Plot a family of 5 parabolas. The plot should display their equations, have x and y marks along the axes and the grid shown.

### Exercise 2:

Create a file with 1000 values each being a random number from 1 to 20. Plot a nice looking histogram. You can use [these](http://www.phyast.pitt.edu/~zov1/gnuplot/html/histogram.html) for inspiration.

### Exercise 3:

Make a 3d plot of some function (play around with sin() and exp() to get something interesting)

### Exercise 4:

Complete the script `gif.gp` in `data_dir`.











































