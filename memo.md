# online-judge-tools, atcoder-cliの注意

## サンプルケースDLから提出の流れ
0. 2つのツールを使うためにどちら共にログインしておく．`acc session`でログイン状況を確認している．
  ```
  acc login
  oj login https://beta.atcoder.jp/
  ```

1. サンプルケースフォルダ(`test`)が入っているディレクトリの作成．
  ```
  acc new contestID
  ```

2. 問題のディレクトリまで移動してそこの`main.cpp`でコードを記入．

3. 完成したら`main.cpp`をコンパイルする．その後に`oj t`コマンドでサンプルケースを試す．
  ```
  g++ main.cpp \\ 忘れるとテストケースがWA表示になるので注意．
  oj t
  ```

4. 上記のテストケースが全てACならば`acc s`コマンドで提出．
  ```
  acc s
  ```

5. 下記のような提出の確認が出てくるので確認の`abc` + 問題番号．
  ```
  the problem "https://atcoder.jp/contests/abc227/tasks/abc227_a" is specified to submit, but no samples were downloaded in this directory. this may be mis-operation
  Are you sure? Please type "abca" // 確認コードの最後の文字が問題番号．今回は"a"
  ```

## テストケースの注意．
- 浮動小数点で提出の際は引数`-e`と相対誤差を決める．
  ```
  oj t -e 相対誤差
  ```

- 解答が複数の際は引数`-N`（空白と改行を無視）を決める．
  ```
  oj t -N
  ```

## その他
- online-judge-toolsのランダム生成器実装はまた今度．

# codeforces toolの設定
0. `cf config`で初期設定をする．
  ```
  Configure the tool
  0) login
  1) add a template
  2) delete a template
  3) set default template
  4) run "cf gen" after "cf parse"
  5) set host domain
  6) set proxy
  7) set folders' name
  Please choose one (index): \\ ここに数字を入れてセレクト．
  ```

  1. `0`をセレクトしてユーザー名（メールアドレス）とパスワードを入力して設定する．
    ```
    Configure handle/email and password
    Note: The password is invisible, just type it correctly.
    handle/email: 
    password: 
    ```