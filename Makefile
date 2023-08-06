reproduce: dragtest clipboard/test
	kwin_wayland ./run.sh

without_clipboard: dragtest
	NO_CLIP=1 kwin_wayland ./run.sh

dragtest: dragtest.c
	gcc dragtest.c $(shell pkg-config --cflags --libs gtk+-3.0) -g -o dragtest

clipboard/test: clipboard/main.cpp
	cd clipboard && qmake test.pro && make
