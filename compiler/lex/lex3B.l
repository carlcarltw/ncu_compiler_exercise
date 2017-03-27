column ^[a-z|A-Z]+[ ]+[a-z|A-Z]+[ ]+noodles[ ]+[a-z|A-z]+$
%%
{column}    {
          printf("%s\n",yytext);
          }
\n     {}
.        {}
%%
int main(int argc, char* argv[])
{
  yylex();
  return 0;
}
