// 设f[i,j]为(i, j)的最少点击次数
// 则有
// f[i,j]=min{f[i-1,j-up[i-1]]+1, f[i-1,j+down[i-1]], f[i,j-up[i-1]]+1}
// f[i,m]=min{f[i,m-j]+1,f[i-1,m-j]+1} (j<=up[i-1])
var f:array[0..1,1..1000] of longint;
var down,up:array[0..10000] of longint;
var bottom,top:array[0..10000] of longint;
var i,j,n,m,q,x,y,sum,ans,flag:longint;
const
  INF=1000000;

function max(a,b:longint):longint;
begin
  if a>b then
    max:=a
  else
    max:=b;
end;
function min(a,b:longint):longint;
begin
  if a<b then
    min:=a
  else
    min:=b;
end;

begin
  fillchar(f,sizeof(f),0);
  read(n,m,q);
  for i:=0 to n-1 do
    read(up[i], down[i]);
  for i:=0 to n do begin
    bottom[i]:=0;
    top[i]:=m+1;
  end;
  for i:=1 to q do begin
    read(x);
    read(bottom[x], top[x]);
  end;
  sum:=0;
  x:=0;
  y:=1;
  for i:=1 to n do begin
    y:=x;
    x:=1-x;
    // writeln('# ', i, ' ', bottom[i], ' ', top[i]);

    for j:=1 to m do
      f[x,j]:=INF;
    for j:=up[i-1]+1 to m do
      f[x,j]:=min(f[x,j-up[i-1]]+1, f[y,j-up[i-1]]+1);
    for j:=1 to m-down[i-1] do
      f[x,j]:=min(f[x,j], f[y,j+down[i-1]]);
    for j:=0 to up[i-1] do
      if m>j then
        f[x,m]:=min(f[x,m], min(f[x,m-j]+1,f[y,m-j]+1));
    for j:=1 to bottom[i] do
      f[x,j]:=INF;
    for j:=top[i] to m do
      f[x,j]:=INF;
    // for j:=1 to m do
    //   write(f[x,j], ' ');
    // writeln();

    flag:=0;
    for j:=1 to m do
      if f[x,j]<INF then
        flag:=1;
    if flag=0 then begin
      writeln(0);
      writeln(sum);
      // writeln(i);
      exit;
    end;
    if top[i]<=m then
      inc(sum);
    // writeln();
  end;

  ans:=f[x,1];
  for i:=2 to m do
    ans:=min(ans, f[x,i]);
  writeln(1);
  writeln(ans);
end.
