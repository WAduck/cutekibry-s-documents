# [LSOI2018]NOIPPJ Round1
## 一、题目概况
<table width=100% style="text-align:center">
<tr>
    <th>中文题目名称</th>
    <td>成绩</td>
    <td>图书管理员</td>
    <td>棋盘</td>
    <td>魔法阵</td>
</tr>
<tr>
    <th>英文题目与子目录名</th>
    <td>score</td>
    <td>librarian</td>
    <td>chess</td>
    <td>magic</td>
</tr>
<tr>
    <th>可执行文件名</th>
    <td>score</td>
    <td>librarian</td>
    <td>chess</td>
    <td>magic</td>
</tr>
<tr>
    <th>输入文件名</th>
    <td>score.in</td>
    <td>librarian.in</td>
    <td>chess.in</td>
    <td>magic.in</td>
</tr>
<tr>
    <th>输出文件名</th>
    <td>score.out</td>
    <td>librarian.out</td>
    <td>chess.out</td>
    <td>magic.out</td>
</tr>
<tr>
    <th>每个测试点时限</th>
    <td>1秒</td>
    <td>1秒</td>
    <td>1秒</td>
    <td>1秒</td>
</tr>
<tr>
    <th>测试点数目</th>
    <td>10</td>
    <td>10</td>
    <td>10</td>
    <td>10</td>
</tr>
<tr>
    <th>每个测试点分值</th>
    <td>10</td>
    <td>10</td>
    <td>10</td>
    <td>10</td>
</tr>
<tr>
    <th>附加样例文件</th>
    <td>有</td>
    <td>有</td>
    <td>有</td>
    <td>有</td>
</tr>
<tr>
    <th>结果比较方式</th>
    <td colspan="4">全文比较（过滤行末空格和文末回车）</td>
</tr>
<tr>
    <th>题目类型</th>
    <td>传统</td>
    <td>传统</td>
    <td>传统</td>
    <td>传统</td>
</tr>
<tr>
    <th>运行内存上限</th>
    <td>256M</td>
    <td>256M</td>
    <td>256M</td>
    <td>256M</td>
</tr>
</table>

## 二、提交源程序文件名

<table width=100% style="text-align:center">
<tr>
    <th>对于C++语言</th>
    <td>score.cpp</td>
    <td>librarian.cpp</td>
    <td>chess.cpp</td>
    <td>magic.cpp</td>
</tr>
<tr>
    <th>对于C语言</th>
    <td>score.c</td>
    <td>librarian.c</td>
    <td>chess.c</td>
    <td>magic.c</td>
</tr>
<tr>
    <th>对于pascal语言</th>
    <td>score.pas</td>
    <td>librarian.pas</td>
    <td>chess.pas</td>
    <td>magic.pas</td>
</tr>
</table>

## 三、编译命令（不包含任何优化开关）

<table width=100% style="text-align:center">
<tr>
    <th>对于C++语言</th>
    <td>g++ -o score score.cpp -lm</td>
    <td>g++ -o librarian librarian.cpp -lm</td>
    <td>g++ -o chess chess.cpp -lm</td>
    <td>g++ -o magic magic.cpp -lm</td>
</tr>
<tr>
    <th>对于C语言</th>
    <td>gcc -o score score.c -lm</td>
    <td>gcc -o librarian librarian.c -lm</td>
    <td>gcc -o chess chess.c -lm</td>
    <td>gcc -o magic magic.c -lm</td>
</tr>
<tr>
    <th>对于pascal语言</th>
    <td>fpc score.pas</td>
    <td>fpc librarian.pas</td>
    <td>fpc chess.pas</td>
    <td>fpc magic.pas</td>
</tr>
</table>

## 注意事项：

1. 文件名（程序名和输入输出文件名）必须使用英文小写。
2. C/C++中函数main()的返回值类型必须是int，程序正常结束时的返回值必须是0。
3. 注意要对相应的程序建立同名子文件夹，评测时只评测以.cpp/c/pas为后缀名的文件。
4. 为了提升各位同学的编程能力，本次模拟赛不提供大样例。
5. 特别提醒：评测在Linux下进行，各语言的编译器版本以其为准。

评测时的Linux版本：

```plain
parrot
"Parrot GNU/Linux"
Release 4.3 64-bit
Kernel Linux 4.18.0-parrot10-amd64 x86_64
MATE 1.20.3

Memory: 3.8 GiB
Processor: Intel Celeron(R) CPU 3855U @ 1.60GHz × 2

gcc version 8.2.0 (Debian 8.2.0-7)

Free Pascal Compiler version 3.0.4+dfsg-20 [2018/07/02] for x86_64
Copyright (c) 1993-2017 by Florian Klaempfl and others
```

<br /><br /><br /><br /><br /><br /><br /><br />

## A - 成绩
### 题目描述
牛牛最近学习了C++入门课程，这门课程的总成绩计算方法是：

\(总成绩=作业成绩\times 20\%+小测成绩\times 30\%+期末考试成绩\times 50\%\)

老师给牛牛布置了 \(n\) 项作业和 \(m\) 次小测，作业成绩取所有作业成绩的平均分，小测成绩取所有小测成绩中第二高的。

注意：如果第一高和第二高的小测成绩相同，则取第三高的。也就是说，取的是不同小测成绩中第二高的。

### 输入格式
输入文件名为score.<span></span>in。

输入文件的第1行，两个非负整数 \(n, m\) ，分别表示老师给牛牛布置的作业数量和小测数量。

第2行， \(n\) 个非负整数 \(a_i\) ，表示作业成绩。

第3行， \(m\) 个非负整数 \(b_i\) ，表示小测成绩。

第4行，一个非负整数 \(x\) ，表示期末考试成绩。

所有成绩满分都是 \(100\) 分。

### 输出格式
输出文件名为score.out。

输出文件只有1行，包含一个整数，即牛牛这门功课的总成绩四舍五入到个位后的结果，满分也是 \(100\) 分。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th>score.in</th>
    <th>score.out</th>
</tr>
<tr style="vertical-align:top">
    <td>
        4 4     <br />
        20 10 10 40 <br />
        40 20 10 10 <br />
        50
    </td>    
    <td>
        35
    </td>
</tr>
</table>

### 输入输出样例1说明
牛牛的作业成绩是 \((20+10+10+40) \div 4=20\) 分，小测成绩是 \(20\) 分，期末考试成绩是 \(50\) 分，总成绩是 \(20 \times 20\%+20 \times 30\%+50 \times 50\%=4+6+25=35\) 分。

### 输入输出样例2
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th>score.in</th>
    <th>score.out</th>
</tr>
<tr style="vertical-align:top">
    <td>
        2 2     <br />
        18 22 <br />
        58 48 <br />
        80
    </td>
    <td>
        58
    </td>
</tr>
</table>

### 输入输出样例2说明
牛牛的作业成绩是 \((18+22) \div 2=20\) 分，小测成绩是 \(48\) 分，期末考试成绩是 \(80\) 分，总成绩是 \(20 \times 20\%+48 \times 30\%+80 \times 50\%=4+14.4+40=58.4\) 分，四舍五入后为 \(58\) 分。

### 数据说明
对于 \(30\%\) 的数据， \(n=m=2\) 。

对于 \(60\%\) 的数据， \(2 \leq n,m \leq 100\) ， 所有 \(a_i\) 和 \(b_i\) 各不相同。

对于 \(100%\) 的数据， \(2 \leq n,m \leq 3000000\) ， \(0 \leq a_i \leq 100\) 。

保证至少存在一对 \((i, j)\) 使 \(b_i \neq b_j\) 。

<br /><br /><br /><br /><br /><br /><br /><br />

## B - 图书管理员
### 题目描述
图书馆中每本书都有一个图书编码，可以用于快速检索图书，这个图书编码是一个正整数。

每位借书的读者手中有一个需求码，这个需求码也是一个正整数。如果一本书的图书编码恰好等于读者的需求码，那么这本书就是这位读者所需要的。

小D刚刚当上图书馆的管理员，她知道图书馆里所有书的图书编码，她请你帮她写一个程序，对于每位读者，求出他所需要的书存不存在，如果存在，这位读者将借走这本书。

### 输入格式
输入文件名为librarian.<span></span>in。

输入文件的第一行，包括两个正整数 \(n\) 和 \(q\) ，以一个空格分开，分别代表图书馆里书的数量和读者的数量。

接下来的 \(n\) 行，每行包含一个正整数，代表图书馆里某本书的图书编码。

接下来的 \(q\) 行，每行包含两个正整数，以一个空格分开，第一个正整数代表图书馆里读者的需求码的长度，第二个正整数代表读者的需求码。

### 输出格式
输出文件名为librarian.out。

输出文件有 \(q\) 行，每行包含一个整数，如果存在第 \(i\) 个读者所需要的书，则输出 \(1\) ，否则输出 \(0\) 。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th>librarian.in</th>
    <th>librarian.out</th>
</tr>
<tr style="vertical-align:top">
    <td>
        3 3     <br />
        15      <br />
        73      <br />
        222     <br />
        4 6777  <br />
        2 15    <br />
        2 15    <br />
    </td>    
    <td>
        0       <br />
        1       <br />
        0       <br />
    </td>
</tr>
</table>

### 输入输出样例1说明
一开始图书馆里有的图书编号： \(\{15,73,222\}\) ；

第 \(1\) 个读者想要编号为 \(6777\) 的图书，图书馆里没有，所以输出 \(0\) 。图书馆里有的图书编号： \(\{15,73,222\}\) 。

第 \(2\) 个读者想要编号为 \(15\) 的图书，图书馆里有，所以图书被借走了，输出 \(1\) 。图书馆里有的图书编号： \(\{73,222\}\) 。

第 \(3\) 个读者想要编号为 \(15\) 的图书，但这本书刚刚被借走了，所以没有，输出 \(0\) 。图书馆里有的图书编号： \(\{73,222\}\) 。

### 数据说明
对于 \(60\%\) 的数据， \(1 \leq n,q \leq 100\) ，需求码长度和图书编码的长度不超过 \(5\) 。

对于 \(100\%\) 的数据， \(1 \leq n,q \leq 100\) ，需求码长度和图书编码的长度不超过 \(100\) 。

数据保证所有需求码和图书编码开头数字不会为 \(0\) ，也就是说没有前导零。

<br /><br /><br /><br /><br /><br /><br /><br />

## C - 棋盘
### 题目描述
有一个 \(1 \times n \) 的棋盘，每个格子上写有一个正整数 \(a_i\) ，代表这一个格子上的金币数为 \(a_i^2\) 。你现在要从最左边走到最右边，收集一路上的金币。

当然，你还可以使用一次魔法，使每个格子上的数字变为 \(a_i+k\) ，其中 \(k\) 是一个正整数。当然，格子上的金币数也会随数字的改变而改变。此外，由于使用魔法是很累的，所以如果你使用了魔法，你最后获得的金币数还会除以 \(k\) （如果有余数则舍弃）。

搬送金币是很累的，所以你希望得到的金币最少。给出 \(x\) ，问：当 \(1 \leq k \leq x\) 时你最少能得到多少金币？

### 输入格式
输入文件名为chess.<span></span>in。

输入文件的第一行，一个正整数 \(n\) ，表示棋盘大小。

第二行， \(n\\) 个正整数 \(a_i\) ，表示棋盘上的整数。

第三行，一个正整数 \(q\) ，表示询问个数。

接下来 \(q\) 行，每行一个正整数 \(x\) ，表示询问中的 \(x\) 。

### 输出格式
输出文件名为chess.out。

输出文件有 \(q\) 行，每行一个正整数，表示答案。


### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th>chess.in</th>
    <th>chess.out</th>
</tr>
<tr style="vertical-align:top">
    <td>
        5           <br />
        1 2 3 4 5   <br />
        2           <br />
        1           <br />
        3
    </td>    
    <td>
        90          <br />
        190
    </td>
</tr>
</table>

### 输入输出样例1说明
棋盘上的整数分别为 \([1,2,3,4,5]\) ，金币个数为 \([1,4,9,16,25]\) 。

当 \(k=1\) 时，棋盘上的整数全部加 \(1\) ，变为 \([2,3,4,5,6]\) ，金币个数相应地变为 \([4,9,16,25,36]\) ，结果为 \(\frac {4+9+16+25+36}1 = \frac {90}1 = 90\) 。

当 \(k=2\) 时，棋盘上的整数全部加 \(2\) ，变为 \([3,4,5,6,7]\) ，金币个数相应地变为 \([9,16,25,36,49]\) ，结果为 \(\frac {9+16+25+36+49}2 = \frac {135}2 = 67.5\) ，向下取整变为 \(67\) 。

当 \(k=3\) 时，棋盘上的整数全部加 \(3\) ，变为 \([4,5,6,7,8]\) ，金币个数相应地变为 \([16,25,36,49,64]\) ，结果为 \(\frac {16+25+36+49+64}3 = \frac {190}3 = 63.333\ldots \) ，向下取整变为 \(63\) 。

对于第一个询问， \(1 \leq k \leq 1\) ，当 \(k=1\) 时取最小值为 \(90\) 。

对于第二个询问， \(1 \leq k \leq 3\) ，当 \(k=3\) 时取最小值为 \(63\) 。

### 数据说明
对于 \(30\%\) 的数据， \(1 \leq n,q \leq 100\) ， \(1 \leq a_i,x \leq 1000\) 。

另外 \(30\%\) 的数据， \(1 \leq n,q \leq 100000\) ， \(1 \leq a_i,x \leq 10000\) ，保证不同的 \(a_i\) 最多只有 \(100\) 个。

对于 \(100\%\) 的数据， \(1 \leq n,q \leq 600000\) ， \(1 \leq a_i,x \leq 600000\) 。

<br /><br /><br /><br /><br /><br /><br /><br />

## D - 魔法阵
### 题目描述
六十年一次的魔法战争就要开始了，大魔法师准备从附近的魔法场中汲取魔法能量。

大魔法师有 \(n\) 个魔法物品，编号分别为 \(1, 2, 3, \ldots, n\) 。大魔法师可以从中选取任意个（也可以一个都不选择）魔法物品组成魔法阵，但要保证魔法物品不会互相冲突。

同时，大魔法师认为，编号为 \(i\) 的魔法物品会与编号为 \(i^2\) 的魔法物品发生剧烈冲突，因此它们不能被同时选择。特殊地，编号为 \(1\) 的魔法物品不在此限。

现在，大魔法师想要知道，有多少个合法的魔法阵。由于答案过大，请输出答案除以 \((10^9+7\)) 的余数。

### 输入格式
输入文件名为magic.<span></span>in。

只有一行，一个正整数 \(n\) ，表示魔法物品的个数。

### 输出格式
输出文件名为magic.out。

只有一行，一个非负整数，表示答案。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th>magic.in</th>
    <th>magic.out</th>
</tr>
<tr style="vertical-align:top">
    <td>
        3
    </td>    
    <td>
        8
    </td>
</tr>
</table>

### 输入输出样例1说明
可以选择的方案如下：

方案 \(1\) ： \(\{\}\) ；

方案 \(2\) ： \(\{1\}\) ；

方案 \(3\) ： \(\{2\}\) ；

方案 \(4\) ： \(\{3\}\) ；

方案 \(5\) ： \(\{1,2\}\) ；

方案 \(6\) ： \(\{1,3\}\) ；

方案 \(7\) ： \(\{2,3\}\) ；

方案 \(8\) ： \(\{1,2,3\}\) ；

### 输入输出样例2
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th>magic.in</th>
    <th>magic.out</th>
</tr>
<tr style="vertical-align:top">
    <td>
        4
    </td>    
    <td>
        12
    </td>
</tr>
</table>

### 输入输出样例2说明
可以选择的方案如下：

方案 \(1\) ： \(\{\}\) ；

方案 \(2\) ： \(\{1\}\) ；

方案 \(3\) ： \(\{2\}\) ；

方案 \(4\) ： \(\{3\}\) ；

方案 \(5\) ： \(\{4\}\) ；

方案 \(6\) ： \(\{1,2\}\) ；

方案 \(7\) ： \(\{1,3\}\) ；

方案 \(8\) ： \(\{1,4\}\) ；

方案 \(9\) ： \(\{2,3\}\) ；

方案 \(10\) ： \(\{3,4\}\) ；

方案 \(11\) ： \(\{1,2,3\}\) ；

方案 \(12\) ： \(\{1,3,4\}\) ；

注意编号为 \(i\) 的魔法物品会与编号为 \(i^2\) 的魔法物品发生剧烈冲突（ \(1\) 除外），所以编号为 \(2\) 的魔法物品不能和编号为 \(4\) 的魔法物品被同时选择。

### 数据说明
对于 \(20\%\) 的数据， \(1 \leq n \leq 5\) 。

对于 \(50\%\) 的数据， \(1 \leq n \leq 20\) 。

对于 \(100\%\) 的数据， \(1 \leq n \leq 400\) 。
