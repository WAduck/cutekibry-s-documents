var a, b, c, i, j, ans:longint;
begin
    read(i, j, a, b, c);
    ans:=3;
    if a<>b then inc(ans);
    if a<>c then inc(ans);
    if b<>c then inc(ans);
    writeln(ans);
end.
