package = Tooltip
version = 1.0
tarname = $(package)
distdir = $(package)-$(version)

all clean check install Tooltip:
	cd src && $(MAKE) $@

dist: $(distdir).tar.gz

$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)

$(distdir): FORCE
	mkdir -p $(distdir)/src
	cp Makefile $(distdir)
	cp src/Makefile src/main.c $(distdir)/src

discheck: $(distdir).tar.gz
	gzip -cd $(distdir).tar.gz | tar xvf -
	cd $(distdir) && $(MAKE) all
	cd $(distdir) && $(MAKE) check
	cd $(distdir) && $(MAKE) clean
	rm -rf $(distdir)
	@echo "*** Package  $(distdir).tar.gz is ready for distribution. "

distclean: FORCE

FORCE:
	rm -f $(distdir).tar.gz
	rm -rf $(distdir)


.PHONY: FORCE clean check dist distcheck install
