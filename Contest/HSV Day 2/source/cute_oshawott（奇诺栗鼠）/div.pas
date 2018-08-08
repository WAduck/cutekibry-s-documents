var a,b,t:longint;
var c:real;
begin
    read(t);
    while t>0 do begin
        dec(t);
        read(a,b);
        c:=a/b;
        writeln(a, '/', b, '=', c:0:3);
    end;
end.
