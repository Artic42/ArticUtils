#TUI

TUI_R: lib/c-cpp/tui.lib
TUI_D: lib/c-cpp/tui_D.lib
TUI: TUI_R TUI_D
TUI_TEST: src/tui/tuiTest.app TUI_D



lib/c-cpp/tui.lib: src/tui/tui.* Artic42_R
	@${CC} ${OFLAGSR} ${IPATH} src/tui/tui.c -o lib/c-cpp/tui.lib

lib/c-cpp/tui_D.lib: src/tui/tui.* Artic42_D
	@${CC} ${OFLAGSD} ${IPATH} src/tui/tui.c -o lib/c-cpp/tui_D.lib

src/tui/tuiTest.app: src/tui/test.c TUI_D Artic42_D
	@${CC} ${CFLAGSD} ${IPATH}  src/tui/test.c lib/c-cpp/tui_D.lib lib/c-cpp/Artic42_D.lib ${NCURSES} -o src/tui/tuiTest.app
	@./src/tui/tuiTest.app
	@rm src/tui/tuiTest.app