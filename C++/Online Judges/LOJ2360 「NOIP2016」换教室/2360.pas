// f[i,j,0]=min{f[i-1,j,0]+w[c[i-1],c[i]],
//              f[i-1,j,1]+p[i-1]*w[d[i-1],c[i]]+(1-p[i-1])*w[c[i-1],c[i]]}
// f[i,j,1]=min{f[i-1,j-1,0]+p[i]*w[c[i-1],d[i]]+(1-p[i])*w[c[i-1],c[i]],
//                f[i-1,j-1,1]+p[i-1]*(p[i]*w[d[i-1],d[i]]+(1-p[i])*w[d[i-1],c[i]])
//                              +(1-p[i-1])*(p[i]*w[c[i-1],d[i]]+(1-p[i])*w[c[i-1],c[i]])
//               }
var f:array[1..2000,0..2000,0..1] of real;
var w:array[1..300,1..300] of longint;
var c,d:array[1..2000] of longint;
var p:array[1..2000] of real;
var i,j,k,n,m,nn,nm,x,y,z:longint;
var ans:real;
function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;
function min(a,b:real):real;
begin
  if a<b then min:=a else min:=b;
end;
begin
  fillchar(f,sizeof(f),67);
  fillchar(w,sizeof(w),63);
  read(n,m,nn,nm);
  for i:=1 to n do read(c[i]);
  for i:=1 to n do read(d[i]);
  for i:=1 to n do read(p[i]);
  for i:=1 to nm do begin
    read(x,y,z);
    if w[x,y]>z then begin
      w[x,y]:=z;
      w[y,x]:=z;
    end;
  end;
  for i:=1 to nn do w[i,i]:=0;
  for k:=1 to nn do
    for i:=1 to nn do
      for j:=1 to nn do
        w[i,j]:=min(w[i,j],w[i,k]+w[k,j]);

  f[1,m,0]:=0;
  f[1,m-1,1]:=0;
  for i:=2 to n do begin
    for j:=0 to m do begin
      f[i,j,0]:=min(f[i-1,j,0]+w[c[i-1],c[i]],
                    f[i-1,j,1]+p[i-1]*w[d[i-1],c[i]]+(1-p[i-1])*w[c[i-1],c[i]]);
      if j<m then
        f[i,j,1]:=min(f[i-1,j+1,0]+p[i]*w[c[i-1],d[i]]+(1-p[i])*w[c[i-1],c[i]],
                       f[i-1,j+1,1]+p[i-1]*(p[i]*w[d[i-1],d[i]]+(1-p[i])*w[d[i-1],c[i]])
                                     +(1-p[i-1])*(p[i]*w[c[i-1],d[i]]+(1-p[i])*w[c[i-1],c[i]])
                      );
      // writeln('f[',i,',',j,',','0]','=',f[i,j,0]:0:2);
      // writeln('f[',i,',',j,',','1]','=',f[i,j,1]:0:2);
      // writeln();
    end;
  end;
  ans:=1e16;
  for i:=0 to m do ans:=min(ans,min(f[n,i,0],f[n,i,1]));
  writeln(ans:0:2);
end.
