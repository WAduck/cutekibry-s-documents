{
f[i,j]:=max(f[k,l]) (k=1..i, l=1..j)
f[i-1,j]:=max(f[k,l]) (k=1..i-1, l=1..j)
f[i,j-1]:=max(f[k,l]) (k=1..i, l=1..j-1)
f[i,j]:=max(f[i-1,j],)
}
var f:array[0..100,0..100,0..10] of longint;
var sum:array[0..100,1..2] of longint;
var i,j,n,m,q:longint;
function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;
function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;
function dp(i,j,k:longint):longint;
var l:longint;
begin
  if (i<0) or (j<0) or (k<0) then
    dp:=-1000000000
  else if k=0 then
    dp:=0
  else if f[i,j,k]>-1000000000 then
    dp:=f[i,j,k]
  else begin
    f[i,j,k]:=max(dp(i-1,j,k),dp(i,j-1,k));
      // writeln('f[',i,',',j,',',k,']=',dp(i,j,k));
    for l:=0 to i-1 do f[i,j,k]:=max(f[i,j,k],dp(l,j,k-1)+sum[i,1]-sum[l,1]);
    for l:=0 to j-1 do f[i,j,k]:=max(f[i,j,k],dp(i,l,k-1)+sum[j,2]-sum[l,2]);
    if i=j then
      for l:=0 to i-1 do f[i,j,k]:=max(f[i,j,k],dp(l,l,k-1)+sum[i,1]-sum[l,1]+sum[j,2]-sum[l,2]);
    dp:=f[i,j,k];
  end;
end;
begin
  fillchar(f,sizeof(f),128);
  read(n,m,q);
  sum[0,1]:=0;
  sum[0,2]:=0;
  for i:=1 to n do for j:=1 to m do read(sum[i,j]);
  if m=1 then for i:=1 to n do sum[i,2]:=-1000000;
  for i:=2 to n do for j:=1 to m do inc(sum[i,j],sum[i-1,j]);
  writeln(dp(n,n,q));
  // for i:=0 to n do
  //   for j:=0 to n do
  //     for k:=0 to q do
  //       writeln('f[',i,',',j,',',k,']=',dp(i,j,k));
end.
