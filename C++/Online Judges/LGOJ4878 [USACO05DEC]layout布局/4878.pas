var x,y,z:array[1..20000] of int64;
var dis:array[1..1000] of int64;
var i,n,m,m1,m2,flag:longint;

function min(a,b:longint):longint;
begin
  if a<b then
    min:=a
  else
    min:=b;
end;

procedure bellmanford();
var i,j:longint;
begin
  for i:=1 to n do
    dis[i]:=1000000000;
  dis[1]:=0;
  for i:=1 to n do
    for j:=1 to m do
      dis[y[j]]:=min(dis[y[j]],dis[x[j]]+z[j]);
end;

begin
  read(n,m1,m2);
  for i:=1 to m1 do
    read(x[i],y[i],z[i]);
  for i:=1 to m2 do begin
    read(y[i+m1],x[i+m1],z[i+m1]);
    z[i+m1]:=-z[i+m1];
  end;
  m:=m1+m2;
  bellmanford();
  flag:=dis[n];
  // for i:=1 to n do
  //   write(dis[i], ' ');
  if dis[n]=1000000000 then
    flag:=-2;
  for i:=1 to m do
    if dis[y[i]]>dis[x[i]]+z[i] then
      flag:=-1;
  writeln(flag);
end.
{
 x-y<=w1
 y-z<=w2
 x-z<=w3

 x-z<=min(w1+w2, w3)

 x-y>=w1
 y-x<=-w1
}
