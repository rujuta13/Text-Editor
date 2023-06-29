#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define TE_VERSION "0.0.1"
#define TE_TAB_STOP 8
#define TE_QUIT_TIMES 3
#define CTRL_KEY(k) ((k) & 0x1f)

typedef struct erow {
  int size;
  int rsize;
  char *chars;
  char *render;
} erow;

struct editorConfig {
  int cx, cy;
  int rx;
  int rowoff;
  int coloff;
  int screenrows;
  int screencols;
  int numrows;
  erow *row;
  int dirty;
  char *filename;
  char statusmsg[80];
  time_t statusmsg_time;
  struct termios orig_termios;
};

void enableRawMode();
void initEditor();
void editorOpen(char *filename);
void editorSetStatusMessage(const char *fmt, ...);
void editorRefreshScreen();
void editorProcessKeypress();
