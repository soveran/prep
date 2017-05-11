PREFIX?=/usr/local
MANPREFIX?=${PREFIX}/share/man
STRIP?=strip

default: prep

prep: prep.c
	$(CC) -Wall -Os -o prep prep.c

clean:
	@echo cleaning
	@rm -f prep

install: prep
	@echo stripping executable
	@${STRIP} prep
	@echo installing executable to ${PREFIX}/bin
	@mkdir -p ${PREFIX}/bin
	@cp -f prep ${PREFIX}/bin/prep
	@chmod 755 ${PREFIX}/bin/prep

	@echo installing manual pages to ${MANPREFIX}/man1
	@mkdir -p ${MANPREFIX}/man1
	@cp -f prep.1 ${MANPREFIX}/man1/prep.1
	@chmod 644 ${MANPREFIX}/man1/prep.1

uninstall:
	@echo removing executable from ${PREFIX}/bin
	@rm ${PREFIX}/bin/prep
	@echo removing manual pages from ${MANPREFIX}/man1
	@rm ${MANPREFIX}/man1/prep.1

test:
	@sh test/tests.sh

.PHONY: clean install uninstall test
