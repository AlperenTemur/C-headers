#ifdef __unix__

#include <stdio.h>
#include <termios>
#include <unistd.h>
int getch ( void )
{
  int ch;
  struct termios oldt, newt;

  tcgetattr ( STDIN_FILENO, &oldt );
  newt = oldt;
  newt.c_lflag &= ~( ICANON | ECHO );
  tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
  ch = getchar();
  tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );

  return ch;
}

#elif defined(_WIN32) || defined(WIN32)

#include <conio.h>

#endif
