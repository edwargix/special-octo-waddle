#include "declarator.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>


/* dcl: parse a declarator */
void dcl(void)
{
  int ns;

  for (ns = 0; gettoken() == '*'; )  /* count *'s */
    ns++;
  _dirdcl();
  while(ns-- > 0)
    strcat(out, " pointer to");
}


/* dirdcl: parse a direct declarator */
void _dirdcl(void)
{
  int type;

  if (tokentype == '(') {
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME)  /* variable name */
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");
  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}


int gettoken(void)  /* return next token */
{
  int c;
  char *p = token;

  while ((c = getchar()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getchar()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetc(c, stdin);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getchar()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getchar()); )
      *p++ = c;
    *p = '\0';
    ungetc(c, stdin);
    return tokentype = NAME;
  } else
    return tokentype = c;
}
