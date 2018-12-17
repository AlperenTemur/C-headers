#include <stdio.h>
#include <conio.h>

#ifndef _DIE
 #ifndef __ASSERT_H_
  #include <stdlib.h>//exit()
  #define _DIE(x) fprintf(stderr,x,__FILE__,__LINE__);exit(-1);
 #else
  #ifndef _UASSERT
   #include <stdlib.h>
   #define _DIE(x) fprintf(stderr,x,__FILE__,__LINE__);exit(-1);
  #else
   #define _DIE(x) assert(0&&x);
  #endif
 #endif
#endif
#ifdef __GNUC__
#define _T(x) if(__builtin_expect(!(x),0))_DIE("ERROR!");
#define _T(x,y) if(__builtin_expect(!(x),0))_DIE(y);
#else
#define _T(x) if((x))_DIE("ERROR!");
#define _T(x,y) if(!(x))_DIE(y);
#endif
#ifdef DEBUG
#define _P(x) printf(x)
#define _D(x) fprintf(stderr,x)
#else
#define _P(x) ((void)0)
#define _D(x) ((void)0)
#endif
