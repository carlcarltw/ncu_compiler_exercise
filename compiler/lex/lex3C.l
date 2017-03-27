column ^[ ]*0[X|x][0-9a-fA-F]{1,8}$
%{
	char temp[100];
%}
%%
{column}    {
		sscanf(yytext,"%s",temp);
          	printf("%s\n",temp);
          }
\n     {}
.        {}
%%
int main(int argc, char* argv[])
{
  yylex();
  return 0;
}
