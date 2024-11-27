EFetch
===========
.. image:: https://img.shields.io/badge/Build%20(fedora)-passing-2a7fd5?logo=fedora&logoColor=2a7fd5
   :alt: Build = Passing
   :target: https://github.com/ElisStaaf/efetch
.. image:: https://img.shields.io/badge/Version-1.0.0-38c747
   :alt: Version = 1.0.0
   :target: https://github.com/ElisStaaf/efetch
.. image:: https://img.shields.io/badge/Language-C++-grey?logo=c%2B%2B&logoColor=white&labelColor=blue
   :alt: Language = C++
   :target: https://github.com/ElisStaaf/efetch

Oh no! Neofetch, the favourite CLI tool for displaying system information is gone!
I (and many others) loved that tool! So I (like many others) made my own. That's
how "EFetch" was born.

Requirements
------------
* `gcc`_ (or any other C++ compiler)
* `make`_
* `cmake`_
* `git`_ or `gh`_

Installation
------------
To install, firstly clone the repo:

.. code:: sh 

   # git
   git clone https://github.com/ElisStaaf/efetch

   # gh
   gh repo clone ElisStaaf/efetch

Then you would want to build an executable using ``cmake``:

.. code:: sh

   cmake .
   sudo make

.. _`gcc`: https://gcc.gnu.org/install
.. _`make`: https://www.gnu.org/software/make
.. _`cmake`: https://cmake.org/download
.. _`git`: https://git-scm.com/downloads 
.. _`gh`: https://github.com/cli/cli#installation
