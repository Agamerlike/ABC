# ABC073
Atcoder Beginner Contest073の自分の解答

# A
無駄に一般化しようとしてクソみたいなミスをして1WA。ノーコンパイルチャレンジ失敗。

# B
区間を求めるのは、r-l+1でできる。Aより簡単だと思う。

# C
数が非常に大きくなることがあるため、DP的手法は使えない。だが、要は同じ数が何回出てくるか数えればいいだけなので、ソートしてそれぞれ数えれば良い。

# D
まずどの点の移動にも対応できるように全点間最短経路を取る。その後訪れる順番の選び方が問題となってくる。

最初、ゴールをあらかじめ設定しておき、ゴールから訪れる街の中で最も距離が短いものを順番に求めていく、という方針で実装を行ったがこれはWAだった。その後、計算間違いにより全探索しても間に合うことが判明(8^8<10^8より)し、全探索を実装しようとしたが順列の全探索の方法が分からず詰まった。しかしそこはさすがC++、何とSTLに順列の全探索を行えるものがあった(next_permutation関数)。これを実装したことにより、無事ACした。