# ABC048
Atcoder Beginner Contest048の自分の解答

Dが解けず3完。500点問題はどうにかして安定させたいところ。

# A
入力形式を読み違え1WA。ノーコンパイルチャレンジ失敗。

# B
累積和的なエッセンスを使うのでBにしたらかなり難しいと思う。

a以下のxの倍数（0以上）の個数はいかなる場合にもfloor(a/x)+1によって得られる。

これでO(1)で計算できるが、aが0である場合は特殊なケース（つまりxによらず0）となるので気をつける。

# C
アルゴリズムが雑だったが通った。

例えば3つ箱があったとき、すべての組み合わせに影響を与えられるのは真ん中の箱だけなので基本的に端以外で取り除ける部分は取り除いていき、どうしても条件を満たせない部分だけ端を使うべきだろうという方針が立つ。

2番目の箱から見ていき、i番目の箱とi-1番目の箱のキャンディの和がx以下になるようにi番目の箱のキャンディを減らす。ところがi番目の箱だけではx以下にできないことがあるのでその場合はi番目の箱の中身を0にし、足りない分だけi-1番目の箱から減らす。

O(N)で計算でき間に合うが、例外処理の部分のコードがやや難しい。

# D
分からなかった。

DPするにも遷移条件がいまいち分からず、おそらく最大手数を保持するタイプのDPだと思うのだが……

### 追記（解説読んだ）

最終的な状態と最初の状態の差から何ターン使ったかを導き出せるのでそれで解が出せるという方式。言われてみればそうだなぁという感触だが、これを思いつける気がしない。

最初の文字と末尾の文字が同じならば最終的には奇数文字数になり、異なるならば偶数文字数になる。ここから最初の文字列長が偶数か奇数かでターン数の偶奇が分かる。偶数なら"Second"、奇数なら"First"の勝ちである。