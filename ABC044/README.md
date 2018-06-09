# ABC044
Atcoder Beginner Contest044の自分の解答

Cが分からない。

# A
CEが怖かったのでコンパイルした。定数とlong long型変数の比較では定数の方の型を合わせる(LL)。

# B
文字列内の文字登場数を数え上げてすべて偶数かどうか確認するだけ。

# C
全探索で部分点解法は取れる。問題はその後。どうにもアプローチが思い浮かばない。

### 追記（解説見た）
普通にやるとO(2^N)より配るDP。DP力弱すぎる。

個数による条件を無視したいのでx_iからaを引いたものをいくつか選んで総和を0にする方法を考える。したがって、i番目までで選んだものの数字の和がjになるようなDPテーブルdp[i][j]を考える。ところで、x_iがa未満の場合、つまりDPテーブルの添字が負になる場合を考慮しておくことに注意する。

テーブルを考えたところで遷移条件を考える。DPテーブルは0で初期化を行う。

まず、何も選んでいない状態としてdp[0][0]=1である。ここから目標であるdp[n][0]を求めるため遷移させていく。例えばx_iを加えると仮定すると、遷移は以下のようになる。

> dp[i][j]=dp[i-1][j]
> dp[i][j+(x_i-a)]+=dp[i-1][j]

上の式はx_iを選ばなかった場合の遷移であり、下の式は選んだ場合の遷移である。複数のパターンで同じテーブルを更新する可能性を考慮して下の式では+=としているが必要ないかもしれない。

このようにして求まったdp[n][0]が答えである。ただし、何も選ばない場合は答えとして不適なので除く。

# D
かなり効率良くやらないと間に合わないと思うが、いったいどうやってやるのだろうか。少なくともDPではなさそうだ。

### 追記（解説見た）
力技で押す。今回のABCはCとDの出題傾向がいつもと逆のように感じる。

まず1ケタで終わる場合について考える。これはn=bとなるbしかなく、したがって自明的にf(b,n)=1である（nのn進表記）。次に2ケタになる場合について考える。2ケタで終わる場合は、純粋にf(b,n)=n/b+n%bである。3ケタで終わる場合からforループを回す必要が生じる。純粋にループを回すとO(logN)となり、これが最大n個分行うのでO(NlogN)。やや厳しいと思われる。

~~ しかし、1ケタと2ケタで終わる場合については、O(1)で求められることが分かる。3ケタ以上になるのはb<sqrt(n)を満たすような場合である。したがってO(logN)かかる部分はたかだかsqrt(n)個しかなく、全体の計算量は平均的にO(N)に近づくであろうことが予想される（b<sqrt(n)を満たすようなbはn全体からすると非常に少ないため）。よって間に合う？ ~~

O(N)でも間に合わないのでさらなる高速化が必要である。2ケタの場合について考える。2ケタの場合、上の桁をp、下の桁をqとすると、n=pb+qというように表せる。ここで、pはsqrt(n)より小さいことが分かる。なぜならば、bがsqrt(n)より大きいため、pがsqrt(n)より大きいとn=pb+qを満たすp,b,qが存在しなくなるためである。またpを固定した場合q=s-pとなり、pb+qがnかどうかもO(1)で判定できる。したがってpの値で全探索を行うと良い。

これもsqrt(n)分存在するため、全体の計算量はO(sqrt(n)logN)となり、ギリギリ間に合う。実装部分が大変面倒なことになっているのでエレガントな解答がないか探ってみたい。