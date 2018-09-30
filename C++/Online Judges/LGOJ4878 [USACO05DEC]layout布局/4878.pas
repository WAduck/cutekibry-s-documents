var x,y,z:array[1..20000] of int64;
var dis:array[1..1000] of int64;
var i,n,m,m1,m2,flag:longint;

procedure bellmanford();
var i,j:longint;
begin
  for i:=1 to n do
    dis[i]:=1000000000;
  for i:=1 to n do
    for j:=1 to m do
      dis[y[i]]:=min(dis[y[i]],dis[x[i]]+z[i]);
end;

begin
  read(n,m1,m2);
  for i:=1 to m1 do
    read(x[i],y[i],z[i]);
  for i:=1 to m2 do
    read(x[i+m1],y[i+m1],z[i+m1]);
  m:=m1+m2;
  bellmanford();
  flag:=0;
  if dis[n]=1000000000
  for i:=1 to m do
    if dis[y[i]]<dis[x[i]]+z[i] then
      flag:=-1
end.
{
 x-y<=w1
 y-z<=w2
 x-z<=w3

 x-z<=min(w1+w2, w3)

 x-y>=w1
 y-x<=-w1
}
