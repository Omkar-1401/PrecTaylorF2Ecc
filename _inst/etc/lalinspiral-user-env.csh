# source this file to access LALInspiral
if ( ! ${?PYTHONPATH} ) setenv PYTHONPATH
setenv PYTHONPATH `echo "$PYTHONPATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/python3.13/site-packages:||g;'`
setenv PYTHONPATH `echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/python3.13/site-packages:$PYTHONPATH" | /usr/bin/sed -e 's|:$||;'`
if ( ! ${?MANPATH} ) setenv MANPATH
setenv MANPATH `echo "$MANPATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/share/man:||g;'`
setenv MANPATH `echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/share/man:$MANPATH" | /usr/bin/sed -e 's|:$|:|;'`
if ( ! ${?PKG_CONFIG_PATH} ) setenv PKG_CONFIG_PATH
setenv PKG_CONFIG_PATH `echo "$PKG_CONFIG_PATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/pkgconfig:||g;'`
setenv PKG_CONFIG_PATH `echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/lib/pkgconfig:$PKG_CONFIG_PATH" | /usr/bin/sed -e 's|:$||;'`
setenv LALINSPIRAL_PREFIX "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst"
setenv LALINSPIRAL_DATADIR "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/share/lalinspiral"
if ( ! ${?PATH} ) setenv PATH
setenv PATH `echo "$PATH" | /usr/bin/sed -e 's|/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/bin:||g;'`
setenv PATH `echo "/home/omkar/miniconda3/envs/lalsuite-dev/src/lalsuite/_inst/bin:$PATH" | /usr/bin/sed -e 's|:$||;'`
