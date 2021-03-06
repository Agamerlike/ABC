# ABC042
Atcoder Beginner Contest042の自分の解答

時間はかかっているが考察ミスはしていないので実質スムーズな全完を果たしたと言えるだろう。やはり必要なのは膨大な計算用紙。

# A
ソートしないとかえってめんどくさそうな問題。ノーコンパイルチャレンジ成功。

# B
辞書順比較は上からアルファベットが若い順に並べていけばいいので、ソートしてソートされたとおりに結合するだけ。

# C
最初全探索でやろうとして、途中で面倒になって別の方針（上位の桁から決めていく）に切り替え、頓挫したのでまた全探索に戻るという、非常にややこしい迷走をしたので無駄に時間を食った。

制約上100000を超えることはなさそうだということが分かるので、全探索でも十分間に合う(O(NlogN))。全探索の場合はnからスタートし、それぞれに数について使われている数字をすべて照合する。このときバケットっぽくするとスムーズに実装できるが、何を血迷ったか自分はいちいち全部調べていた。

解の存在は保証されるので、最初に見つかったものを出力するだけで良い。

# D
考察は秒で終わるがさすがに細かい部分はメモ書かなきゃ無理。そしてこの問題を文章だけで解説するのは相当無理がある。

左上から右下まで移動する方法が何通りあるかを調べる問題。基本的には平面上の点の移動と変わらない。したがって何も制約（通れないところなど）がない格子状の空間であった場合はCombinationを使うことでO(logN)ですぐに求められる。しかし今回は左下の一部領域を通ることができない。

なんとかしてO(log(W+H))で求められる形に帰着させたいので長方形の区画に分割することを考える。幸いなことに変な切り取られ方はしていないので、2つの長方形に分けることができそうだ。

1番左上のマス目を左上の頂点とする幅bマス、高さh-aマスの長方形とその右にある1番右下のマス目を右下の頂点とする幅w-bマス、高さhマスの長方形に分割する。前者の長方形で1番右のマスにたどり着ければ、そこから後者の長方形につなげることができる。このつなげ方は1通りしか存在しないので、前者の長方形でそれぞれの1番右のマスにたどり着く組み合わせとその1つ右のマス目から右下へ向かう組み合わせをかけ算してすべて足したものが答えとなる。この場合はO(Hlog(W+H))となり、間に合うことが分かる。