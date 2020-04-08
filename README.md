# myproj
Example DUNE analysis project  

### Introduction

The goal is to have a code development framework that is easy to use
for developers, installers and users.
Code is separated into small projects which can include
utilities (ordinary C++ classes and functions), scripts and executables
(C++ main programs), art tools and tool interfaces, art services, and
Root dictionaries for the utiltities and tools.

It is also possible (and encouraged) to create tests for each of these
components and to create a script that runs all the tests.
The tests and this script are installed in the test subdirectory of
the project installation area.

### Setup

DUNE analysis projects are assumed to depend on dunetpc and so users must first set up that project.
Their build makes use of art studio and cmake which must also be set up. At FNAL, the
following commands can be used:
<pre>
source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setup dunetpc v08_48_01 -q e19:prof
setup cmake v3_14_3
setup studio v1_02_00
<pre>
The versions here were the moset recent in early April 2020.
Users will typically want to use the most current version of dunetpc and should be able to use later versions of cmake and studio.
Let David Adams know if you have any problems.

### Installation

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
</pre>
to run cmake and generate the build area,
<pre>
&lt;path-to-code>/build make
</pre>
to build the project, and
<pre>
&lt;path-to-code>/build install
</pre>
to install it.

### Using the project

To set up to use the package, source the setup script in the installation
directory:
<pre>
source $DUNE_INSTALL_DIRECTORY/myproj/install.sh
</pre>
The project executables, scripts, libraries (including Root dictionaries) and fcl files
are now included in the usual system paths.
The variable MYPROJ\_DIR points to the package installation directory.
E.g. to run the demo executable:
<pre>
myhello
</pre>

Start a Root session and use the MyXform class:
<pre>
root.exe
[root [0] MyXform xf(8);
MyXform::ctor: Scale is 8
root [1] xf.transform(128)
(float) 1024.00f
</pre>

### Testing

The project includes a variety of component tests. All of thes may be run with the
command
<pre>
$MYPROJ_DIR/test/test
</pre>
The test are run in the current directory and may write some files, and so it
is best to run this in a clean directory.
