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
export DUNE_INSTALL_DIRECTORY=$HOME/dune/install/$DUNETPC_VERSION
</pre>
The compiled project will be installed at $DUNE\_INSTALL\_DIR/myproj
if DUNE_INSTALL_BYPKG is undefined or has any value other than "false".
In the latter case, it is installed directly in $DUNE\_INSTALL\_DIR
allowing multiple packages to share the installation directory.
Note the dunetpc version is included here.

Create a base build area and defined DUNE\_BUILD\_DIR to point there, e.g.
<pre>
export DUNE_BUILD_DIRECTORY=$HOME/tmp/dune/build/$DUNETPC_VERSION
</pre>
The code will be built (compiled, linked, etc.) at $DUNE\_BUILD\_DIR/myproj.
This temporary area may be deleted after the code is installed.

To build and install the code, from any directory,
<pre>
&lt;path-to-code>/build
</pre>

or equivalently issue the following three commands:
<pre>
&lt;path-to-code>/build cmake
<pre>
to run cmake and generate the build area,
<pre>
&lt;path-to-code>/build make
<pre>
to build the project, and
<pre>
&lt;path-to-code>/build install
<pre>
to install it.

To set up, to use the package, source the setup script in the installation
directory:
<pre>
source $DUNE_INSTALL_DIRECTORY/myproj/install.sh
<pre>
The project executables, scripts, libraries (including Root dicionaries) and fcl files
are now included in the usual system paths.
The variable MYPROJ\_DIR points to the package installation directory.
E.g. to run the demo executable:
<pre>
myhello
<pre>

The project includes a variety of component tests. All of thes may be run with the
command
<pre>
$MYPROJ_DIR/test/test
<pre>
The test are run in the current directory and may write some files, and so it
is best to run this in a clean directory.
