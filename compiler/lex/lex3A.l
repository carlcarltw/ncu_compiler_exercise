spy [a-z|A-Z|_]*cpy[a-z|A-Z|_]*

%%
{spy}    {
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
