## Environment modules

Modules are mostly used on clusters to manage the environment, but can also be used on laptop if you want to have different software versions with the same names.

### Important/Useful environment variables:

* **PATH**: where the system looks when you ask it to run a command
* **LD_LIBRARY_PATH**: where the system searches for runtime libraries
* **PKG_CONFIG_PATH**: where the system looks for the pkg-config files (`.pc`)
* **MANPATH**: where the system searches for the manual pages of commands

### How to install (on Linux)
- clone the repo https://github.com/cea-hpc/modules

- cd in it
- `./configure --prefix=/path/to/somewhere/modules` (Like, /home/USERNAME/modules)

Clarification: you create a new folder called `modules` (or something else if you want, but then you might later forget what it is). It has to be outside the folder you cloned, but otherwise in any place you prefer. 

- `make`
- `make install`
- source the files `bash` (specify the full path) in `PREFIX/init/`. If everything works later, add this to .bashrc

Try to run `module av`.
If it doesn't work, do

```
export MODULEPATH=/WHATEVERYOURPREFIXWAS/modulefiles:$MODULEPATH
```
### For Mac users: 

If it complaints about _tclConfig.sh_ script! Just do this:

- `brew install tcl-tk`

If it is still complaining about gcc! Install Xcode Command Line Tools:

- `xcode-select --install`

Simply if something is missing brew it! Anyway! Installing Xcode Command Line Tools will solve most of the errors/complaints!

### An example
A simple modulefile as example:

```
#%Module1.0

set name     petsc
set version  3.9.2

module-whatis "Portable, Extensible Toolkit for Scientific Computation. Is a suite of data structures and routines for the scalable (parallel) solution of scientific applications modeled by partial differential equations."

proc ModulesHelp {} {
  puts stderr "A very useful library.\n"
}

set prefix   /opt/lib/$name-$version

setenv         PETSC_HOME         $prefix
setenv         PETSC_DIR          $prefix
setenv         PETSC_ARCH         linux-double-real-mkl

prepend-path   PATH               $prefix
prepend-path   LD_LIBRARY_PATH    $prefix/lib
prepend-path   PKG_CONFIG_PATH    $prefix/lib/pkgconfig
```

### Useful commands (that you've already seen yesterday)

If the installation worked, you can try everything on your machine, otherwise, do it on cluster later.

 - `module av` (from "available") - shows all the modules you can use 
 - `module av 2>&1 | grep "NAME"` - shows all the modules with "NAME" in their name
 - `module list` - list all the currently loaded modules
 - `module load MODULE_NAME` - loads the module
 - `module purge`  - unload all loaded modules
 - `module spider MODULE_NAME` - finds a module and it's possible dependencies. This command is often unavailable. 


You will need to use mpi soon anyway, so let's install that inside a module.

### Open MPI

1. Go to the [homepage of OpenMPI](https://www.open-mpi.org/)

2. Go to Download (left side panel)

3. Save the the tar file `openmpi-4.1.5.tar.gz`

4. Untar the file `tar -xf openmpi-4.1.5.tar.gz`

5. Go into the folder `cd openmpi-4.1.5`

6. Configuration: `./configure --prefix=/WHREVERYOUKEEPYOURLIBRARIES/openmpi/4.1.5 --enable-mpi-fortran=yes --enable-mpi-cxx` 

7. Make `make -j 4`

8. Install `make install`

9. Check the folder `/WHREVERYOUKEEPYOURLIBRARIES/openmpi/4.1.5`. See how things are arranged in there (you can use `tree .`)

10. Write a modulefile for the installed Open MPI. Put it into /WHATEVERYOURPREFIXWAS/modulefiles. Remember to set:
   - **PATH**
   - **LD_LIBRARY_PATH**
   - **MANPATH**

11. Check that `which mpirun` works

12. For those who want to check that not only modules, but mpi itself works:

in "stray_files" folder there is a file "hello_mpi.c". After the module is loaded, run the following commands in that folder:

```
mpicc -o hello_mpi.x hello_mpi.c
mpirun -np 2 hello_mpi.x

```
#### For Mac users again!

You may enconter this error when runnig make! 

```
ld: library not found for -levent_core
collect2: error: ld returned 1 exit status
make[2]: *** [libmpi_usempif08.la] Error 1
make[1]: *** [install-recursive] Error 1
make: *** [install-recursive] Error 1

```
Do this! By simply forcing configure to select the bundled versions of hwloc and libevent!

- `./configure --with-hwloc=internal --with-libevent=internal --prefix=/path/to/somewhere/modules` (Like, /home/USERNAME/modules)


