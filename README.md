CParsing
========

A simple recursive descent parser framework in C

At the beginning it was suppose to be used in parser generation.
This code was build so you can use it in a way really close to the BNF way.

For example this list rule:

list ::= #identifier [',' #identifier]* #check_print
;

Can be translated by:

bool    check_print(s_ctx* ctx)
{
  printf("The rule was correclty executed\n");
  return (true);
}

bool    list(s_ctx* parent_ctx)
{
  s_ctx local_ctx = LOCAL_CTX(parent_ctx);

  if (expression(\
                 readIdentifier
                ,ZeroOrN(Expression(readIdentifier))
                ,Hook(check_print, ctx)))
    return (true);
  return (false);
}


int   main(void)
{
  const char* bool_str[] = {"false", "true"};
  s_ctx root;

  pushStream("this ,is, a , list");
  saveContext();
  printf("%s", bool_str[list(&root)]);
  validateContext();
  popStream();
}
