import java.util.*;
class InfixToPostfix
{
static String infixToPostfix(String infixExp)
{
String postfixExp="";
infixExp="("+infixExp+")";
Stack<Character> stack=new Stack<>();
for(int i=0;i<infixExp.length();i++)
{
char ch=infixExp.charAt(i);
if(Character.isLetterOrDigit(ch))
postfixExp+=ch;
else if(ch=='(')
stack.push(ch);
else if(ch==')')
{
while(!stack.isEmpty()&&stack.peek()!='(')
postfixExp+=stack.pop();
if(!stack.isEmpty())
stack.pop();
}
else
{
while(!stack.isEmpty()&&checkPriority(ch)<=checkPriority(stack.peek()))
postfixExp+=stack.pop();
stack.push(ch);
}
}
while(!stack.isEmpty())
{
if(stack.peek()=='(')
return "Invalid Expression";
postfixExp+=stack.pop();
}
return postfixExp;
}
static int checkPriority(char operator)
{
int priority=0;
if(operator=='^')
priority=3;
else if(operator=='/'||operator=='*')
priority=2;
else if(operator=='+'||operator=='-')
priority=1;
return priority;
}
static boolean isOperator(char ch)
{
return (ch=='^'||ch=='/'||ch=='*'||ch=='+'||ch=='-'||ch==')');
}
public static void main()
{
Scanner s=new Scanner(System.in);
//System.out.println("Enter the infix expression");
//String infixExp=s.next();
String infixExp="((AX+(B*CY))/(D­E))";
String postfixExp=infixToPostfix(infixExp);
System.out.println(postfixExp);
}
}