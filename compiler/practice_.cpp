#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

static bool flag = true; //to check if the input is valid
string token;
int i = 0;
//vector<string> output_;
void output();
void scanner(string);
void exprs();
void expr();
int main()
{
  string in;
  char in_;
  while(cin>>in_)
  {
    in += in_;
  }
scanner(in);
exprs();
output();
  //output();
  return 0;
}
void output()
{
  if(flag) {
    cout<<"valid";
  }  else {
    cout<<"error";
  }
}
void exprs()
{
//  cout<<"token[i]"<<token[i]<<endl;

  if(token[i] == '('||token[i] == '['||token[i] == '{')
  {
  //  cout<<"HIIII"<<endl;
    expr();
    exprs();
  }
  else if(token[i] =='$')
  {
    //do nothing
  }
}
void expr()
{
  //cout<<"I fuck you"<<endl;
  if(token[i] == '(')
  {
  //  cout<<"hi"<<endl;
    i++;
    exprs();
    if(token[i] != ')')
    {
    //  cout<<"QQ"<<endl;
      flag =false;
    }
    i++;
  }
  if(token[i] == '[')
  {
    i++;
    exprs();
    if(token[i] != ']')
    {
    //    cout<<"BB"<<endl;
      flag =false;
    }
    i++;
  }
  if(token[i] == '{')
  {
    i++;
    exprs();
    if(token[i] != '}')
    {
    //    cout<<"AA"<<endl;
      flag =false;
    }
    i++;
  }
}
void scanner(string in)
{
  in = in +" ";
  in = " "+ in;
  //token temp;
  for(string::iterator it = in.begin(); it != in.end(); it++)
  {
    if((*it) != '(' &&(*it) != ')'&&(*it) != '['&&(*it) != ']' &&(*it) != '{' &&(*it) != '}'&&(*it) != '\n'&& (*it) != '\t' && (*it) != '\r' && (*it) != ' ')
    {
      flag = false ;
    //  cout<<*it<<endl;
      //cout<<"DD"<<endl;
      break;
    }
    else if((*it) == ' ' || (*it) == '\n' ||(*it) == '\t' ||(*it) == '\r')
    {
      continue;
    }
    else
    {
        token +=*it;
    }
  }
  token += '$';
}
