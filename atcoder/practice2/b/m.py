# from <ディレクトリ名>.<ファイル名> import <クラス名>
# 提出する際は python -m <提出ファイル> -o <結合後のファイル名> でコードを結合して，そのファイルを提出する．
from atcoder.fenwicktree import FenwickTree

n, q = map(int, input().split())
a = list(map(int, input().split()))
f = FenwickTree(n)

for i in range(n):
    f.add(i, a[i])


for _ in range(q):
    q1, q2, q3 = map(int, input().split())
    if q1 == 0:
        f.add(q2, q3)
    else:
        print(f.sum(q2, q3))
