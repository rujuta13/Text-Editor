#include "texteditor.h"

int main(int argc, char *argv[]) {
  enableRawMode();
  initEditor();
  if (argc >= 2) {
    editorOpen(argv[1]);
  }

  editorSetStatusMessage("HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-A = autocomplete");

  while (1) {
    editorRefreshScreen();
    editorProcessKeypress();
  }

  return 0;
}

