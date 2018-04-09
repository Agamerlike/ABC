# ABC069
Atcoder Beginner Contest069の自分の解答

# C
問題の条件から奇数は4の倍数に挟まれた状態でないと置けないので、奇数の数は大きな制約を受けそうだということが考えられた。

ここで話を単純化し、数列のそれぞれの数に4の倍数なら2、2の倍数なら1、奇数なら0のスコアをつける。この場合、隣り合った数字のスコアの和が2以上ならばその数字の積は4の倍数である。登場するパターンとスコアを最小化する数列をいくつか作ってみて確かめてみたところ、数列の合計スコアによって条件を満たせるかどうかが判別できそうなことが分かってきた（ただし未証明、条件はn-n%2以上かどうか）。で、自信はなかったがそれで出したら通った。

# D
順番にマス目を数字で塗りつぶしていく。ただし、塗りつぶし方は一筆書き、すなわち1行目の1列目～w列目まで塗りつぶしたら、今度は折り返して2行目のw列目から1列目に向かって塗りつぶす、といった方法で問題の条件は満たせるはずだ（この方法ならば行が変わる地点でも連続であることが保証されるため）。また、色iのマスが存在しない(a[i]=0)こともある（※ありませんでした）ので、そのパターンは飛ばすようにループ中で配慮する必要がある。ちょうどHWマスになるため、条件を満たさなかった場合については考える必要がない。

上記の方法でアルゴリズムを実装したが、通らなかった。根本的にどこか間違っているのだろうか。。。

### 追記（解説見た）
同じじゃねーか、何故通らん。

### 追記

テストケースを見た結果、マスの色をstring型で管理していたことが原因であることがわかった（10色以上で成立しない）。サンプル中には1ケタの数字しかない、特に数字であるという制約はない、出力に使われているcは通常char型の変数として扱われる、といったことが重なった末の誤読だった。