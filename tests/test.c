#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Base.h"
#include "Lifo.h"
#include "Callback.h"
#include "ParsingBase.h"
#include "Primitives.h"
#include "stream.h"
#include "Context.h"
#include "Capture.h"


/*
**
** Example for a very simple list parsing and the use of a hook.
*/

bool    check_print(s_ctx* ctx)
{
  (void)ctx;
  printf("The rule was correclty executed\n");
  return (true);
}

bool    list(s_ctx* parent_ctx)
{
/*
** list ::= #identifier [',' #identifier]*
** ;
*/

  s_ctx local_ctx = LOCAL_CTX(parent_ctx);

  if (expression(\
	ReadIdentifier
	,ZeroOrN(Expression(ReadChar(',')
			   ,ReadIdentifier))
	,Hook(check_print, local_ctx)))
    return (true);
  return (false);
}


int   main(int argc, char** argv)
{
  const char* bool_str[] = {"false", "true"};
  s_ctx root;

  if (argc > 1)
    {
      printf("Parsed string : [%s]\n",argv[1]);
      pushStream(argv[1]);
      saveContext();
      printf("%s\n", bool_str[list(&root) && getPos() == (int)strlen(argv[1])]);
      popStream();
    }
  else
    fprintf(stderr, "Usage : ./a.out \"list, to, test\"\n");
}
