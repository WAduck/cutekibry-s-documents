PY=python3
BASEDIR=$(CURDIR)

help:
	@echo 'Makefile for a Web site                                                   '
	@echo '                                                                          '
	@echo 'Usage:                                                                    '
	@echo '   make html                           generate the web site              '
	@echo '   make clean                          remove the generated files         '
	@echo '   make serve                          serve site at http://localhost:8000'

test:
	echo $(BASEDIR)

html:
	cd cinccino && $(PY) make.py $(BASEDIR)/content $(BASEDIR)/output

clean:
	[ ! -d $(OUTPUTDIR) ] || rm -rf $(OUTPUTDIR)

serve:
	cd output && python3 -m http.server
