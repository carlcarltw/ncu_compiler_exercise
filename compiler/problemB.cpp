#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

static bool flag = true; //to check if the input is valid
static int pointer = 0;
struct token
{
  string stream;
  string type ;
  string value;
};
vector<token> out;//the output stream
void proc();
void Dcl();
void Astring();
void Stmt();
void output();
void scanner(string);
int main()
{
  string in;
  string in_;
  while(getline(cin,in_))
  {
    in+="$";
     in =in+in_;
  }
  scanner(in);
  proc();
  output();
  return 0;
}
void Stmt()
{
  if(out[pointer].type == "print")  pointer++;
  else
  {
    flag = false;
    return;
  }
  if(out[pointer].type == "id")    pointer++;
  else
  {
    flag = false ;
    return;
  }
}
void Astring()
{
  if(out[pointer].type == "quote")    pointer++;
  else
  {
    flag = false;
    return;
  }
  if(out[pointer].type == "string")    pointer++;
  else
  {
    flag = false;
    return;
  }
  if(out[pointer].type =="quote")    pointer++;
  else
  {
    flag = false;
    return;
  }
}
void Dcl()
{
  if(out[pointer].type == "strdcl")    pointer++;
  else
  {
    flag = false;
    return;
  }
 if(out[pointer].type == "id")    pointer++;
  else
  {
    flag = false;
    return;
  }
  Astring();
  return;
}

void proc()
{
  if(out[pointer].type == "strdcl"||out[pointer].type == "print")
  {
    Dcl();
    Stmt();
  }
}


void output()
{
  if(!flag)
  {
    cout<<"valid input"<<endl;
  }
  else
  {
    for(int i=0;i<out.size()-1;i++)
    {
      cout<<out[i].type<<" "<<out[i].stream<<endl;
    }
  }
}
void scanner(string in)
{
  in = in +" ";
  in = " "+ in;
  token temp,begin;
  for(string::iterator it = in.begin(); it != in.end(); it++)
  {
    token temp;
    int asc = *it, next = *(it+1), pre = *(it-1);
    if(asc == 32||asc == 36)
    {      }//do nothing
    else if(pre == 34)
    {
      if(asc == 32)
      {   }//do nothing
      else if((47 < asc && asc < 58) || (96 < asc && asc < 123) || (64 < asc && asc < 91))
      {
        temp.type = "string";
        temp.stream = *it;
        next = *(it+1);

        while((47 < next && next < 58) || (96 < next && next < 123) || (64 < next && next < 91))
        {
          it++;
          temp.stream += *it;
          next = *(it+1);
        }
      }
      out.push_back(temp);
    }
    else if(((96<asc&&asc<112)||asc==113||asc==114||(115<asc&&asc<123))&&pre != 34)//id
    {
      temp.stream = *it;
      temp.type = "id";
      out.push_back(temp);
    }
    else if(asc== 115)//s
    {
      temp.stream = "s";
      temp.type = "strdcl";
      out.push_back(temp);
    }
    else if(asc == 112)//p
    {
      temp.stream = "p";
      temp.type = "print";
      out.push_back(temp);
    }
    else if(asc == 34)//"
    {
      temp.type = "quote";
      temp.stream = "\"";
      out.push_back(temp);
      if(next==34)
      {
          temp.type = "string";
          temp.stream ="";
          out.push_back(temp);
      }
    }
    else
    {

      flag =false;
      temp.type = "error";
      out.push_back(temp);
      break;
    }
  }
  token buffer;
  buffer.type="end";
  out.push_back(buffer);
}
