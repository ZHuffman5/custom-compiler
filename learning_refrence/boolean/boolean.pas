{--------------------------------------------------------------}
program Cradle;

{--------------------------------------------------------------}
{ Constant Declarations } 
const TAB = ^I; 

{--------------------------------------------------------------} 
{ Variable Declarations } 
var Look: char; 		{ Lookahead Character }
                              
{--------------------------------------------------------------} 
{ Read New Character From Input Stream } 
procedure GetChar; 
begin
   Read(Look); 
end;

{--------------------------------------------------------------} 
{ Report an Error } 
procedure Error(s: string); 
begin
   WriteLn; WriteLn(^G, 'Error: ', s, '.'); 
end;

{--------------------------------------------------------------} 
{ Report Error and Halt } 
procedure Abort(s: string); 
begin
   Error(s); Halt; 
end;

{--------------------------------------------------------------} 
{ Report What Was Expected } 
procedure Expected(s: string); 
begin
   Abort(s + ' Expected'); 
end;

{--------------------------------------------------------------} 
{ Match a Specific Input Character } 
procedure Match(x: char); 
begin
   if Look = x then GetChar else Expected('''' + x + ''''); 
end;

{--------------------------------------------------------------} 
{ Recognize an Alpha Character } 
function IsAlpha(c: char): boolean; 
begin
   IsAlpha := upcase(c) in ['A'..'Z']; 
end;
                              
{--------------------------------------------------------------} 
{ Recognize an Addop }
function IsAddop(c: char): boolean;
begin
    IsAddop := c in ['+','-'];
end;

{--------------------------------------------------------------} 
{ Recognize a Decimal Digit } 
function IsDigit(c: char): boolean; 
begin
   IsDigit := c in ['0'..'9']; 
end;

{--------------------------------------------------------------} 
{ Recognize an Alphanumeric } 
function IsAlNum(c: char): boolean;
begin
    IsAlNum := IsAlpha(c) or IsDigit(c);
end;

{--------------------------------------------------------------} 
{ Recognize an Alphanumeric }
function IsBoolean(c: char): Boolean;
begin
   IsBoolean := UpCase(c) in ['T','F'];
end;

{--------------------------------------------------------------} 
{ Get a Boolaen Literal }
function GetBoolean: Boolean;
begin
   if not IsBoolean(Look) then Expected('Boolean Literal');
   GetBoolean := UpCase(Look) = 'T';
   Getchar;
end;

{--------------------------------------------------------------} 
{ Get an Identifier } 
function GetName: char; 
begin
   if not IsAlpha(Look) then Expected('Name'); 
   GetName := UpCase(Look); 
   GetChar;
end;

{--------------------------------------------------------------} 
{ Get a Number } 
function GetNum: char; 
begin
   if not IsDigit(Look) then Expected('Integer'); GetNum := Look; 
   GetChar;
end;

{--------------------------------------------------------------} 
{ Output a String with Tab } 
procedure Emit(s: string); 
begin
   Write(TAB, s); 
end;

{--------------------------------------------------------------} 
{ Output a String with Tab and CRLF } 
procedure EmitLn(s: string); 
begin
   Emit(s); WriteLn; 
end;

{--------------------------------------------------------------} 
{ Determine if Look is an OR or XOR term }
function isOrOp(c: char):  Boolean;
begin
   isOrOp := c in ['|','~'];
end;

{--------------------------------------------------------------} 
{ PLACEHOLDER }
procedure Relation;
begin
   EmitLn(Look);
   GetChar;
end;

{--------------------------------------------------------------} 
{ Translate and parse a Boolean Factor }
procedure BoolFactor;
begin
   if IsBoolean(Look) then 
      if GetBoolean then
         EmitLn('MOVE #-1,D0')
      else
         EmitLn('CLR D0')
   else 
      Relation;
end;
{--------------------------------------------------------------} 
{ Translate and parse a Boolaen NOT }
procedure NotFactor;
begin
   if Look = '!' then begin
      match('!');
      BoolFactor;
      EmitLn('EOR #-1,D0');
      end
   else
      BoolFactor;
end;

{--------------------------------------------------------------} 
{ Translate and parse a boolean term }
procedure BoolTerm;
begin
  NotFactor;
  while Look = '&' do begin
      EmitLn('MOVE D0,-(SP)');
      match('&');
      NotFactor;
      EmitLn('AND (SP)+,D0');
   end;
end;

{--------------------------------------------------------------} 
{ Process a boolean OR }
procedure BoolOr;
begin
   match('|');
   BoolTerm;
   EmitLn('OR (SP)+,D0');
end;

{--------------------------------------------------------------} 
{ Process a Boolaen XOR } 
procedure BoolXor;
begin
   Match('~');
   BoolTerm;
   EmitLn('EOR (SP)+,D0');
end;

{--------------------------------------------------------------} 
{ Translate and parse a Boolean Expression }
procedure BoolExpression;
begin
   BoolTerm;
   while isOrOp(Look) do begin
      EmitLn('MOVE D0,-(SP)');
      case Look of
         '|': BoolOr;
         '~': BoolXor;
      end;
   end;
end;
   
{--------------------------------------------------------------} 
{ Initialize } 
procedure Init; 
begin
   GetChar; 
end;

{--------------------------------------------------------------} 
{ Main Program } 
begin
   Init; 
   BoolExpression;
end.
{--------------------------------------------------------------}