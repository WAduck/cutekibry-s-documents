# [LSOI2018]NOIPPJ Round2
## 附加文件
* [附加样例](../文件/[LSOI2018]%20NOIPPJ%20Round2%20Sample.zip)

## 一、题目概况
<table width=100% style="text-align:center">
<tr>
    <th>中文题目名称</th>
    <td>三叉神经树</td>
    <td>购买巧克力</td>
    <td>购物街</td>
    <td>玉桂狗睡衣</td>
</tr>
<tr>
    <th>英文题目与子目录名</th>
    <td>tree</td>
    <td>chocolate</td>
    <td>shopping</td>
    <td>cinnamoroll</td>
</tr>
<tr>
    <th>可执行文件名</th>
    <td>tree</td>
    <td>chocolate</td>
    <td>shopping</td>
    <td>cinnamoroll</td>
</tr>
<tr>
    <th>输入文件名</th>
    <td>tree.in</td>
    <td>chocolate.in</td>
    <td>shopping.in</td>
    <td>cinnamoroll.in</td>
</tr>
<tr>
    <th>输出文件名</th>
    <td>tree.out</td>
    <td>chocolate.out</td>
    <td>shopping.out</td>
    <td>cinnamoroll.out</td>
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
    <td>20</td>
    <td>10</td>
    <td>20</td>
</tr>
<tr>
    <th>每个测试点分值</th>
    <td>10</td>
    <td>5</td>
    <td>10</td>
    <td>5</td>
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
    <td>tree.cpp</td>
    <td>chocolate.cpp</td>
    <td>shopping.cpp</td>
    <td>cinnamoroll.cpp</td>
</tr>
<tr>
    <th>对于C语言</th>
    <td>tree.c</td>
    <td>chocolate.c</td>
    <td>shopping.c</td>
    <td>cinnamoroll.c</td>
</tr>
<tr>
    <th>对于pascal语言</th>
    <td>tree.pas</td>
    <td>chocolate.pas</td>
    <td>shopping.pas</td>
    <td>cinnamoroll.pas</td>
</tr>
</table>

## 三、编译命令（不包含任何优化开关）

<table width=100% style="text-align:center">
<tr>
    <th>对于C++语言</th>
    <td>g++ -o tree tree.cpp -lm</td>
    <td>g++ -o chocolate chocolate.cpp -lm</td>
    <td>g++ -o shopping shopping.cpp -lm</td>
    <td>g++ -o cinnamoroll cinnamoroll.cpp -lm</td>
</tr>
<tr>
    <th>对于C语言</th>
    <td>gcc -o tree tree.c -lm</td>
    <td>gcc -o chocolate chocolate.c -lm</td>
    <td>gcc -o shopping shopping.c -lm</td>
    <td>gcc -o cinnamoroll cinnamoroll.c -lm</td>
</tr>
<tr>
    <th>对于pascal语言</th>
    <td>fpc tree.pas</td>
    <td>fpc chocolate.pas</td>
    <td>fpc shopping.pas</td>
    <td>fpc cinnamoroll.pas</td>
</tr>
</table>

## 注意事项：

1. 文件名（程序名和输入输出文件名）必须使用英文小写。
2. C/C++中函数main()的返回值类型必须是int，程序正常结束时的返回值必须是0。
3. 注意要对相应的程序建立同名子文件夹，评测时只评测以.cpp/c/pas为后缀名的文件。
4. 特别提醒：评测在Linux下进行，各语言的编译器版本以其为准。

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

## A - 三叉神经树 (tree.cpp/c/pas)
### 题目描述
明明是个热爱学习的OIer，最近为了准备普及组，正在勤奋地刷着题。正在他写 [SHOI2012]三叉神经树 的时候，他发现一件奇怪的事情：他的程序本地能跑出正确答案，交到网站上评测却没有输出。经过几天几夜的调试后，他终于发现了问题：没有删除文件输入输出流。

在C++中，freopen是一个控制重定向文件输入输出流的函数。为了避免再次出现这样的事情，他希望你可以帮助他写一个程序：读入一份代码，输出代码中的freopen个数。

注意：题目只需要你输出freopen的个数，不需要去考虑前面是否有任何字符（例如`// freopen`也算是一个freopen）。

不保证代码可以正常编译。

### 输入格式
输入文件名为tree.<span></span>in。

输入文件有多行，表示代码。

### 输出格式
输出文件名为tree.out。

输出文件只有一行，一个整数，表示代码中的freopen个数。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>tree.in</th>
    <th>tree.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        #include &lt;cstdio&gt;                                     <br />
        using namespace std;                                        <br />
        int main(){                                                 <br />
        &nbsp;&nbsp;&nbsp;&nbsp;freopen("test.in", "r", stdin);     <br />
        &nbsp;&nbsp;&nbsp;&nbsp;freopen("test.out", "w", stdout);   <br />
        &nbsp;&nbsp;&nbsp;&nbsp;int a, b;                           <br />
        &nbsp;&nbsp;&nbsp;&nbsp;scanf("%d %d", &a, &b);             <br />
        &nbsp;&nbsp;&nbsp;&nbsp;printf("%d\n", a+b);                <br />
        &nbsp;&nbsp;&nbsp;&nbsp;return 0;                           <br />
        }
    </td>
    <td>
        2
    </td>
</tr>
</table>

见选手目录下的tree/tree1.in和tree/tree1.ans。

该组样例数据范围同第 \(1\) 个测试点。

### 输入输出样例1说明
在这份代码的第四行和第五行各出现了一个freopen，所以答案为2。

### 输入输出样例2
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>tree.in</th>
    <th>tree.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        freopen                         <br />
        freopenfreopenfreopen           <br />
        infreopenline                   <br />
                                        <br />
        fre open                        <br />
        fre...open                      <br />
        Freopen                         <br />
        fre                             <br />
        open                            <br />
        assign('tree.in', input);       <br />
        with open('tree.in', 'r') as f:
    </td>
    <td>
        5
    </td>
</tr>
</table>

见选手目录下的tree/tree2.in和tree/tree2.ans。

该组样例数据范围同第 \(1\) 个测试点。

### 输入输出样例2说明
第一行出现了一个freopen；

第二行出现了三个freopen；

第二行出现了一个freopen。

注意：如果freopen之间有空格、换行，或不是全部小写，不计入答案。

### 输入输出样例3
见选手目录下的tree/tree3.in和tree/tree3.ans。

该组样例数据范围同第 \(4\) 个测试点。

### 输入输出样例4
见选手目录下的tree/tree4.in和tree/tree4.ans。

该组样例数据范围同第 \(7\) 个测试点。

### 数据说明
本题共有 \(10\) 个测试点。

对于第 \(1,2,3\) 个测试点，字符数（包括换行符'\n'和空格' '）不超过 \(1000\) 。

对于第 \(4,5,6\) 个测试点，输入不包含任何空格，仅在文末有一个换行符。

对于所有测试点，字符数（包括换行符'\n'和空格' '）不超过 \(100000\) 。

数据保证输入中只包含换行符、空格、特殊符号、字母和数字，所有字符的ASCII小于 \(128\) 。

<br /><br /><br /><br /><br /><br /><br /><br />

## B - 购买巧克力 (chocolate.cpp/c/pas)
明明和宁宁是好朋友。

最近NOIP要到了，明明很高兴，因为他到时候就可以去找宁宁玩了。为了准备和宁宁见面，明明决定去零食店买一些好吃的巧克力。

明明决定买 \(n1\) 份白巧克力和 \(n2\) 份黑巧克力 。商店一共有 \(m\) 份巧克力，每份巧克力的价格是 \(p\) ，有白色、黑色、混合三种口味。混合巧克力可以作为一份白巧克力，也可以作为一份黑巧克力。

明明因为考试考砸了，所以没有太多的零花钱（不会超过 \(10^9\) 元）。他希望你能写一个程序，帮助他计算如果要满足购买的要求，至少要花多少钱。

### 输入格式
输入文件名为chocolate.<span></span>in。

输入文件的第一行，三个非负整数 \(m, n1, n2\) ，表示商店的巧克力数量、明明决定购买的白巧克力数量和黑巧克力数量。

接下来 \(m\) 行，每行两个非负整数 \(t, p\) ，表示巧克力的口味和价格。

如果 \(t=1\) ，则该巧克力是白色的；

如果 \(t=2\) ，则该巧克力是黑色的；

如果 \(t=3\) ，则该巧克力是混合的。

### 输出格式
输出文件名为chocolate.out。

输出文件只有一行，一个非负整数，表示最少花费。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>chocolate.in</th>
    <th>chocolate.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        5 2 2   <br />
        1 4     <br />
        2 3     <br />
        1 2     <br />
        2 6     <br />
        2 5
    </td>
    <td>
        14
    </td>
</tr>
</table>

见选手目录下的chocolate/chocolate1.in和chocolate/chocolate1.ans。

该组样例数据范围同第 \(2\) 个测试点。

### 输入输出样例1说明
选择第一份、第二份、第三份、第五份巧克力，花费 \(4+3+2+5=14\) 元。

### 输入输出样例2
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>chocolate.in</th>
    <th>chocolate.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        5 2 2   <br />
        1 5     <br />
        1 3     <br />
        2 4     <br />
        2 6     <br />
        3 5
    </td>
    <td>
        17
    </td>
</tr>
</table>

见选手目录下的chocolate/chocolate2.in和chocolate/chocolate2.ans。

该组样例数据范围同第 \(1\) 个测试点。

### 输入输出样例2说明
选择第一份、第二份、第三份、第五份巧克力，花费 \(5+3+4+5=17\) 元。

第五份巧克力是混合巧克力，这里当作黑色巧克力用。

### 输入输出样例3
见选手目录下的chocolate/chocolate3.in和chocolate/chocolate3.ans。

该组样例数据范围同第 \(13\) 个测试点。

### 数据说明
本题共有 \(20\) 个测试点。

<table width=100% style="text-align:center">
<tr>
    <th style="text-align:center">数据点编号</th>
    <th style="text-align:center">\(m, n1, n2\)</th>
    <th style="text-align:center">\(p\)</th>
    <th style="text-align:center">有无混合</th>
</tr>
<tr>
    <td>\(1\)</td>
    <td rowspan="6" style="vertical-align:middle">\(\leq 10\)</td>
    <td rowspan="6" style="vertical-align:middle">\(\leq 100\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(2\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(3\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(4\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(5\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(6\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(7\)</td>
    <td rowspan="6" style="vertical-align:middle">\(\leq 1000\)</td>
    <td rowspan="6" style="vertical-align:middle">\(\leq 1000\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(8\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(9\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(10\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(11\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(12\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(13\)</td>
    <td rowspan="8" style="vertical-align:middle">\(\leq 100000\)</td>
    <td rowspan="8" style="vertical-align:middle">\(\leq 10000\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(14\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(15\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(16\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(17\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(18\)</td>
    <td>\(\times\)</td>
</tr>
<tr>
    <td>\(19\)</td>
    <td>\(\sqrt{}\)</td>
</tr>
<tr>
    <td>\(20\)</td>
    <td>\(\times\)</td>
</tr>
</table>

数据保证一定存在满足购买需求的方法。

有无混合：如果为 \(\times\) ，则数据保证 \(t \neq 3\) 。

<br /><br /><br /><br /><br /><br /><br /><br />

## C - 购物街 (shopping.cpp/c/pas)
### 题目描述
明明通过了三叉神经树之后，便准备去购买巧克力了。

他脑子里又突然闪过一个念头：既然我要买巧克力，那不如也顺便买些别的东西吧。

于是，毛绒玩偶，玫瑰花，玉桂狗睡衣……他一个个地列出了清单。

为了简化问题，我们假设：

购物街上有 \(n\) 家商铺，从第 \(i\) 家商铺到第 \(i+1\) 家商铺需要步行 \(d_i\) 的路程。

第 \(i\) 家商铺有 \(m_i\) 份商品，第 \(j\) 件商品的价格和重要度分别为 \(p_{ij}\) 和 \(v_{ij}\) 。

现在明明可以从任意一家店铺出发。他希望他购买的总金额不超过 \(a\) ，总重要度不小于 \(b\) ，同时要使步行的路程最小。

问：最小的路程是多少？

### 输入格式
输入文件名为shopping.<span></span>in。

输入文件的第一行，三个正整数 \(n, a, b\) ，表示商铺个数、购买总金额上限和总重要度下限。

第二行， \(n-1\) 个正整数 \(d_i\) ，表示第 \(i\) 家商铺和第 \(i+1\) 家商铺之间的距离。

接下来 \(n\) 行，每行若干个正整数。第一个整数 \(m_i\) ，表示商铺商品数；接下来 \(m_i\) 对整数 \(p_{ij}\) 和 \(v_{ij}\) ，分别描述了这些商品的价格和重要度。

### 输出格式
输出文件名为shopping.out。

输出文件只有一行，一个整数，表示最小步行的路程。

如果不存在合法的方案，请输出 \(-1\) 。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>shopping.in</th>
    <th>shopping.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        3 10 6      <br />
        1 2         <br />
        2 1 1 2 2   <br />
        1 7 2       <br />
        1 3 5       <br />
    </td>
    <td>
        2
    </td>
</tr>
</table>

见选手目录下的shopping/shopping1.in和shopping/shopping1.ans。

该组样例数据范围同第 \(5\) 个测试点。

### 输入输出样例1说明
从第 \(2\) 家商铺走到第 \(3\) 家商铺，需要走的距离为 \(2\) 。

选择购买 \((p=7, v=2)\) 和 \((p=3, v=5)\) 的物品，总价格为 \(7+3=10 \leq 10\) ，总价值为 \(2+5=7 \geq 6\) ，满足要求。

### 输入输出样例2
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>shopping.in</th>
    <th>shopping.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        4 10 10         <br />
        1 2 4           <br />
        2 6 7 5 6       <br />
        2 5 4 6 5       <br />
        1 12 7          <br />
        3 5 3 2 3 3 3
    </td>
    <td>
        1
    </td>
</tr>
</table>

见选手目录下的shopping/shopping2.in和shopping/shopping2.ans。

该组样例数据范围同第 \(5\) 个测试点。

### 输入输出样例2说明
从第 \(1\) 家商铺走到第 \(2\) 家商铺，需要走的距离为 \(1\) 。

选择购买 \((p=5, v=6)\) 和 \((p=5, v=4)\) 的物品，总价格为 \(7+3=10 \leq 10\) ，总价值为 \(6+4=10 \geq 10\) ，满足要求。

### 输入输出样例3
见选手目录下的shopping/shopping3.in和shopping/shopping3.ans。

该组样例数据范围同第 \(7\) 个测试点。

### 数据说明
本题共有 \(10\) 个测试点。

对于第 \(1,2\) 个测试点， \(p_{ij}=1\) 。

对于第 \(3,4\) 个测试点，购买金额上限不小于所有商品价格的总和，即 \(a \geq \sum_{i=1}^n \sum_{j=1}^{m_i} p_{ij}\) 。

对于第 \(1,2,3,4,5,6\) 个测试点， \(1 \leq n \leq 10\) ， \(1 \leq a,p_{ij},b,v_{ij} \leq 100\) 。

对于所有的测试点， \(1 \leq n \leq 100\) ， \(1 \leq a,p_{ij} \leq 100\) ， \(1 \leq b,v_{ij},d_i \leq 100000\) ，所有商铺的商品总数不会超过 \(1000\) ，即 \(\sum_{i=1}^n m_i \leq 1000\) 。

<br /><br /><br /><br /><br /><br /><br /><br />

## D - 玉桂狗睡衣 (cinnamoroll.cpp/c/pas)
### 题目描述
明明有一天在网上看到了玉桂狗睡衣，觉得非常可爱，非常喜欢。

他想，要是宁宁穿上了玉桂狗睡衣，那该是多么可爱，多么温暖！比起女装来说，他更想要看到宁宁穿这个的样子。

沉浸在幻想之中的明明无法自拔，于是就白白浪费了一个周末的时间。当然，他也没有准备好这道题目的背景。

看着看着，看着玉桂狗那长长的耳朵，明明不禁想到了一只和它一样可爱的兔子——月见。

明明记得，那只兔子和他玩过一个游戏，游戏是这样的——

有一个画有 \(n\) 个格子的棋盘，上面格子的编号分别为 \(1 \ldots n\) 。

月见一开始在第 \(1\) 个格子，它想要跳到第 \(n\) 格去，只能往前，不能退后。

当然，为了加大游戏难度，月见还会给出 \(m\) 个整数，对于给出的整数 \(x_i\) ，月见不能跳到编号为 \(x_i\) 倍数的格子上去。

月见想考考小明，有多少种合法的方案？当然，因为方案很大，月见只想知道方案数除以 \((10^9+7)\) 的余数。

这个问题小明一直都想不出来——直到离别的时候，直到月见回到月亮上去的时候，他也没有想出解决的方法。

他希望你可以帮助他解决这个问题……

### 输入格式
输入文件名为cinnamoroll.<span></span>in。

输入文件的第一行，两个非负整数 \(n,m\) ，表示棋盘格子的数量和月见给出的整数数量。

第二行， \(m\) 个正整数 \(x_i\) ，表示月见给出的整数。

### 输出格式
输出文件名为cinnamoroll.out。

输出文件只有一行，一个整数，表示方案总数除以 \((10^9+7)\) 的余数。

### 输入输出样例1
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>cinnamoroll.in</th>
    <th>cinnamoroll.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        11 2     <br />
        2 3
    </td>
    <td>
        4
    </td>
</tr>
</table>

见选手目录下的cinnamoroll/cinnamoroll1.in和cinnamoroll/cinnamoroll1.ans。

该组样例数据范围同第 \(3\) 个测试点。

### 输入输出样例1说明
根据题意可得，月见不可以踏上编号为 \(2\) 的倍数或编号为 \(3\) 的倍数的格子，也就是不能踏上编号为 \(2,3,4,6,8,9,10\) 的格子。

可以选择的方案如下：

方案 \(1\) ： \(1 \rightarrow 11\) ；

方案 \(2\) ： \(1 \rightarrow 5 \rightarrow 11\) ；

方案 \(3\) ： \(1 \rightarrow 7 \rightarrow 11\) ；

方案 \(4\) ： \(1 \rightarrow 5 \rightarrow 7 \rightarrow 11\) ；

### 输入输出样例2
<table width=100% style="font-family:monospace,consolas,Ubuntu Mono">
<tr>
    <th width=50%>cinnamoroll.in</th>
    <th>cinnamoroll.out</th>
</tr>
<tr style="vertical-align:top">
    <td width=50%>
        4 0     <br />
        &nbsp;
    </td>
    <td>
        4
    </td>
</tr>
</table>

见选手目录下的cinnamoroll/cinnamoroll2.in和cinnamoroll/cinnamoroll2.ans。

该组样例数据范围同第 \(1\) 个测试点。

### 输入输出样例2说明
所有格子都没有限制。

可以选择的方案如下：

方案 \(1\) ： \(1 \rightarrow 4\) ；

方案 \(2\) ： \(1 \rightarrow 2 \rightarrow 4\) ；

方案 \(3\) ： \(1 \rightarrow 3 \rightarrow 4\) ；

方案 \(4\) ： \(1 \rightarrow 2 \rightarrow 3 \rightarrow 4\) ；

### 输入输出样例3
见选手目录下的cinnamoroll/cinnamoroll3.in和cinnamoroll/cinnamoroll3.ans。

该组样例数据范围同第 \(10\) 个测试点。

### 输入输出样例4
见选手目录下的cinnamoroll/cinnamoroll4.in和cinnamoroll/cinnamoroll4.ans。

该组样例数据范围同第 \(13\) 个测试点。

### 数据说明
本题共有 \(20\) 个测试点。

<table width=100% style="text-align:center">
<tr>
    <th style="text-align:center">数据点编号</th>
    <th style="text-align:center">\(n\)</th>
    <th style="text-align:center">\(m\)</th>
</tr>
<tr>
    <td>\(1\)</td>
    <td rowspan="3" style="vertical-align:middle">\(\leq 20\)</td>
    <td>\(=0\)</td>
</tr>
<tr>
    <td>\(2\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(3\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(4\)</td>
    <td rowspan="3" style="vertical-align:middle">\(\leq 5000\)</td>
    <td>\(=0\)</td>
</tr>
<tr>
    <td>\(5\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(6\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(7\)</td>
    <td rowspan="4" style="vertical-align:middle">\(\leq 500000\)</td>
    <td>\(=0\)</td>
</tr>
<tr>
    <td>\(8\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(9\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(10\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(11\)</td>
    <td rowspan="10" style="vertical-align:middle">\(\leq 10^9\)</td>
    <td>\(=0\)</td>
</tr>
<tr>
    <td>\(12\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(13\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(14\)</td>
    <td>\(=0\)</td>
</tr>
<tr>
    <td>\(15\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(16\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(17\)</td>
    <td>\(=1\)</td>
</tr>
<tr>
    <td>\(18\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(19\)</td>
    <td>\(=2\)</td>
</tr>
<tr>
    <td>\(20\)</td>
    <td>\(=2\)</td>
</tr>
</table>

对于所有测试点，保证 \(1 < x_i < n\) ， \(n\) 不为 \(x_i\) 的倍数。
