# ABC053
Atcoder Beginner Contest053の自分の解答

ABDの3完

# B
前から'A'、後ろから'Z'を探す。

# C
5,6,5,6,...と出していくのが最も効率の良い点のとり方なので、それを何セット繰り返すか(x/11)を求め、端数は5を取ってそのまま終わることができるのか6まで取る必要があるのかを求める。

謎バグにハマり分からず。これで正しいと思うのだが。

### 追記（解説見た）
初期条件設定のミスが原因の誤読。ｸｿｸｿｸｿｸｿｸｿｸｿｸｿ

# D
被ったカードを取り除く方法を考える。被ったカードが3枚以上ある時、3枚同じカードを抜き出すことで2枚減らすことができる。被ったカードが2枚の時、被ったカードが2枚ある2組から3枚取り出すことでそれぞれ1枚ずつに減らすことができる。もしくは1枚しかないカードと2枚あるカードで3枚の組を作ることで1枚のカードは消滅するが、2枚のカードは1枚残すことができる。

この3つの操作以外にはする必要がない。順番に3枚以上あるカードを2枚以下に減らし、2枚あるカードでペアを作って1枚にしていき、もし2枚のカードが余ったら1枚のカードとペアにする。これで最適解となる。