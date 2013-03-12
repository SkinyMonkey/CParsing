/*
** Copyright (C) 2012 Candiotti Adrien 
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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


int main(int argc, char *argv[])
{
  extern const char*	resstr[];
  bool	res;

  if (argc == 2)
    {
      pushStream(argv[1]);
      saveContext();
      s_ctx		oLocalCtx = {NULL, {NULL, 0}};
      
      printf("%d\n", getPos());
      res = rule(expression, expression, &oLocalCtx);
      printf("[%s]\n", resstr[getPos() == (int)strlen(argv[1])]);

      popStream();
    }
  return 0;
}
