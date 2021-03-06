# ABC064
Atcoder Begginer Contest 064の自分の解答

# A
色の順序が決まっているので100の位10の位1の位で算数の要領で順番に足していく。

色の順番が決まってなかったら結構難しい問題になってそう。

# B
最も座標が小さいところから最も座標が大きいところへ移動するのが最小の移動量である。

よってソートして最大値-最小値で終了。

# C
誤読でクソみたいに時間食った。

まず、レートが400の倍数で区切られていることを頼りにレートを色ごとに区切る（3200以上を含めて9グループに分割する）。この時点で3200未満のグループの種類の数が最小値であることが分かる（ **注意** ）。最大値はこれに3200以上のグループの人数を加えた値である。

ここで **注意** として、全員3200以上のとき、最小値が0になってしまう。色の種類が0であることは考えられないので、最小値は1である。

3200以上の人が使える色はそれまでに出てきた8種類のうちのどれかだと80分弱誤読しており、大変なタイムロスをした。コードにもそのときの爪痕（未使用の変数等）が残っている。

# D
(と)の数をそれぞれカウントしていくが、このとき以下の4種類にグルーピングする。

1. (の登場回数
2. )の登場回数
3. 左から数えたときに最初に(が出てくるまでに)が出てくる回数
4. 右から数えたときに最初に)が出てくるまでに(が出てくる回数

3と4はそのまま挿入すればよい。1と2について、差分をそれぞれ最初と最後に加えていけばいいのだが、すでに3と4で使われている分を引いて考える必要があることに注意する。

さらに、全部(あるいは)のとき、以上のアルゴリズムは正しく動作しない可能性があると判断したので、その場合は別途処理を行うようにした。

以上のようにすることで概ね正しく動くようになるのだが、"()))((()"のように最初が(かつ最後が)で、(と)の使用回数が等しい場合には正しく動作しない。これを回避するために、最初の段階で()の組み合わせが成立しているものについては除くことにする。"((()))"のような場合もあるのでこの処理は再帰的に行う必要があるため計算量が心配だが、N≦100なので十分間に合うと判断した（間に合った）。

### 追記(2017/6/12、解説の方法)

要するに一番左に挿入する(の数と一番右に挿入する)の数が分かればいいので、それを求める。

0≦i≦nとし、d[i]を｛i文字目までに出てきた(の数｝-｛i文字目までに出てきた)の数｝とする（ただしd[0]=0）。そしてx=min(d[0],d[1],...,d[n])とおく。

このとき、d[n]=0かつx=0にすれば条件を満たしたことになる。ここでd[n]は右側に加える)の数、xは左側に加える(の数に注目したものであることに注意する。

一番左に(を挿入する処理は、d[n]とxを1増やす処理に、一番右に)を挿入する処理はd[n]を1減らす処理に相当する。この2つの処理を行ってxとd[n]を0にすることを目標にする。まず、最小値を取り、初期値は0であることから明らかにx≦0である。したがってx=0になるまでd[n]とxを1増やす処理を行う。次に、もしd[n]が増えすぎているならば、これを減らす必要がある。したがってd[n]を1減らす処理をd[n]が0になるまで、すなわちd[n]+|x|=(d[n]-x)回行う。これでx=0かつd[n]=0を実現できる。

上記の処理を(と)に置き換えて完成。
