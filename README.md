# myproj
Example DUNE analysis project  

Build and test the project as follows. First, choose an installation
bse directory and, from there, check out the code:
<pre>
  git clone https://github.com/dladams/myproj.git
</pre>
The code will be in the myproj subdirectory, here denoted
&lt;path-to-code>.  

Create a base installation directory and define DUNE\_INSTALL\_DIR to
point at that directory, e.g.
<pre>
export DUNE_INSTALL_DIRECTORY=$HOME/dune/install
</pre>
The compiled project will be installed at $DUNE\_INSTALL\_DIR/myproj.

Create a base build area and defined DUNE\_BUILD\_DIR to point there, e.g.
<pre>
export DUNE_BUILD_DIRECTORY=$HOME/tmp/dune/build
</pre>
The code will be built (compiled, linked, etc.) at $DUNE\_BUILD\_DIR/myproj.
This temporary area may be deleted after the code is installed.

To build the code, from any directory,
<pre>
<path-to-code>/build
</pre>

