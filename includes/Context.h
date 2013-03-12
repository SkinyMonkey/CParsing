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

#ifndef __CONTEXT__
#define __CONTEXT__

typedef struct	t_parsingContext
{
  int		index;
  char*		wslist;
}		s_parsingContext;

void		saveContext(void);
bool		restoreContext(void);
bool		validContext(void);
void		setWsList(char* sWsList);

#define		LOCAL_CTX(var)	{var, {NULL, 0}}

#endif /* __CONTEXT__ */
