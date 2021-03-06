# ABC105
Atcoder Beginner Contest105の自分の解答

リハビリがてらサクッとやるつもりだったんだけど、なんだかなぁ。

# A
出力形式はちゃんと読みましょう。

# B
DPっぽいフラグを立ててループを回す。この場合は25回回すだけで十分だが、別に何回回しても良い。

ローカルでテストしない場合もコンパイルぐらいはしましょう。せぐふぉにも注意

# C
難しい。分からなかった。もう少し紙で計算すれば分かったかもしれない。

0もしくはぴったり(-2)^nとなるケース以外においては、その数字より大きくなるもしくはその数字より小さくなる(-2)^nを探してそのビットを立てる、という作業の繰り返しになる。その数字が正であれば大きくなるものを、負ならば小さくなるものを探す。そして得られた(-2)^nを引き、同様の作業を繰り返すことで各ビットを確定させる。各ループでは、数字の絶対値は小さくなっていくはず……

だったのだが、結構多くの場合で無限ループになりそれを解消できずに終了。

### C(解説読んだ)
ムズすぎる。Cで出していい問題じゃない。

negabinaryという変換形式らしいです。そこを参考にして解を出した。

まず、1桁目について考える。これは簡単で奇数であれば1、偶数であれば0である。次に2桁目以降について考える。例えば8という数字が欲しければ16+(-8)によって実現できる。このように2進数における特定のビットがあって欲しい符号になかった場合、その直上のビットとまとめて立てることで目標のビットと同じ数字を得ることができる。

とある-2進数の数字tを下から順番に決めていくうえにおいて、nとtを一致させることがこの問題の目標となる。この考え方では確定した数字の分は引いて考えても良い。したがって2桁目以降について考えるときn-tは必ず偶数となる。

同様に「あるビットを立てるためにはそのビットもしくはそのビットと直上のビットを立てる必要がある」というところから、逆に未確定の分(n-t)について(-2)^nで割り切れるならばnビット目は0であるが成立する。これをすべての桁（n-tが0になるまで）について行う。

# D
問題文の読解が少々難しかった。典型なのに40分使ったのは情けない。

一定の区間の累積和がmod mにおいて0になる部分の数を調べる問題。mod mは単調増加ではないのでしゃくとり法は使えない。

とりあえず累積和を取る。mod mにおいて0になる区間とは、a_1からの累積和の剰余が等しい部分のことなので（引いて区間和を取るとmod mにおいて0になるため）それを探したものにフラグを立てながら探していく。

いちいち全部の箱についてやっているとO(N^2)となり時間がないのでそれぞれの余りについて短縮化を考える。ようするにmod mにおいて等しい2つの箱の選び方の総数なのでnC2=n\*(n-1)/2で表せる。よって余りによってまとめられた。

これで提出すると最後のテストケースでTLE。たとえば1ずつインクリメントして剰余がすべての箱で違う場合にO(N^2)となることが判明した。

これまでの考察では箱の順番を気にしていた。しかし、実は順番は一切気にする必要がない。したがってmap等O(1)であまりを持てる構造で余りが等しいものの個数をすべて数え上げてO(N)に落とせる。