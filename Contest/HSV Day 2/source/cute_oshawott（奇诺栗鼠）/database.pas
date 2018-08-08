var n, i, j, k, l, ans:longint;
var a:array[0..5, 1..505] of ansistring;
begin
    readln(n);
    for i:=1 to n do begin
        readln(a[i,1], a[i,2], a[i,3], a[i,4]);
    end;
    for i:=0 to 4 do begin
        ans:=n;
        for j:=1 to n-1 do
            for k:=j+1 to n do
                if ((a[j,1]=a[k,1]) or (i=1)) and ((a[j,2]=a[k,2]) or (i=2)) and ((a[j,3]=a[k,3]) or (i=3)) and ((a[j,4]=a[k,4]) or (i=4)) then
                    dec(ans);
        write(ans, ' ');
    end;
end.
// 6
// lg gd 13 js
// wwt gd 13 js
// hjw gd 14 js
// hjw gd 14 hf
// zzx gd 13 ls
// zzx gd 14 ls
