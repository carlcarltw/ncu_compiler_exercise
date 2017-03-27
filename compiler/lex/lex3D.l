column ((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])
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
