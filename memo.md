# online-judge-tools, atcoder-cli

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

2. 問題のディレクトリまで移動してそこの`m.cpp`でコードを記入．

3. 完成したら`m.cpp`をコンパイルする．その後に`oj t`コマンドでサンプルケースを試す．
  ```
  g++ m.cpp \\ 忘れるとテストケースがWA表示になるので注意．
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

# ac-library-python
pythonのaclなので最適化が完全にできてないので，TLEになる可能性もあるので注意が必要．  
使用方法がわからなくなったときは以下のリポジトリから**example**の例を見ること．
https://github.com/not522/ac-library-python
- `import #{クラス名} from atcoder.#{ファイル名}`でインポートする．
- ローカル環境内では通常と同じく`python hoge.py`で実行できるが，提出の際は`python -m #{元のファイル} -o #{結合後のファイル名}`でac-library-pythonと元ファイルを結合する．そのファイルを提出すること．
- pypyには使用不可能．

# codeforces tool
## 初期設定
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
  Please choose one (index): // ここに数字を入れてセレクト．
  ```

1. `0`をセレクトしてユーザ名（メールアドレス）とパスワードを入力して設定する．
  ```
  Configure handle/email and password
  Note: The password is invisible, just type it correctly.
  handle/email: // ユーザ名（メールアドレス）
  password: // パスワード
  ```

2. `1`をセレクトしてデフォルト設定をする．

- 提出する言語を決める．
  ```
  Select a language (e.g. "42"): 

  54
  ```

- テンプレートのファイルを指定する．
  ```
  Template absolute path(e.g. "~/template/io.cpp"): 

  /root/work/kyopuro/cf/template.cpp
  ```

- これはパス．
  ```
  Other suffix? (e.g. "cxx cc"), empty is ok: 
  ```

- 拡張子の設定． 
  ```
  Template's alias (e.g. "cpp" "py"):

  cpp
  ```

- コンパイラコマンドを入力．（Pythonなどは不要．） 
  ```
  Before script (e.g. "g++ $%full%$ -o $%file%$.exe -std=c++11"), empty is ok:

  g++ $%full%$
  ```

- 実行ファイルを入力． 
  ```
  Script (e.g. "./$%file%$.exe" "python3 $%full%$"): 

  ./a.out
  ```

- 実行ファイルの削除などのコマンドを入力．（Pythonなどは不要．） 
  ```
  After script (e.g. "rm $%file%$.exe" or "cmd.exe /C del $%file%$.exe" in windows), empty is ok: 

  rm a.out
  ```

  3. `4`をセレクトして`cf race` や`cf parse`の後に`cf gen`を自動的に実行させる．`cf gen`はテンプレートファイルを作るコマンドであり，これを設定しないと`cf race`だけではテンプレートファイルは作られない．
    ```
  Run "cf gen" after "cf parse" (y/n)? 

  yes
  ```

3. サンプルケースが入っているディレクトリの作成．`cf race` + URLの数字．<u>問題番号ではないので注意．</u> `cf parse`だと，問題サイトは同時に表示されない．
  ```
  cf race URLID
  cf parse URLID
  ```

4. 問題のディレクトリまで移動して，問題番号`.cpp`にコードを記入．

5. `cf test`でカレントディレクトリ内の問題ケースをテストする．
  ```
  cf test
  ```

6. 上記のテストケースが全てPassedならば`cf submit`コマンドで提出．ターミナル上で結果を確認できてAcceptedなら正解．
  ```
  cf submit
  ```

## その他
- `cf list`で問題の正解情報などがわかる．
