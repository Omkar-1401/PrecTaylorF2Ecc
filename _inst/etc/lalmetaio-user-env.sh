# source this file to access LALMetaIO
export PYTHONPATH
PYTHONPATH=`echo "$PYTHONPATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/python3.13/site-packages:||g;'`
PYTHONPATH=`echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/python3.13/site-packages:$PYTHONPATH" | /usr/bin/sed -e 's|:$||;'`
export MANPATH
MANPATH=`echo "$MANPATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/share/man:||g;'`
MANPATH=`echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/share/man:$MANPATH" | /usr/bin/sed -e 's|:$|:|;'`
export LALMETAIO_PREFIX
LALMETAIO_PREFIX="/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst"
export PKG_CONFIG_PATH
PKG_CONFIG_PATH=`echo "$PKG_CONFIG_PATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/pkgconfig:||g;'`
PKG_CONFIG_PATH=`echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/pkgconfig:$PKG_CONFIG_PATH" | /usr/bin/sed -e 's|:$||;'`
export PATH
PATH=`echo "$PATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/bin:||g;'`
PATH=`echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/bin:$PATH" | /usr/bin/sed -e 's|:$||;'`
export LALMETAIO_DATADIR
LALMETAIO_DATADIR="/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/share/lalmetaio"
