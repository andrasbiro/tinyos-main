AUTOMAKE_OPTIONS = foreign

tinyoslibdir=$(libdir)/tinyos

bin_SCRIPTS = motelist2

tinyoslib_DATA = motelist2-getdevices.py

if CYGWIN
  GETDEVICES_SOURCE = motelist2-getdevices-cygwin.py
else
  GETDEVICES_SOURCE = motelist2-getdevices-linux.py
endif

motelist2-getdevices.py: $(GETDEVICES_SOURCE)
	cp $(GETDEVICES_SOURCE) $@
	
motelist2: motelist2.in
	sed -e 's,@tinyoslibdir\@,$(tinyoslibdir),g' $< | sed -e 's,@pathpython\@,$(pathpython),g' >$@
